/*
---------------exemplo blink GSTD-commonwire---------------
autor:jabutirsom64
plataforma: Arduino/esp8266
linguagens: c/c++
-----------------------------------------------------------
*/

//inclusão da biblioteca
#include <GSTD-commonwire.h>

//define o pino do LED e o tempo que o led ira piscar
commonFUNC bultinLED(D4,1000);
//setup
void setup() {
//nada aqui :)
}
//loop infinito
void loop() {
//pisca o led
bultinLED.blink();

}
