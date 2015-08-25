#include "dxl_hal.h"
#include "dynamixel.h"
#include <string.h>
#include <stdlib.h>

#include <stdio.h>

unsigned short update_crc(unsigned short crc_accum, unsigned char *data_blk_ptr, unsigned short data_blk_size)
{
	unsigned short i, j;
	unsigned short crc_table[256] = {0x0000,
	                                0x8005, 0x800F, 0x000A, 0x801B, 0x001E, 0x0014, 0x8011,
	                                0x8033, 0x0036, 0x003C, 0x8039, 0x0028, 0x802D, 0x8027,
	                                0x0022, 0x8063, 0x0066, 0x006C, 0x8069, 0x0078, 0x807D,
	                                0x8077, 0x0072, 0x0050, 0x8055, 0x805F, 0x005A, 0x804B,
	                                0x004E, 0x0044, 0x8041, 0x80C3, 0x00C6, 0x00CC, 0x80C9,
	                                0x00D8, 0x80DD, 0x80D7, 0x00D2, 0x00F0, 0x80F5, 0x80FF,
	                                0x00FA, 0x80EB, 0x00EE, 0x00E4, 0x80E1, 0x00A0, 0x80A5,
	                                0x80AF, 0x00AA, 0x80BB, 0x00BE, 0x00B4, 0x80B1, 0x8093,
	                                0x0096, 0x009C, 0x8099, 0x0088, 0x808D, 0x8087, 0x0082,
	                                0x8183, 0x0186, 0x018C, 0x8189, 0x0198, 0x819D, 0x8197,
	                                0x0192, 0x01B0, 0x81B5, 0x81BF, 0x01BA, 0x81AB, 0x01AE,
	                                0x01A4, 0x81A1, 0x01E0, 0x81E5, 0x81EF, 0x01EA, 0x81FB,
	                                0x01FE, 0x01F4, 0x81F1, 0x81D3, 0x01D6, 0x01DC, 0x81D9,
	                                0x01C8, 0x81CD, 0x81C7, 0x01C2, 0x0140, 0x8145, 0x814F,
	                                0x014A, 0x815B, 0x015E, 0x0154, 0x8151, 0x8173, 0x0176,
	                                0x017C, 0x8179, 0x0168, 0x816D, 0x8167, 0x0162, 0x8123,
	                                0x0126, 0x012C, 0x8129, 0x0138, 0x813D, 0x8137, 0x0132,
	                                0x0110, 0x8115, 0x811F, 0x011A, 0x810B, 0x010E, 0x0104,
	                                0x8101, 0x8303, 0x0306, 0x030C, 0x8309, 0x0318, 0x831D,
	                                0x8317, 0x0312, 0x0330, 0x8335, 0x833F, 0x033A, 0x832B,
	                                0x032E, 0x0324, 0x8321, 0x0360, 0x8365, 0x836F, 0x036A,
	                                0x837B, 0x037E, 0x0374, 0x8371, 0x8353, 0x0356, 0x035C,
	                                0x8359, 0x0348, 0x834D, 0x8347, 0x0342, 0x03C0, 0x83C5,
	                                0x83CF, 0x03CA, 0x83DB, 0x03DE, 0x03D4, 0x83D1, 0x83F3,
	                                0x03F6, 0x03FC, 0x83F9, 0x03E8, 0x83ED, 0x83E7, 0x03E2,
	                                0x83A3, 0x03A6, 0x03AC, 0x83A9, 0x03B8, 0x83BD, 0x83B7,
	                                0x03B2, 0x0390, 0x8395, 0x839F, 0x039A, 0x838B, 0x038E,
	                                0x0384, 0x8381, 0x0280, 0x8285, 0x828F, 0x028A, 0x829B,
	                                0x029E, 0x0294, 0x8291, 0x82B3, 0x02B6, 0x02BC, 0x82B9,
	                                0x02A8, 0x82AD, 0x82A7, 0x02A2, 0x82E3, 0x02E6, 0x02EC,
	                                0x82E9, 0x02F8, 0x82FD, 0x82F7, 0x02F2, 0x02D0, 0x82D5,
	                                0x82DF, 0x02DA, 0x82CB, 0x02CE, 0x02C4, 0x82C1, 0x8243,
	                                0x0246, 0x024C, 0x8249, 0x0258, 0x825D, 0x8257, 0x0252,
	                                0x0270, 0x8275, 0x827F, 0x027A, 0x826B, 0x026E, 0x0264,
	                                0x8261, 0x0220, 0x8225, 0x822F, 0x022A, 0x823B, 0x023E,
	                                0x0234, 0x8231, 0x8213, 0x0216, 0x021C, 0x8219, 0x0208,
	                                0x820D, 0x8207, 0x0202 };

	for(j = 0; j < data_blk_size; j++)
	{
		i = ((unsigned short)(crc_accum >> 8) ^ *data_blk_ptr++) & 0xFF;
		crc_accum = (crc_accum << 8) ^ crc_table[i];
	}

	return crc_accum;
}

void dxl_add_stuffing(unsigned char * packet)
{
    int i = 0, index = 0;
    int packet_length_in = DXL_MAKEWORD(packet[PKT_LENGTH_L], packet[PKT_LENGTH_H]);
    int packet_length_out = packet_length_in;
    unsigned char temp[MAXNUM_TXPACKET] = {0};

    memcpy(temp, packet, PKT_LENGTH_H + 1);    // FF FF FD XX ID LEN_L LEN_H
    index = PKT_INSTRUCTION;
    for( i = 0; i < packet_length_in - 2; i++) // except CRC
    {
        temp[index++] = packet[i+PKT_INSTRUCTION];
        if(packet[i+PKT_INSTRUCTION] == 0xFD && packet[i+PKT_INSTRUCTION-1] == 0xFF && packet[i+PKT_INSTRUCTION-2] == 0xFF)
        {   // FF FF FD
            temp[index++] = 0xFD;
            packet_length_out++;
        }
    }
    temp[index++] = packet[PKT_INSTRUCTION+packet_length_in-2];
    temp[index++] = packet[PKT_INSTRUCTION+packet_length_in-1];

    if(packet_length_in != packet_length_out)
        packet = (unsigned char*)realloc(packet, index * sizeof(unsigned char));

    memcpy(packet, temp, index);
    packet[PKT_LENGTH_L] = DXL_LOBYTE(packet_length_out);
    packet[PKT_LENGTH_H] = DXL_HIBYTE(packet_length_out);
}

void dxl_remove_stuffing(unsigned char * packet)
{
    int i = 0, index = 0;
    int packet_length_in = DXL_MAKEWORD(packet[PKT_LENGTH_L], packet[PKT_LENGTH_H]);
    int packet_length_out = packet_length_in;
    unsigned char temp[MAXNUM_TXPACKET] = {0};

    index = PKT_INSTRUCTION;
    for( i = 0; i < packet_length_in - 2; i++)  // except CRC
    {
        if(packet[i+PKT_INSTRUCTION] == 0xFD && packet[i+PKT_INSTRUCTION+1] == 0xFD && packet[i+PKT_INSTRUCTION-1] == 0xFF && packet[i+PKT_INSTRUCTION-2] == 0xFF)
        {   // FF FF FD FD
            packet_length_out--;
            i++;
        }
        packet[index++] = packet[i+PKT_INSTRUCTION];
    }
    packet[index++] = packet[PKT_INSTRUCTION+packet_length_in-2];
    packet[index++] = packet[PKT_INSTRUCTION+packet_length_in-1];

    packet[PKT_LENGTH_L] = DXL_LOBYTE(packet_length_out);
    packet[PKT_LENGTH_H] = DXL_HIBYTE(packet_length_out);
}

double dxl_get_packet_time( PSerialPort comm )
{
    double interval_time;

    interval_time = (double)(dxl_hal_get_curr_time() - comm->dPacketStartTime);

    // Overflow
    if(interval_time < 0)
        comm->dPacketStartTime = dxl_hal_get_curr_time();
	
	return interval_time;
}

void dxl_set_packet_timeout( PSerialPort comm, int numPacket )
{
    comm->dPacketStartTime = dxl_hal_get_curr_time();
    comm->fPacketWaitTime = (float)(comm->fByteTransferTime*(float)numPacket + 2*LATENCY_TIME + 2.0f);
}

void dxl_set_packet_timeout_ms( PSerialPort comm, int msec)
{
    comm->dPacketStartTime = dxl_hal_get_curr_time();
    comm->fPacketWaitTime = (float)msec;
}

int dxl_is_packet_timeout( PSerialPort comm )
{
    if(dxl_get_packet_time(comm) > comm->fPacketWaitTime)
        return 1;
    return 0;
}

float dxl_get_baudrate(int baudnum)
{
    if(baudnum >= 2400)
        return (float)baudnum;

    switch(baudnum)
    {
    case 0:
        return 2400.0f;
    case 1:
        return 57600.0f;
    case 2:
        return 115200.0f;
    case 3:
        return 1000000.0f;
    case 4:
        return 2000000.0f;
    case 5:
        return 3000000.0f;
    case 6:
        return 4000000.0f;
    case 7:
        return 4500000.0f;
    case 8:
        return 10500000.0f;
    default:
        return 57600.0f;
    }    
}

int dxl_initialize( PSerialPort comm, int devIndex, int baudnum )
{
    float baudrate = dxl_get_baudrate(baudnum);

    if( dxl_hal_open(&(comm->hComm), devIndex, baudrate) == 0 )
        return 0;

    comm->fByteTransferTime = 1000.0f / baudrate * 10.0f; // 1000/baudrate(bit per msec) * 10(start bit + data bit + stop bit)
    comm->iBusUsing = 0;
    return 1;
}

void dxl_terminate( PSerialPort comm )
{
    dxl_hal_close(&(comm->hComm));
}

int dxl_change_baudrate( PSerialPort comm, int baudnum )
{
    int result = 0;
    float baudrate = dxl_get_baudrate(baudnum);
    
    result = dxl_hal_change_baudrate(comm->hComm, baudrate);
    if(result == 1)
        comm->fByteTransferTime = 1000.0f / baudrate * 10.0f; // 1000/baudrate(bit per msec) * 10(start bit + data bit + stop bit)

    return result;
}

int dxl_tx_packet( PSerialPort comm, unsigned char *txpacket )
{
    int packet_tx_len, real_tx_len;
    int length;
    unsigned short crc = 0;

    // Check Bus Using
    if(comm->iBusUsing == 1)
        return COMM_TXFAIL;
    comm->iBusUsing = 1;

    // Character stuffing
    dxl_add_stuffing(txpacket);
    length = DXL_MAKEWORD(txpacket[PKT_LENGTH_L], txpacket[PKT_LENGTH_H]);

    // Check MAX packet length
    if(length > (MAXNUM_TXPACKET))
    {
        comm->iBusUsing = 0;
        return COMM_TXERROR;
    }

    // Packet Header
    txpacket[PKT_HEADER0]   = 0xFF;
    txpacket[PKT_HEADER1]   = 0xFF;
    txpacket[PKT_HEADER2]   = 0xFD;
    txpacket[PKT_RESERVED]  = 0x00; // RESERVED

    // Add CRC16
    crc = update_crc(0, txpacket, length+PKT_LENGTH_H+1-2);  // -2 : except CRC16
    txpacket[length+PKT_LENGTH_H-1] = DXL_LOBYTE(crc);     // last - 1
    txpacket[length+PKT_LENGTH_H-0] = DXL_HIBYTE(crc);     // last - 0

    // Tx Packet
    dxl_hal_clear(comm->hComm);
    packet_tx_len = length + PKT_LENGTH_H + 1;
    real_tx_len = dxl_hal_write( comm->hComm, txpacket, packet_tx_len );
    if( packet_tx_len != real_tx_len )
    {
        comm->iBusUsing = 0;
        return COMM_TXFAIL;
    }

    return COMM_TXSUCCESS;
}

int dxl_rx_packet( PSerialPort comm, unsigned char *rxpacket )
{
    int rx_length = 0, wait_length = PKT_LENGTH_H + 4 + 1;    // 4 : INST ERROR CHKSUM_L CHKSUM_H
    int i, result = COMM_RXFAIL;
    unsigned short crc = 0;

    // Check Bus Using
    //if(bus_using == 0)
    //    return 0;

    while(1)
    {
        rx_length += dxl_hal_read(comm->hComm, &rxpacket[rx_length], wait_length - rx_length);
        if(rx_length >= wait_length)    // wait_length minimum : 11
        {
            // Find packet header
            for(i = 0; i < (rx_length - 2); i++)
            {
                if(rxpacket[i] == 0xFF && rxpacket[i+1] == 0xFF && rxpacket[i+2] == 0xFD)
                    break;
            }

            if(i == 0)
            {
                // Check length
                wait_length = DXL_MAKEWORD(rxpacket[PKT_LENGTH_L], rxpacket[PKT_LENGTH_H]) + PKT_LENGTH_H + 1;
                if(rx_length < wait_length)
                {
                    // Check timeout
                    if(dxl_is_packet_timeout(comm) == 1)
                    {
                        if(rx_length == 0)
                            result = COMM_RXTIMEOUT;
                        else
                            result = COMM_RXCORRUPT;
                        comm->iBusUsing = 0;
                        break;
                    }
                    continue;
                }

                // Check CRC16
                crc = DXL_MAKEWORD(rxpacket[wait_length-2], rxpacket[wait_length-1]);
                if(update_crc(0, rxpacket, wait_length-2) == crc) // -2 : except CRC16
                    result = COMM_RXSUCCESS;
                else
                    result = COMM_RXCORRUPT;
                comm->iBusUsing = 0;
                break;
            }
            else
            {
                // Remove unnecessary packets
                memcpy(&rxpacket[0], &rxpacket[i], rx_length - i);
                rx_length -= i;
            }
        }
        else
        {
            // Check timeout
            if(dxl_is_packet_timeout(comm) == 1)
            {
                if(rx_length == 0)
                    result = COMM_RXTIMEOUT;
                else
                    result = COMM_RXCORRUPT;
                comm->iBusUsing = 0;
                break;
            }
        }
    }

    // Character stuffing
    if(result == COMM_RXSUCCESS)
        dxl_remove_stuffing(rxpacket);

    comm->iBusUsing = 0;
    return result;
}

int dxl_txrx_packet( PSerialPort comm, unsigned char *txpacket, unsigned char* rxpacket, int *error )
{
    int result = COMM_TXFAIL;

    // Wait for Bus Idle
    while(comm->iBusUsing == 1) 
    {
        //Sleep(0);
    }

    result = dxl_tx_packet(comm, txpacket);

    // Check Tx packet result
    if( result != COMM_TXSUCCESS )
        return result;

    // Set Rx Timeout
    if(txpacket[PKT_INSTRUCTION] == INST_READ)
        dxl_set_packet_timeout(comm, DXL_MAKEWORD(txpacket[PKT_PARAMETER+2], txpacket[PKT_PARAMETER+3]) + 11);
    else
        dxl_set_packet_timeout(comm, PKT_LENGTH_H+4+1);    // 4 : INST ERROR CHKSUM_L CHKSUM_H

    // BroadCast ID && !BulkRead = There is no need to wait for a rxpacket
    if(txpacket[PKT_ID] == BROADCAST_ID && txpacket[PKT_INSTRUCTION] != INST_BULK_READ)
    {
        comm->iBusUsing = 0;
        return COMM_RXSUCCESS;
    }

    result = dxl_rx_packet(comm, rxpacket);
    if((result == COMM_RXSUCCESS) && (txpacket[PKT_ID] != BROADCAST_ID) && (txpacket[PKT_ID] != rxpacket[PKT_ID]))
        result = dxl_rx_packet(comm, rxpacket);

    if(result == COMM_RXSUCCESS && txpacket[PKT_ID] != BROADCAST_ID)
    {
        if(error != 0)
            *error = (int)rxpacket[PKT_PARAMETER];
    }

    return result;
}

int dxl_ping( PSerialPort comm, int id, PPingData data, int *error )
{
    int result = COMM_TXFAIL;
    unsigned char txpacket[10]  = {0};
    unsigned char rxpacket[14]  = {0};

    txpacket[PKT_ID]            = (unsigned char)id;
    txpacket[PKT_LENGTH_L]      = 0x03;
    txpacket[PKT_LENGTH_H]      = 0x00;
    txpacket[PKT_INSTRUCTION]   = INST_PING;

    result = dxl_txrx_packet(comm, txpacket, rxpacket, error);
    if(result == COMM_RXSUCCESS && id != BROADCAST_ID)
    {
        if(data != 0)
        {
            data->iID = rxpacket[PKT_ID];
            data->iModelNo = DXL_MAKEWORD(rxpacket[PKT_PARAMETER+1], rxpacket[PKT_PARAMETER+2]);
            data->iFirmVer = rxpacket[PKT_PARAMETER+3];
        }
    }
    return result;
}

int dxl_broadcast_ping( PSerialPort comm, PPingData arr_data, int *count)
{
    int result = COMM_TXFAIL;
    int rx_length = 0, wait_length = 0;
    unsigned char txpacket[10]  = {0};
    unsigned char rxpacket[PING_STATUS_LENGTH * MAX_ID] = {0};

    //if(arr_data != NULL)
    //{
    //    free(arr_data);
    //    arr_data = NULL;
    //}
    //arr_data = (PPingData)calloc(MAX_ID, sizeof(PingData));
    *count = 0;

    txpacket[PKT_ID]            = (unsigned char)BROADCAST_ID;
    txpacket[PKT_LENGTH_L]      = 0x03;
    txpacket[PKT_LENGTH_H]      = 0x00;
    txpacket[PKT_INSTRUCTION]   = INST_PING;

    result = dxl_tx_packet(comm, txpacket);
    if(result != COMM_TXSUCCESS)
    {
        comm->iBusUsing = 0;
        return result;
    }

    wait_length = PING_STATUS_LENGTH * MAX_ID;
    dxl_set_packet_timeout_ms(comm, (int)((comm->fByteTransferTime * wait_length) + (3 * MAX_ID) + 2 * LATENCY_TIME));

    while(1)
    {
        int _cnt = dxl_hal_read(comm->hComm, &rxpacket[rx_length], wait_length - rx_length);
        if(_cnt > 0)
        {
            rx_length += _cnt;
            printf("cnt : %d, Interval : %f / Wait time : %f\n", _cnt,  dxl_get_packet_time(comm), comm->fPacketWaitTime);
        }
        if(dxl_is_packet_timeout(comm) == 1 || rx_length >= wait_length)
            break;
    }
    comm->iBusUsing = 0;

    while(1)
    {
        int idx = 0;

        if(rx_length < PING_STATUS_LENGTH)
            return COMM_RXCORRUPT;

        // find packet header
        while( idx < (rx_length - 2) )
        {
            if(rxpacket[idx] == 0xFF && rxpacket[idx + 1] == 0xFF && rxpacket[idx + 2] == 0xFD)
                break;
            else
                idx++;
        }

        if(idx == 0)
        {
            // check CRC16
            int crc = DXL_MAKEWORD(rxpacket[PING_STATUS_LENGTH - 2], rxpacket[PING_STATUS_LENGTH - 1]);
            if(update_crc(0, rxpacket, PING_STATUS_LENGTH - 2) == crc) // - 2 : except CRC16
            {
                memset(&arr_data[*count], 0, sizeof(PingData));
                arr_data[*count].iID = rxpacket[PKT_ID];
                arr_data[*count].iModelNo = DXL_MAKEWORD(rxpacket[PKT_PARAMETER+1], rxpacket[PKT_PARAMETER+2]);
                arr_data[*count].iFirmVer = rxpacket[PKT_PARAMETER+3];
                (*count)++;

                memcpy(&rxpacket[0], &rxpacket[PING_STATUS_LENGTH], rx_length - PING_STATUS_LENGTH);
                rx_length -= PING_STATUS_LENGTH;
            }
            else
            {
                result = COMM_RXCORRUPT;

                // remove header (0xFF 0xFF 0xFD)
                memcpy(&rxpacket[0], &rxpacket[3], rx_length - 3); 
                rx_length -= 3;
            }

            if(rx_length < PING_STATUS_LENGTH)
                break;
        }
        else
        {
            // remove unnecessary packets
            memcpy(&rxpacket[0], &rxpacket[idx], rx_length - idx);
            rx_length -= idx;
        }
    }

    return result;
}

int dxl_reboot( PSerialPort comm, int id, int *error)
{
    unsigned char txpacket[10]  = {0};
    unsigned char rxpacket[11]  = {0};

    txpacket[PKT_ID]            = (unsigned char)id;
    txpacket[PKT_LENGTH_L]      = 0x03;
    txpacket[PKT_LENGTH_H]      = 0x00;
    txpacket[PKT_INSTRUCTION]   = INST_REBOOT;

    return dxl_txrx_packet(comm, txpacket, rxpacket, error);
}

int dxl_factory_reset( PSerialPort comm, int id, int option, int *error )
{
    unsigned char txpacket[11]  = {0};
    unsigned char rxpacket[11]  = {0};

    txpacket[PKT_ID]            = (unsigned char)id;
    txpacket[PKT_LENGTH_L]      = 0x04;
    txpacket[PKT_LENGTH_H]      = 0x00;
    txpacket[PKT_INSTRUCTION]   = INST_FACTORY_RESET;
    txpacket[PKT_PARAMETER]     = (unsigned char)option;

    return dxl_txrx_packet(comm, txpacket, rxpacket, error);
}

int dxl_read( PSerialPort comm, int id, int address, int length, unsigned char *data, int *error)
{
    int result = COMM_TXFAIL;

	unsigned char txpacket[14]	= {0};
	unsigned char* rxpacket		= (unsigned char*)calloc(length+11, sizeof(unsigned char));

	txpacket[PKT_ID]			= (unsigned char)id;
	txpacket[PKT_LENGTH_L]		= 0x07;
	txpacket[PKT_LENGTH_H]		= 0x00;
	txpacket[PKT_INSTRUCTION]	= INST_READ;
	txpacket[PKT_PARAMETER+0]	= (unsigned char)DXL_LOBYTE(address);
	txpacket[PKT_PARAMETER+1]	= (unsigned char)DXL_HIBYTE(address);
	txpacket[PKT_PARAMETER+2]	= (unsigned char)DXL_LOBYTE(length);
	txpacket[PKT_PARAMETER+3]	= (unsigned char)DXL_HIBYTE(length);

	result = dxl_txrx_packet(comm, txpacket, rxpacket, error);
	if(result == COMM_RXSUCCESS && id != BROADCAST_ID)
		memcpy(data, &rxpacket[PKT_PARAMETER+1], length);

	free(rxpacket);
	return result;
}

int dxl_read_byte( PSerialPort comm, int id, int address, int *value, int *error )
{
	int result = COMM_TXFAIL;
	unsigned char data[1] = {0};

	result = dxl_read(comm, id, address, 1, data, error);
	if(result == COMM_RXSUCCESS)
		*value = data[0];
    else
        printf("READ BYTE RESULT : %d \n", result);

	return result;
}

int dxl_read_word( PSerialPort comm, int id, int address, int *value, int *error )
{
	int result = COMM_TXFAIL;
	unsigned char data[2] = {0};

	result = dxl_read(comm, id, address, 2, data, error);
	if(result == COMM_RXSUCCESS)
		*value = DXL_MAKEWORD(data[0], data[1]);

	return result;
}

int dxl_read_dword( PSerialPort comm, int id, int address, unsigned int *value, int *error )
{
	int result = COMM_TXFAIL;
	unsigned char data[4] = {0};

	result = dxl_read(comm, id, address, 4, data, error);
	if(result == COMM_RXSUCCESS)
		*value = DXL_MAKEDWORD(DXL_MAKEWORD(data[0], data[1]), DXL_MAKEWORD(data[2], data[3]));

	return result;
}

int dxl_write( PSerialPort comm, int id, int address, int length, unsigned char *data, int *error)
{
    int result = COMM_TXFAIL;
	unsigned char* txpacket 	= (unsigned char*)calloc(length+12, sizeof(unsigned char));
	unsigned char rxpacket[12] 	= {0};

	txpacket[PKT_ID]			= (unsigned char)id;
	txpacket[PKT_LENGTH_L]		= DXL_LOBYTE(length+5);
	txpacket[PKT_LENGTH_H]		= DXL_HIBYTE(length+5);
	txpacket[PKT_INSTRUCTION]	= INST_WRITE;
	txpacket[PKT_PARAMETER+0]	= (unsigned char)DXL_LOBYTE(address);
	txpacket[PKT_PARAMETER+1]	= (unsigned char)DXL_HIBYTE(address);

	memcpy(&txpacket[PKT_PARAMETER+2], data, length);

    result = dxl_txrx_packet(comm, txpacket, rxpacket, error);

    free(txpacket);
	return result;
}

int dxl_write_byte( PSerialPort comm, int id, int address, int value, int *error )
{
	unsigned char data[1] = {value};
	return dxl_write(comm, id, address, 1, data, error);
}

int dxl_write_word( PSerialPort comm, int id, int address, int value, int *error )
{
	unsigned char data[2] = {DXL_LOBYTE(value), DXL_HIBYTE(value)};
	return dxl_write(comm, id, address, 2, data, error);
}

int dxl_write_dword( PSerialPort comm, int id, int address, unsigned int value, int *error )
{
    unsigned char data[4] = { DXL_LOBYTE(DXL_LOWORD(value)), DXL_HIBYTE(DXL_LOWORD(value)),
	                          DXL_LOBYTE(DXL_HIWORD(value)), DXL_HIBYTE(DXL_HIWORD(value)) };
	return dxl_write(comm, id, address, 4, data, error);
}

int dxl_system_write( PSerialPort comm, int id, int address, int length, unsigned char *data, int *error)
{
    int result = COMM_TXFAIL;
	unsigned char* txpacket 	= (unsigned char*)calloc(length+12, sizeof(unsigned char));
	unsigned char rxpacket[12] 	= {0};

	txpacket[PKT_ID]			= (unsigned char)id;
	txpacket[PKT_LENGTH_L]		= DXL_LOBYTE(length+5);
	txpacket[PKT_LENGTH_H]		= DXL_HIBYTE(length+5);
    txpacket[PKT_INSTRUCTION]	= INST_SYSTEM_WRITE;
	txpacket[PKT_PARAMETER+0]	= (unsigned char)DXL_LOBYTE(address);
	txpacket[PKT_PARAMETER+1]	= (unsigned char)DXL_HIBYTE(address);

	memcpy(&txpacket[PKT_PARAMETER+2], data, length);

	result = dxl_txrx_packet(comm, txpacket, rxpacket, error);

    free(txpacket);
	return result;
}

int dxl_sync_write( PSerialPort comm, int start_addr, int data_length, unsigned char *param, int param_length)
{
    int result = COMM_TXFAIL;
    int pkt_length = param_length + 7;  // 7 : INST START_ADDR_L START_ADDR_H DATA_LEN_L DATA_LEN_H CHKSUM_L CHKSUM_H
	unsigned char* txpacket 	= (unsigned char*)calloc(pkt_length+7, sizeof(unsigned char));
	unsigned char rxpacket[12] 	= {0};

    txpacket[PKT_ID]            = (unsigned char)BROADCAST_ID;
    txpacket[PKT_LENGTH_L]      = (unsigned char)DXL_LOBYTE(pkt_length);
    txpacket[PKT_LENGTH_H]      = (unsigned char)DXL_HIBYTE(pkt_length);
    txpacket[PKT_INSTRUCTION]   = INST_SYNC_WRITE;
    txpacket[PKT_PARAMETER]     = (unsigned char)DXL_LOBYTE(start_addr);
    txpacket[PKT_PARAMETER+1]   = (unsigned char)DXL_HIBYTE(start_addr);
    txpacket[PKT_PARAMETER+2]   = (unsigned char)DXL_LOBYTE(data_length);
    txpacket[PKT_PARAMETER+3]   = (unsigned char)DXL_HIBYTE(data_length);
    memcpy(&txpacket[PKT_PARAMETER+4], param, param_length);

    result = dxl_txrx_packet(comm, txpacket, rxpacket, 0);

    free(txpacket);
	return result;
}

int dxl_bulk_read( PSerialPort comm, unsigned char *param, int param_length, PBulkData *rxdata)
{
    int result = COMM_TXFAIL, n, wait_length = 0;
    int num = param_length / 5; // each length : 5 (ID ADDR_L ADDR_H LEN_L LEN_H)
    int pkt_length = param_length + 3;  // 3 : INST CHKSUM_L CHKSUM_H
    unsigned char txpacket[MAXNUM_TXPACKET] = {0};
    unsigned char rxpacket[MAXNUM_RXPACKET] = {0};

    txpacket[PKT_ID]            = (unsigned char)BROADCAST_ID;
    txpacket[PKT_LENGTH_L]      = (unsigned char)DXL_LOBYTE(pkt_length);
    txpacket[PKT_LENGTH_H]      = (unsigned char)DXL_HIBYTE(pkt_length);
    txpacket[PKT_INSTRUCTION]   = INST_BULK_READ;
    memcpy(&txpacket[PKT_PARAMETER], param, param_length);

    for(n = 0; n < num; n++)
    {
        int id = param[n*5+0];
        rxdata[id]->iError = -1;
        rxdata[id]->iStartAddr = DXL_MAKEWORD(param[n*5+1], param[n*5+2]);
        rxdata[id]->iLength = DXL_MAKEWORD(param[n*5+3], param[n*5+4]);
        rxdata[id]->pucTable = (unsigned char *)calloc(rxdata[id]->iLength, sizeof(unsigned char));
        wait_length += rxdata[id]->iLength + 11;
    }

    /************ TxRxPacket *************/
    // Wait for Bus Idle
    while(comm->iBusUsing == 1) 
    {
        //Sleep(0);
    }

    result = dxl_tx_packet(comm, txpacket);

    // Check Tx packet result
    if( result != COMM_TXSUCCESS )
        return result;

    // Set Rx Timeout (BULK_READ)
    dxl_set_packet_timeout(comm, wait_length);

    for(n = 0; n < num; n++)
    {
        int id = param[n*5+0];
        // Rx packet
        result = dxl_rx_packet(comm, rxpacket);
        if(result == COMM_RXSUCCESS)
            rxdata[id]->iError = rxpacket[PKT_PARAMETER];
        // rxpacket to rxdata[id]->pucTable
        memcpy(rxdata[id]->pucTable, &rxpacket[PKT_PARAMETER+1], rxdata[id]->iLength);
    }


    return result;
}

int dxl_get_bulk_byte(PBulkData *data, int id, int addr, int *value)
{
    if(data[id] == 0 || data[id]->iError == -1)
        return 0;
    if(addr < data[id]->iStartAddr || data[id]->iStartAddr+data[id]->iLength-1 < addr)
        return 0;
    *value = data[id]->pucTable[(addr-data[id]->iStartAddr)];
    return 1;
}

int dxl_get_bulk_word(PBulkData *data, int id, int addr, int *value)
{
    if(data[id] == 0 || data[id]->iError == -1)
        return 0;
    if(addr < data[id]->iStartAddr || data[id]->iStartAddr+data[id]->iLength-2 < addr)  // 2byte
        return 0;
    *value = DXL_MAKEWORD(data[id]->pucTable[(addr-data[id]->iStartAddr)],
                          data[id]->pucTable[(addr-data[id]->iStartAddr+1)]);
    return 1;
}

int dxl_get_bulk_dword(PBulkData *data, int id, int addr, unsigned int *value)
{
    if(data[id] == 0 || data[id]->iError == -1)
        return 0;
    if(addr < data[id]->iStartAddr || data[id]->iStartAddr+data[id]->iLength-4 < addr)  // 4byte
        return 0;
    *value = DXL_MAKEDWORD(DXL_MAKEWORD(data[id]->pucTable[(addr-data[id]->iStartAddr)],
                                        data[id]->pucTable[(addr-data[id]->iStartAddr+1)]),
                           DXL_MAKEWORD(data[id]->pucTable[(addr-data[id]->iStartAddr+2)],
                                        data[id]->pucTable[(addr-data[id]->iStartAddr+3)]));
    return 1;
}
