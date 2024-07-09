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
svsegment display(2, 3, 4, 5, 6, 7, 8, 9);

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
    display.svdigitWRITE(x);
    delay(500);
    display.clearAL();
    //se a variavel "x" for maior ou igual a 10, ela volta pro valor 0
    if (x >= 10) {
      x = 0;
    }
  }
}