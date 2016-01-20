#include <stdio.h>
#include <math.h>

double getAcceleration (double initialVelocity, double distance, double time) {
    return (2 * distance / pow(time, 2)) - (2 * initialVelocity / time);
}

double getVelocity (double initialVelocity, double distance, double time) {
    return (2 * distance / time) - initialVelocity;
}

double getTime (double deceleration, double initialVelocity, double velocity) {
    return deceleration * (velocity - initialVelocity);
}

int main (int argc, char *argv[]) {

    double	
        initialVelocity = 0,
        distance = 12100,
        time = 110;	

    double
        acceleration = getAcceleration(initialVelocity, distance, time),
        deceleration = acceleration / 2;

    printf("Acceleration: %f m/s^2\n", acceleration);
    printf("Deceleration: %f m/s^2\n", deceleration);

    double velocity = getVelocity(initialVelocity, distance, time);

    printf("Velocity: %f m/s\n", velocity);

    double timeToStop = getTime(deceleration, initialVelocity, velocity);

    printf("Time to stop: %f s\n", timeToStop);

    return 0;
}
