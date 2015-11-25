#ifndef SERIALHELPER_H
#define SERIALHELPER_H
#include <iostream>
#include "muramasa.h"
#include "logneko.h"
#include <stdio.h>

#include <termios.h>
#include <fcntl.h>

namespace neko {
using namespace std;
class SerialH
{
public:
    SerialH();
    void openPort();
    void closePort();
    int read();
    int write();
    int ConfigurePort();
    bool isOpen;

private:
    string _name;
    int _baudRate;
    struct termios tio;
    struct termios stdio;
    struct termios old_stdio;
    int tty_fd;
    LogNeko ln;
};

}
#endif // SERIALHELPER_H
