#include <stdio.h>
#include <wiringPi>

#define LED 0
#define ENTRADA 2

int main(void)
{
  printf ("Setup... ");
  int leitura_digital = 2;
  int acumulador_1 = 0;
  int acumulador_total = 0;
  float pwm = 0;
  wiriginPiSetup()
  pinMode(LED, OUTPUT);
  pinMode(ENTRADA, INPUT);
  printf (" Setup OK.");
  
  for(;;)
  {
    leitura_digital = digitalRead(ENTRADA);
    if (leitura_digital == 1)
    {
      acumulador_1 ++;
    }
    acumulador_total++;
    if (acumulador_total == 1000)
    {
      pwm = 100*(acumulador_1 / acumulador_total); //EDIT: imprime em %
      acumulador_1 = 0;
      acumulador_total = 0;
      printf ("pwm = %f", pwm);
    }
    delay(1);
  }
  return 0;
}
