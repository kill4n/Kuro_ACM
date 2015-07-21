#include "logneko.h"
using namespace neko;

LogNeko::LogNeko(string name)
{
    this->Name = name;
}

int LogNeko::LogData(string mensaje, STATUS stats)
{
    string t = "Clase :: " + this->Name + " (";
    switch (stats) {
    case NK_OK:
        t += "^_^";
        break;
    case NK_ERROR:
        t += "X_X";
        break;
    default:
        break;
    }
    t += ") " + mensaje + " [O_O] " + __TIMESTAMP__;
    cout<< t <<endl;
    ofstream outfile;
    outfile.open(LOG_NAME,ios_base::out | ios_base::app);
    outfile << t <<endl;
    return 0;
}
