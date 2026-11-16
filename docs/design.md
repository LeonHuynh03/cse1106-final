* Design 
* Original Function and Modifications

We kept the original GPIO functions, including gpioInitialise(), gpioSetMode(), gpioWrite(), and gpioTerminate() to control the LED on GPIO 17.

We modified the original program by replacing getchar() with scanf() to accept temperature inputs. We also added conditions to control the LED automatically:
- Below 68°F or above 76°F: LED ON.
- Between 68°F and 76°F: LED OFF.
We also added five temperature readings and an average calculation to complete our Smart Classroom Comfort Monitor.
