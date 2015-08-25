// windows version
// by windows serial programming
#include <windows.h>
#include <stdio.h>
#include "dxl_hal.h"

#define LATENCY_TIME        (16)    //ms    (USB2Serial Latency timer)

////////////////////////////////////////////////////////////////////////////////
/// summary : Get current time
/// return  : the current time (in milliseconds)
double  dxl_hal_get_curr_time()
{
    LARGE_INTEGER freq, counter;
    QueryPerformanceCounter(&counter);
    QueryPerformanceFrequency(&freq);
    return (double)counter.QuadPart / (double)freq.QuadPart * 1000.0;
}

////////////////////////////////////////////////////////////////////////////////
/// summary : Open device
/// param   : port       handle to COM port
/// param   : dev_index  device index
/// param   : baudrate   real baudrate (ex: 115200, 57600, 38400, ...)
/// return  :
///    0 - failed
///    1 - succeed
int dxl_hal_open( void** port, int dev_index, float baudrate )
{
    DCB Dcb;
    COMMTIMEOUTS Timeouts;
    DWORD dwError;
    char PortName[15];

    dxl_hal_close( port );

    // Make real port name
    sprintf_s(PortName, sizeof(PortName), "\\\\.\\COM%d", dev_index);
    // Open serial device
    *port = CreateFile( PortName, GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );
    if( *port == INVALID_HANDLE_VALUE )
        return 0;

    // Setting communication property
    Dcb.DCBlength = sizeof(DCB);
    if( GetCommState( *port, &Dcb ) == FALSE )
        goto DXL_HAL_OPEN_ERROR;
    
    // Set baudrate
    Dcb.BaudRate            = (DWORD)baudrate;    
    Dcb.ByteSize            = 8;                    // Data bit = 8bit
    Dcb.Parity              = NOPARITY;             // No parity
    Dcb.StopBits            = ONESTOPBIT;           // Stop bit = 1
    Dcb.fParity             = NOPARITY;             // No Parity check
    Dcb.fBinary             = 1;                    // Binary mode
    Dcb.fNull               = 0;                    // Get Null byte
    Dcb.fAbortOnError       = 0;
    Dcb.fErrorChar          = 0;
    // Not using XOn/XOff
    Dcb.fOutX               = 0;
    Dcb.fInX                = 0;
    // Not using H/W flow control
    Dcb.fDtrControl         = DTR_CONTROL_DISABLE;
    Dcb.fRtsControl         = RTS_CONTROL_DISABLE;
    Dcb.fDsrSensitivity     = 0;
    Dcb.fOutxDsrFlow        = 0;
    Dcb.fOutxCtsFlow        = 0;
    if( SetCommState( *port, &Dcb ) == FALSE )
        goto DXL_HAL_OPEN_ERROR;

    if( SetCommMask( *port, 0 ) == FALSE ) // Not using Comm event
        goto DXL_HAL_OPEN_ERROR;
    if( SetupComm( *port, 4096, 4096 ) == FALSE ) // Buffer size (Rx,Tx)
        goto DXL_HAL_OPEN_ERROR;
    if( PurgeComm( *port, PURGE_TXABORT|PURGE_TXCLEAR|PURGE_RXABORT|PURGE_RXCLEAR ) == FALSE ) // Clear buffer
        goto DXL_HAL_OPEN_ERROR;
    if( ClearCommError( *port, &dwError, NULL ) == FALSE )
        goto DXL_HAL_OPEN_ERROR;
    
    if( GetCommTimeouts( *port, &Timeouts ) == FALSE )
        goto DXL_HAL_OPEN_ERROR;
    // Timeout (Not using timeout)
    // Immediatly return
    Timeouts.ReadIntervalTimeout = 0;
    Timeouts.ReadTotalTimeoutMultiplier = 0;
    Timeouts.ReadTotalTimeoutConstant = 1; // must not be zero.
    Timeouts.WriteTotalTimeoutMultiplier = 0;
    Timeouts.WriteTotalTimeoutConstant = 0;
    if( SetCommTimeouts( *port, &Timeouts ) == FALSE )
        goto DXL_HAL_OPEN_ERROR;
    
    return 1;

DXL_HAL_OPEN_ERROR:
    dxl_hal_close( port );
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
/// summary : Close device
/// param   : port       handle to COM port
void dxl_hal_close( void** port )
{
    // Closing device
    if(*port != INVALID_HANDLE_VALUE)
    {
        CloseHandle( *port );
        *port = INVALID_HANDLE_VALUE;
    }
}

////////////////////////////////////////////////////////////////////////////////
/// summary : Change com port baudrate
/// param   : port       handle to COM port
/// param   : baudrate   real baudrate to set
/// return  :
///    0 - failed
///    1 - succeed
int dxl_hal_change_baudrate( void* port, float baudrate )
{
    DCB Dcb;
    GetCommState(port, &Dcb);
    Dcb.BaudRate = (DWORD) baudrate;

    if( SetCommState( port, &Dcb ) == FALSE )
    {
        dxl_hal_close( &port );
        return 0;
    }
    else
    {
        return 1;
    }
}

////////////////////////////////////////////////////////////////////////////////
/// summary : Clear receive buffer
/// param   : port       handle to COM port
void dxl_hal_clear( void* port )
{
    // Clear communication buffer
    PurgeComm( port, PURGE_RXABORT|PURGE_RXCLEAR );
}

////////////////////////////////////////////////////////////////////////////////
/// summary : Sending data
/// param   : port       handle to COM port
/// param   : buf        pointer to data to write
/// param   : count      number of bytes to write
/// return  : number of bytes written or -1(error)
int dxl_hal_write( void* port, const void *buf, unsigned int count )
{
    DWORD dwWritten = 0;

    if( WriteFile( port, buf, count, &dwWritten, NULL ) == FALSE )
        return -1;
    
    return (int)dwWritten;
}

////////////////////////////////////////////////////////////////////////////////
/// summary : Receiving data
/// param   : port       handle to COM port
/// param   : buf        pointer to data to read
/// param   : count      number of bytes to read
/// return  : number of bytes read or -1(error)
int dxl_hal_read( void* port, void *buf, unsigned int count )
{
    DWORD dwRead = 0;

    if( ReadFile( port, buf, (DWORD)count, &dwRead, NULL ) == FALSE )
        return -1;

    return (int)dwRead;
}

