#include "Point.hpp"
//#include <iomanip>

int main( void ) {
	
	Point p1(-1,0), p2(0,10), p3(10,0);
	Point p (3, 5);

	if (bsp (p1, p2, p3, p))
		std::cout << "In!\n";
	else
		std::cout << "No!\n";
	return 0;
}