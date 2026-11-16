
#include <stdio.h>
#include <pigpio.h>

#define PIN 17
#define COUNT 5

int main() {
    double temp, total = 0;
    double minTemp, maxTemp;
    int count = 0;
    char *status;

    printf("Enter minimum temperature: ");
    scanf("%lf", &minTemp);

    printf("Enter maximum temperature: ");
    scanf("%lf", &maxTemp);

    if (minTemp >= maxTemp) {
        printf("Invalid temperature range!\n");
        return 1;
    }

    FILE *file = fopen("temperature_records.txt", "a");

    if (file == NULL) {
        printf("File error!\n");
        return 1;
    }

    if (gpioInitialise() < 0) {
        printf("GPIO error!\n");
        fclose(file);
        return 1;
    }

    gpioSetMode(PIN, PI_OUTPUT);

    fprintf(file, "\nTemperature Range: %.1f - %.1f F\n",
            minTemp, maxTemp);

    for (int i = 0; i < COUNT; i++) {
        printf("Enter temperature %d: ", i + 1);

        if (scanf("%lf", &temp) != 1) {
            printf("Invalid input!\n");
            break;
        }

        total += temp;
        count++;

        if (temp < minTemp || temp > maxTemp) {
            gpioWrite(PIN, 1);
            status = "WARNING";
            printf("WARNING: LED ON\n");
        } else {
            gpioWrite(PIN, 0);
            status = "NORMAL";
            printf("NORMAL: LED OFF\n");
        }

        fprintf(file, "%.2f F - %s\n", temp, status);
    }

    if (count > 0) {
        printf("Average: %.2f F\n", total / count);
        fprintf(file, "Average: %.2f F\n", total / count);
    }

    fclose(file);
    gpioWrite(PIN, 0);
    gpioTerminate();

    return 0;
}
