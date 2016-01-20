#include <stdio.h>
#include <math.h>

double getDistance (double initialVelocity, double acceleration, double time) {
	return (initialVelocity * time) + ((acceleration / 2) * pow(time, 2));
}

int main (int argc, char *argv[]) {
	
	double initialVelocity = 0,
		acceleration = 10,
		minutes = 2,
		time = minutes * 60; // Convert minutes to seconds.

	double distance = getDistance(initialVelocity, acceleration, time);

	printf("Distance is: %f m\n", distance);

	return 0;
}
