#ifndef LOGNEKO_H
#define LOGNEKO_H
#include <iostream>
#include "muramasa.h"
#include <stdio.h>
#include <fstream>
#include <ctime>

namespace neko {
using namespace std;
class LogNeko
{
public:
    LogNeko(string name);
    int LogData(string mensaje, STATUS stats);
    //void write_text_to_log_file( string text );
private:
    string Name;
};

}
#endif // LOGNEKO_H
