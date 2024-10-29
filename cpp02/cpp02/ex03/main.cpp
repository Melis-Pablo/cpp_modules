#include "Point.hpp"

int main( void ) {
	
	if (bsp(Point(0,0), Point(10,10), Point(0,10), Point(5,5)) == true) {
		std::cout << "Point is inside the triangle" << std::endl;
	} else {
		std::cout << "Point is outside the triangle" << std::endl;
	}
	return 0;
}
