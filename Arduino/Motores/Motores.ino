int FRD = 6;        //Sentido giro Lado D
int FRI = 7;        //Sentido giro Lado I
int SGD = 8;        //Sentido giro Lado D
int SGI = 9;        //Sentido giro Lado I
int MotorD = 10;     //Motor Derecho
int MotorI = 11;     //Motor Izquierdo

int iByte = 0;
void setup()
{
  pinMode(FRD, OUTPUT);   // sets the pin as output
  pinMode(FRI, OUTPUT);   // sets the pin as output
  pinMode(SGD, OUTPUT);   // sets the pin as output
  pinMode(SGI, OUTPUT);   // sets the pin as output
  pinMode(MotorD, OUTPUT);   // sets the pin as output
  pinMode(MotorI, OUTPUT);   // sets the pin as output
  Serial.begin(9600);        // opens serial port, sets data rate to 9600 bps  
}
void loop()
{
  if (Serial.available() > 0) 
  {
    Serial.println("Llego Serial");
    // read the incoming byte:
    iByte = Serial.read();
    switch(iByte)
    {
      case 0x40: // pwm
        Serial.println("PWM");
        while(Serial.available() == 0);
        iByte = Serial.read();        
        bitSet(TCCR1B, WGM12);
        if(iByte == 0x10)// Motor Derecho
        {
          while(Serial.available() == 0);
          iByte = Serial.read();
          analogWrite(MotorD, iByte);  // analogWrite values from 0 to 255
        }
        if(iByte == 0x20)// Motor Izquierdo
        {
          while(Serial.available() == 0);
          iByte = Serial.read();
          analogWrite(MotorI, iByte);  // analogWrite values from 0 to 255
        }
        
      break;
      case 0x50: // Rueda Derecha
        Serial.println("Rueda Derecha");
        while(Serial.available() == 0);
        iByte = Serial.read();
        if(iByte == 0x10)// Freno Derecho
        {
          digitalWrite(FRD, HIGH);   // sets the LED on
        }
        else
        {
          digitalWrite(FRD, LOW);   // sets the LED off
        }
        while(Serial.available() == 0);
        iByte = Serial.read();
        if(iByte == 0x10)// Sentido de Giro Derecho
        {
          digitalWrite(SGD, HIGH);   // sets the LED on
        }
        else
        {
          digitalWrite(SGD, LOW);   // sets the LED off
        }
      break;
      case 0x60: // Rueda Izquierda
      Serial.println("Rueda Izquierda");
      while(Serial.available() == 0);
      iByte = Serial.read();
        if(iByte == 0x10)// Freno Izquierda
        {
          digitalWrite(FRI, HIGH);   // sets the LED on
        }
        else
        {
          digitalWrite(FRI, LOW);   // sets the LED off
        }
        while(Serial.available() == 0);
        iByte = Serial.read();
        if(iByte == 0x10)// Sentido de Giro Izquierda
        {
          digitalWrite(SGI, HIGH);   // sets the LED on
        }
        else
        {
          digitalWrite(SGI, LOW);   // sets the LED off
        }
      break;
      default:
      break;
    }
  }
}
