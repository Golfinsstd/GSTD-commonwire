/*
---------------exemplo notes GSTD-commonwire---------------
autor:jabutirsom64
plataforma: Arduino/esp8266
linguagens: c/c++
-----------------------------------------------------------
*/
//inclusão da biblioteca
#include <GSTD-commonwire.h>
//define o pino do buzzer
buzzerATCH gpioBUZZER(D8);
//setup
void setup() {
  //nada aqui :)
}
//loop infinito
void loop() {
//toca as notas progressivamente de 500 em 500 milisegundos (do "Dó" ate o "SI")
gpioBUZZER.noteWRITE("do");
delay(500);
gpioBUZZER.noteWRITE("re");
delay(500);
gpioBUZZER.noteWRITE("mi");
delay(500);
gpioBUZZER.noteWRITE("fa");
delay(500);
gpioBUZZER.noteWRITE("sol");
delay(500);
gpioBUZZER.noteWRITE("la");
delay(500);
gpioBUZZER.noteWRITE("si");
delay(50);
}
