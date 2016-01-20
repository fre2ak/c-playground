#include <stdio.h>

double getVelocity (double initialVelocity, double acceleration, double time) {
	return initialVelocity + acceleration * time;
}

int main (int argc, char *argv[]) {

	double initialVelocity = 0,
		acceleration = 10,
		minutes = 2,
		time = minutes * 60; // Convert time in seconds.

	double velocity = getVelocity(initialVelocity, acceleration, time);	

	printf("Velocity after 2 minutes: %f m/s\n", velocity);

	return 0;
}
