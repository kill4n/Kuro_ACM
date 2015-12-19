int MotorD = 5;     //Motor Derecho
int MotorI = 6;     //Motor Izquierdo

int SGD = 8;        //Sentido giro Lado D
int SGI = 9;        //Sentido giro Lado I

void setup()
{
  pinMode(MotorD, OUTPUT);   // sets the pin as output
  pinMode(MotorI, OUTPUT);   // sets the pin as output
}

void loop()
{
    analogWrite(MotorD, 128);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
    analogWrite(MotorI, 200);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
}
