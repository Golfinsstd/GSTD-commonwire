/*
---------------exemplo blink GSTD-commonwire---------------
autor:jabutirsom64
plataforma: Arduino/esp8266
linguagens: c/c++
-----------------------------------------------------------
*/
//inclusão da biblioteca
#include <GSTD-commonwire.h>
//define o pino do motor
motorPIN gpioNMOS(D8);

//setup

void setup()
{
//nada aqui :)
}
//loop infinito
void loop() {
  // put your main code here, to run repeatedly
  //define a velocidade do motor em 100 (a velocidade varia de 0 a 100)
  gpioNMOS.motorwrite(100);
  //imprime a velocidade do motor no monitor Serial (115200)
  gpioNMOS.printspeed();
}
