#include <iostream>
#include <cmath>

void distanceOfTwo(float xOne, float yOne, float xTwo, float yTwo);

int main(){
	distanceOfTwo(5,6,3,4);
}

void distanceOfTwo(float xOne, float yOne, float xTwo, float yTwo){
	float totalX = xTwo - xOne;
	float totalY = yTwo - yOne;
	totalX = totalX * totalX;
	totalY = totalY * totalY;
	
	float finalTotal = sqrt(totalX + totalY);
	
	std::cout << "The distance between: " << "X1: " << xOne << " Y1: " << yOne << " and X2: " << xTwo << " Y2: " << yTwo << " is: " << finalTotal;
}


