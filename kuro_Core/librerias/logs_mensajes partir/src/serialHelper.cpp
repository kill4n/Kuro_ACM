#include "serialHelper.h"
/*
using namespace neko;

SerialH::SerialH():
    ln("Serial")
{
    this->_name = "/dev/ttyUSB0";
    this->_baudRate = B9600;
    this->isOpen = false;
    ln.LogData("Create", NK_OK);
}

void SerialH::openPort()
{
    this->tty_fd = open(this->_name.c_str(), O_RDWR | O_NOCTTY );
    if (this->tty_fd < 0) {
        this->isOpen = true;
    }
    else{
        this->isOpen = false;
    }
}

int SerialH::ConfigurePort()
{
    memset (&tio, 0, sizeof tio);

    /* Error Handling * /
    if ( tcgetattr ( this->tty_fd, &this->tio) != 0 ) {
        std::cout << "Error " << errno << " from tcgetattr: " << strerror(errno) << std::endl;
        return NK_ERROR;
    }

    /* Save old tty parameters * /
    old_stdio = tio;

    /* Set Baud Rate * /
    cfsetospeed (&tio, (speed_t)this->_baudRate);
    cfsetispeed (&tio, (speed_t)this->_baudRate);

    /* Setting other Port Stuff * /
    tio.c_cflag     &=  ~PARENB;            // Make 8n1
    tio.c_cflag     &=  ~CSTOPB;
    tio.c_cflag     &=  ~CSIZE;
    tio.c_cflag     |=  CS8;

    tio.c_cflag     &=  ~CRTSCTS;           // no flow control
    tio.c_cc[VMIN]   =  1;                  // read doesn't block
    tio.c_cc[VTIME]  =  5;                  // 0.5 seconds read timeout
    tio.c_cflag     |=  CREAD | CLOCAL;     // turn on READ & ignore ctrl lines

    /* Make raw * /
    cfmakeraw(&tio);

    /* Flush Port, then applies attributes * /
    tcflush( this->tty_fd, TCIFLUSH );
    if ( tcsetattr ( this->tty_fd, TCSANOW, &tio ) != 0) {
        std::cout << "Error " << errno << " from tcsetattr" << std::endl;
        return NK_ERROR;
    }
    return NK_OK;
}
*/
