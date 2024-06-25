/*
---------------exemplo FADE GSTD-commonwire----------------
autor:jabutirsom64
plataforma: Arduino/esp8266
linguagens: c/c++
-----------------------------------------------------------
*/
//inclusão da biblioteca
#include <GSTD-commonwire.h>
//define o pino do LED
commonFUNC pwmLED(D4,0);
//setup
void setup()
{
//nada aqui :)
}
//loop infinito
void loop()
{
//faz o efeito "fade" no LED
pwmLED.fade();
}