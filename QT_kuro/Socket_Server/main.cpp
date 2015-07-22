#include <iostream>
using namespace std;
int main(){
    cout << "Hello World!" << endl;
    string one = "#";
    string two = "sRI 00 1";
    string tre = "$";
    one[0] = 2; tre[0] = 3;
    cout << "one_len: " << one.length() <<endl;
    cout << "two_len: " << two.length() <<endl;
    cout << "three_len: " << tre.length() <<endl;
    string dat = one + two + tre;
    cout << "dat_len: " << dat.length() <<endl;
    cout << "data: " << dat.c_str() <<endl;
    char *x= new char[50];
    strcpy(x, dat.c_str());
    cout << "datx: " << (int)x[0] <<endl;
    return 0;
}
