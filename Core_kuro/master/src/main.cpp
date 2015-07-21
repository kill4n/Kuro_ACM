#include <iostream>
#include <fstream>

#include "logneko.h"

using namespace std;
using namespace neko;

int main()
{
    LogNeko ln("Master");
    cout << "Hello World!" << endl;
    //    write_text_to_log_file("Hola mama");
    ln.LogData("Hola Log1",NK_OK);
    ln.LogData("Hola Log2",NK_ERROR);
    return 0;
}
