#include <stdio.h>
#include <wiringPi>
#include <math.h>

#define ENTRADA 2
#define ANTENATX 3
#define TE 0
#define ANTENARX 4
#define LAMPADA 1

int main(void) {
	printf("Setup... ");
	int leitura_digital = 2;
	int leitura_antena = 2;
	float acumulador_1 = 0;
	float acumulador_total = 0;
	float pwm = 0;
	wiriginPiSetup()
	pinMode(ENTRADA, INPUT);
	pinMode(LAMPADA, OUTPUT);
	pinMode(TE, OUTPUT);
	pinMode(ANTENARX, INPUT);
	pinMode(ANTENATX, OUTPUT);
	printf(" Setup OK.");

	for (;;) {
		leitura_digital = digitalRead(ENTRADA);
		if (leitura_digital == 1) {
			acumulador_1++;
		}
		acumulador_total++;

		if (acumulador_total == 1000) {
			printf("\n");
		}

		if (acumulador_total == 1000) {
			pwm = 5 * (acumulador_1 / acumulador_total);
			temp = (1.7 - log(pwm)) / 0.0306;
			acumulador_1 = 0;
			acumulador_total = 0;
			printf("pwm = %f                      temp = %f ºC", pwm, temp);
			if (temp <= 32) {
				digitalWrite(ANTENATX, HIGH);
				digitalWrite(TE, LOW);
			} else {
				digitalWrite(ANTENATX, LOW);
				digitalWrite(TE, LOW);
			}
			delay(100);
			digitalWrite(TE, HIGH);
			leitura_antena = digitalRead(ANTENARX);
			printf (“leitura_antena = %d”, leitura_antena);
			if (leitura_antena == 1) {
				digitalWrite(LAMPADA, HIGH);
			} else {
				digitalWrite(LAMPADA, LOW);
			}
		}
		delay(1);
	}
	return 0;
}
