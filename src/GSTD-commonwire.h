#ifndef GSTD_COMMONWIRE
#define GSTD_COMMONWIRE

#include <Arduino.h>

class commonFUNC

{
private:
public:
  commonFUNC(int gpio, int temp);
  void blink();
  void fade();
};

class motorPIN
{
private:
public:
  motorPIN(int gpioM1);
  void motorwrite(int mapwm);
  void printspeed();
};
class buzzerATCH
{
private:
public:
  buzzerATCH(int gpioBZ);
  void noteWRITE(String nota);
};
class svsegment
{
private:
public:
  svsegment(int gpioAV, int gpioBV, int gpioCV, int gpioDV, int gpioEV, int gpioFV, int gpioGV, int gpioDP);
  void svdigitWRITE(int numberDIGIT);
  void dpWRITE(int dpSTATE);
  void clearAL();
};
#endif
