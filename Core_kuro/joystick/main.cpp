#include <iostream>
//#include "clase.h"
//#include "lib1test/TD.h"
#include "motorProy/motor.h"

using namespace std;
//using namespace nameClas;
//using namespace nameTD;

int main()
{
    Motor mot;
  //  Clase C;
    cout << "Hello World!" << endl;
    //TD td;

    return 0;
}
/*

#include <ctime>
#include <chrono>
#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
    volatile int i = 0; // "volatile" is to ask compiler not to optimize the loop away.
    auto start = std::chrono::steady_clock::now();
    //usleep(1000);
    sleep(1);
    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "It took me " << elapsed.count() << " microseconds." << std::endl;
}
*/
