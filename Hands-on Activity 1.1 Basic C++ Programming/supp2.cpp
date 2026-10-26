#include <iostream>

float kelToFah(int kelvin);

int main(){
	std::cout<<kelToFah(1);
}

float kelToFah(int kelvin){
	float converted = kelvin - 273.15;
	converted = converted * 1.8;
	converted = converted + 32;
	
	return converted;
}
