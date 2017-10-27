#include "circulararray.h"
#include <iostream>

int main(){
	
	CircularArray<int> test  = CircularArray<int>(6);

	std::cout << test.toString() << std::endl;

	test.fill(100, 50);

	std::cout << test.toString() << std::endl;

	test.RotateRight();

	std::cout << test.toString() << std::endl;


	test.turn(5,"left");
	std::cout << test.toString() << std::endl;


}