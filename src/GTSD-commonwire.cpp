#include <GSTD-commonwire.h>

int gpioM1G;
int mapprint;
int gpioBZ_;
int gpioA;
int gpioSWA;
int tempA;
int estado = 0;
int gpioAV_;
int gpioBV_;
int gpioCV_;
int gpioDV_;
int gpioEV_;
int gpioFV_;
int gpioGV_;
int gpioDP_;
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
void buzzerATCH::noteWRITE(String nota)
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
svsegment::svsegment(int gpioAV, int gpioBV, int gpioCV, int gpioDV, int gpioEV, int gpioFV, int gpioGV, int gpioDP)
{
  pinMode(gpioAV, OUTPUT);
  pinMode(gpioBV, OUTPUT);
  pinMode(gpioCV, OUTPUT);
  pinMode(gpioDV, OUTPUT);
  pinMode(gpioEV, OUTPUT);
  pinMode(gpioFV, OUTPUT);
  pinMode(gpioGV, OUTPUT);
  pinMode(gpioDP, OUTPUT);
  gpioAV_ = gpioAV;
  gpioBV_ = gpioBV;
  gpioCV_ = gpioCV;
  gpioDV_ = gpioDV;
  gpioEV_ = gpioEV;
  gpioFV_ = gpioFV;
  gpioGV_ = gpioGV;
  gpioDP_ = gpioDP;
}

void svsegment::svdigitWRITE(int numberDIGIT)
{
  switch (numberDIGIT)
  {
  case 0:
    digitalWrite(gpioAV_, 1);
    digitalWrite(gpioBV_, 1);
    digitalWrite(gpioCV_, 1);
    digitalWrite(gpioDV_, 1);
    digitalWrite(gpioEV_, 1);
    digitalWrite(gpioFV_, 1);

    break;
  case 1:
    digitalWrite(gpioBV_, 1);
    digitalWrite(gpioCV_, 1);
    break;
  case 2:
    digitalWrite(gpioAV_, 1);
    digitalWrite(gpioBV_, 1);
    digitalWrite(gpioGV_, 1);
    digitalWrite(gpioEV_, 1);
    digitalWrite(gpioDV_, 1);
    break;
  case 3:
    digitalWrite(gpioAV_, 1);
    digitalWrite(gpioBV_, 1);
    digitalWrite(gpioGV_, 1);
    digitalWrite(gpioCV_, 1);
    digitalWrite(gpioDV_, 1);
    break;
  case 4:
    digitalWrite(gpioFV_, 1);
    digitalWrite(gpioBV_, 1);
    digitalWrite(gpioGV_, 1);
    digitalWrite(gpioCV_, 1);
    break;
  case 5:
    digitalWrite(gpioAV_, 1);
    digitalWrite(gpioFV_, 1);
    digitalWrite(gpioGV_, 1);
    digitalWrite(gpioCV_, 1);
    digitalWrite(gpioDV_, 1);
    break;
  case 6:
    digitalWrite(gpioAV_, 1);
    digitalWrite(gpioFV_, 1);
    digitalWrite(gpioGV_, 1);
    digitalWrite(gpioCV_, 1);
    digitalWrite(gpioEV_, 1);
    digitalWrite(gpioDV_, 1);
    break;
  case 7:
    digitalWrite(gpioAV_, 1);
    digitalWrite(gpioBV_, 1);
    digitalWrite(gpioCV_, 1);
    break;
  case 8:
    digitalWrite(gpioAV_, 1);
    digitalWrite(gpioBV_, 1);
    digitalWrite(gpioCV_, 1);
    digitalWrite(gpioDV_, 1);
    digitalWrite(gpioEV_, 1);
    digitalWrite(gpioFV_, 1);
    digitalWrite(gpioGV_, 1);
    break;
  case 9:
    digitalWrite(gpioAV_, 1);
    digitalWrite(gpioBV_, 1);
    digitalWrite(gpioGV_, 1);
    digitalWrite(gpioFV_, 1);
    digitalWrite(gpioCV_, 1);
    break;
  default:
    digitalWrite(gpioAV_, 0);
    digitalWrite(gpioBV_, 0);
    digitalWrite(gpioCV_, 0);
    digitalWrite(gpioDV_, 0);
    digitalWrite(gpioEV_, 0);
    digitalWrite(gpioFV_, 0);
    digitalWrite(gpioGV_, 0);
    break;
  }
}
void svsegment::clearAL()
{
  digitalWrite(gpioAV_, 0);
  digitalWrite(gpioBV_, 0);
  digitalWrite(gpioCV_, 0);
  digitalWrite(gpioDV_, 0);
  digitalWrite(gpioEV_, 0);
  digitalWrite(gpioFV_, 0);
  digitalWrite(gpioGV_, 0);
}
void svsegment::dpWRITE(int dpSTATE)
{
  if (dpSTATE == 1)
  {
    digitalWrite(gpioDP_, 1);
  }
  else if (dpSTATE >= 2)
  {
    digitalWrite(gpioDP_, 0);
  }
}
void svsegment::nsvdigitWRITE(int numberDIGIT2)
{
  switch (numberDIGIT2)
  {
  case 0:
    digitalWrite(gpioAV_, 0);
    digitalWrite(gpioBV_, 0);
    digitalWrite(gpioCV_, 0);
    digitalWrite(gpioDV_, 0);
    digitalWrite(gpioEV_, 0);
    digitalWrite(gpioFV_, 0);

    break;
  case 1:
    digitalWrite(gpioBV_, 0);
    digitalWrite(gpioCV_, 0);
    break;
  case 2:
    digitalWrite(gpioAV_, 0);
    digitalWrite(gpioBV_, 0);
    digitalWrite(gpioGV_, 0);
    digitalWrite(gpioEV_, 0);
    digitalWrite(gpioDV_, 0);
    break;
  case 3:
    digitalWrite(gpioAV_, 0);
    digitalWrite(gpioBV_, 0);
    digitalWrite(gpioGV_, 0);
    digitalWrite(gpioCV_, 0);
    digitalWrite(gpioDV_, 0);
    break;
  case 4:
    digitalWrite(gpioFV_, 0);
    digitalWrite(gpioBV_, 0);
    digitalWrite(gpioGV_, 0);
    digitalWrite(gpioCV_, 0);
    break;
  case 5:
    digitalWrite(gpioAV_, 0);
    digitalWrite(gpioFV_, 0);
    digitalWrite(gpioGV_, 0);
    digitalWrite(gpioCV_, 0);
    digitalWrite(gpioDV_, 0);
    break;
  case 6:
    digitalWrite(gpioAV_, 0);
    digitalWrite(gpioFV_, 0);
    digitalWrite(gpioGV_, 0);
    digitalWrite(gpioCV_, 0);
    digitalWrite(gpioEV_, 0);
    digitalWrite(gpioDV_, 0);
    break;
  case 7:
    digitalWrite(gpioAV_, 0);
    digitalWrite(gpioBV_, 0);
    digitalWrite(gpioCV_, 0);
    break;
  case 8:
    digitalWrite(gpioAV_, 0);
    digitalWrite(gpioBV_, 0);
    digitalWrite(gpioCV_, 0);
    digitalWrite(gpioDV_, 0);
    digitalWrite(gpioEV_, 0);
    digitalWrite(gpioFV_, 0);
    digitalWrite(gpioGV_, 0);
    break;
  case 9:
    digitalWrite(gpioAV_, 0);
    digitalWrite(gpioBV_, 0);
    digitalWrite(gpioGV_, 0);
    digitalWrite(gpioFV_, 0);
    digitalWrite(gpioCV_, 0);
    break;
  default:
    digitalWrite(gpioAV_, 1);
    digitalWrite(gpioBV_, 1);
    digitalWrite(gpioCV_, 1);
    digitalWrite(gpioDV_, 1);
    digitalWrite(gpioEV_, 1);
    digitalWrite(gpioFV_, 1);
    digitalWrite(gpioGV_, 1);
    break;
  }
}

void svsegment::nclearAL()
{
  digitalWrite(gpioAV_, 1);
  digitalWrite(gpioBV_, 1);
  digitalWrite(gpioCV_, 1);
  digitalWrite(gpioDV_, 1);
  digitalWrite(gpioEV_, 1);
  digitalWrite(gpioFV_, 1);
  digitalWrite(gpioGV_, 1);
}
