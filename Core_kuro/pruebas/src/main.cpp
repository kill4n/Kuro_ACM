#include <iostream>
#include <stdio.h>
#include "string"
#include "fstream"
#include "neko/include/kurosocket.h"

using namespace std;

int main()
{

    /*    string data = "HOLa MundO";
    cout<< "original: " << data <<endl;
    transform(data.begin(), data.end(), data.begin(), ::tolower);
    cout<< "Final: " << data <<endl;

    string line;
    ifstream myfile ("example.txt");
    if (myfile.is_open())
    {
        while ( getline(myfile,line) )
        {
            cout << line << '\n';
            cout << "Longitud: " << line.length() << endl;
            transform(line.begin(), line.end(), line.begin(), ::tolower);
            cout << "MINUSCULAS: " << line.length() << endl;
        }
        myfile.close();
    }

    else cout << "Unable to open file";
*/
    printf("hola mundo \r\n");
    kuroSocket KS(4444);

    cout <<"Puerto: "<< KS.getPuerto() <<endl;
    return 0;
}
