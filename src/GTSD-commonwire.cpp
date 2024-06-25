#include <GSTD-commonwire.h>
#define D0 16
#define D1 5
#define D2 4
#define D3 0
#define D4 2
#define D5 14
#define D6 12
#define D7 13
#define D8 15
#define ADC0 A0

int gpioA;
int gpioSWA;
int tempA;
int estado =0;

unsigned long execANT =0;

commonFUNC::commonFUNC(int gpio,int temp)
{
gpioA = gpio;
tempA = temp;
pinMode(gpio, OUTPUT);
}


void commonFUNC::blink()
{

  if (millis() - execANT >= tempA)
  {
    execANT = millis();
    if (estado == 0)
    {
      estado = 1;
    }
    else
    {

      estado = 0;
    }
    digitalWrite(gpioA, estado);
  }
}

  void commonFUNC::fade()
  {
    

    for(int fadeVR =0;fadeVR <= 255;fadeVR += 2)
    {
      analogWrite(gpioA,fadeVR);
      delay(20);
     
    }
    for(int fadeVR =255;fadeVR >= 255;fadeVR -= 2)
    {
      analogWrite(gpioA,fadeVR);
     delay(20);
    }
    

  }
