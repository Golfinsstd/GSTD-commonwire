/*
---------------exemplo do display de 7 segmentos GSTD-commonwire---------------
autor:jabutirsom64
plataforma: Arduino/esp8266
linguagens: c/c++
-------------------------------------------------------------------------------
*/

//inclusão da biblioteca
#include <GSTD-commonwire.h>
//define os pinos do display (de A ate o pino do ponto)
svsegment display(D0, D1, D2, D3, D4, D5, D6, D7);

//setup
void setup() {
  //nada aqui :)
}
//loop infinito
void loop() {
  //escreve o ponto do display
  display.dpWRITE(1);
  //escreve do 0 ao nove no display
  for (int x = 0; x <= 9; x++) {
    display.nsvdigitWRITE(x);
    delay(500);
    display.nclearAL();
    //se a variavel "x" for maior ou igual a 10, ela volta pro valor 0
    if (x >= 10) {
      x = 0;
    }
  }
}
