#include <stdio.h>
#include <pigpio.h>

#define PIN 17
#define COUNT 5

int main() {
double temp, total = 0;

if (gpioInitialise() < 0) {
printf("GPIO error\n");
return 1;
}

gpioSetMode(PIN, PI_OUTPUT);

for (int i = 0; i < COUNT; i++) {
	printf("Enter temperature %d (F): ", i + 1);

	if (scanf("%lf", &temp) != 1) {
		printf("Invalid input!\n");
		break;
	}

	total += temp;

	if (temp < 68 || temp > 76) {
		gpioWrite(PIN, 1); // LED ON
		printf("WARNING: LED ON\n");
	} else {
		gpioWrite(PIN, 0); // LED OFF
		printf("Normal: LED OFF\n");
	}
}
printf("Average temperature: %.2f F\n", total / COUNT);

gpioWrite(PIN, 0);
gpioTerminate();

return 0;

}
