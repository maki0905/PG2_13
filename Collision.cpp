#include "Collision.h"
#include "math.h"

float Collision(float posX1, float posY1, float posX2, float posY2) {
	float a = posX1 - posX2;
	float b = posY1 - posY2;
	float c = sqrtf(a * a + b * b);
	return c;
}