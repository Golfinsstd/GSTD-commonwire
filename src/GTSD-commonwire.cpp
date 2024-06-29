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

int gpioM1G;
int mapprint;
int gpioBZ_;
int gpioA;
int gpioSWA;
int tempA;
int estado = 0;

unsigned long execANT = 0;

commonFUNC::commonFUNC(int gpio, int temp)
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

  for (int fadeVR = 0; fadeVR <= 255; fadeVR += 2)
  {
    analogWrite(gpioA, fadeVR);
    delay(20);
  }
  for (int fadeVR = 255; fadeVR >= 255; fadeVR -= 2)
  {
    analogWrite(gpioA, fadeVR);
    delay(20);
  }
}

motorPIN::motorPIN(int gpioM1)
{
  gpioM1G = gpioM1;
  pinMode(gpioM1, OUTPUT);
  Serial.begin(115200);
}

void motorPIN::motorwrite(int mapwm)
{
  mapprint = mapwm;
  int pwm = map(mapwm, 0, 100, 0, 255);
  analogWrite(gpioM1G, pwm);
  delay(1);
}
void motorPIN::printspeed()
{
  Serial.print("velocidade(de 0 a 100):");
  Serial.println(mapprint);
}
buzzerATCH::buzzerATCH(int gpioBZ)
{
  pinMode(gpioBZ, OUTPUT);
  gpioBZ_ = gpioBZ;
}
void buzzerATCH::noteWRITE(string nota)
{

  int convertstr;
  if (nota == "do")
  {
    convertstr = 1;
  }
    if (nota == "re")
  {
     convertstr = 2;
  }
    if (nota == "mi")
  {
     convertstr = 3;
  }
    if (nota == "fa")
  {
     convertstr = 4;
  }
    if (nota == "sol")
  {
     convertstr = 5;
  }
    if (nota == "la")
  {
     convertstr = 6;
  }
    if (nota == "si")
  {
     convertstr = 7;
  }
  noTone(gpioBZ_);
  switch (convertstr)
  {
  case 1:
    tone(gpioBZ_, 262);
    delay(80);
    break;
  case 2:
    tone(gpioBZ_, 294);
    delay(80);
    break;
  case 3:
    tone(gpioBZ_, 330);
    delay(80);
    break;
  case 4:
    tone(gpioBZ_, 349);
    delay(80);
    break;
  case 5:
    tone(gpioBZ_, 392);
    delay(80);
    break;
  case 6:
    tone(gpioBZ_, 440);
    delay(80);
    break;
  case 7:
    tone(gpioBZ_, 494);
    delay(80);
    break;
  default:
    noTone(gpioBZ_);
    break;
  }
}
