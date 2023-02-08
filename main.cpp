#include "mbed.h"

const double pi = 3.141592653589793238462;
const double amplitude = 0.5f;

// The sinewave is created on this pin
// Adjust analog output pin name to your board spec.
PwmOut aout(PB_0);

int main()
{
    double rads = 0.0;
    float sample[36] = {0};

    // sinewave output
    for (int i = 0; i < 36; i++) {
        rads = (pi * i*10) / 180.0f;
        sample[i] = (amplitude * (1.0 + sin(rads)));
    }
    aout.period(0.0000315);              // 1.0/(2*440Hz*36)
    while (1) {
        for (int i = 0; i < 36; i++) {       
            aout.write(sample[i]);
            wait_us(63);                 // 1.0/(440Hz*36) = 63.13 us
        }
    }
}

