#include "clas2.h"
#include "clas1.h"
#include "stdio.h"

clas2::clas2()
{
}

void clas2::metod(void *unused, void *unused2)
{
    printf("Datos {%d}\r\n",((clas1*)unused)->dat);
    ((clas2*)unused2)->y= ((clas1*)unused)->dat*2;
}

void clas2::poten(int d)
{
    y=d*2;
}
