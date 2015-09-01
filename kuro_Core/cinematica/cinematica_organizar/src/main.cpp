#include <iostream>
#include "kin_ack.h"

using namespace std;

int main()
{
    Kin_Ack AckKin(0.7, 0.7);
    cout << "KINEMATICS PROGRAM" << endl;
    AckKin.setVel_Lin(1);
    AckKin.setPhi(15, true);

    for (int i = 0; i < 100; ++i) {
        AckKin.Mover();
    }


    return 0;
}
