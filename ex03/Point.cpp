#include "Point.hpp"
#include <cmath>

Point::Point(void): x(0), y(0){
	
}

Point::Point(float p1, float p2): x(p1), y(p2){

}

Point::~Point(void){

}

Point::Point(const Point &obj): x(obj.x), y(obj.y){


}

Point&	Point::operator=(const Point &obj){

	(void)obj;
	//std::cout << "Can not use \"=\" to remodifie a value of a Point!\n";
	return *this;
}

Fixed	Point::getX(void) const{

	return this->x;
}
Fixed	Point::getY(void) const{

	return this->y;
}

bool bsp( Point const a, Point const b, Point const c, Point const point){

	bool b1, b2, b3;

    b1 = a.crossProduct(point, a, b) < 0.0f;
    b2 = a.crossProduct(point, b, c) < 0.0f;
    b3 = a.crossProduct(point, c, a) < 0.0f;

    return ((b1 == b2) && (b2 == b3));
}

float Point::crossProduct(Point const &p1, Point const &p2, Point const &base){

    return ((p1.getX() - base.getX()) * (p2.getY() - base.getY()) - (p2.getX() - base.getX()) * (p1.getY() - base.getY())).toFloat();
}
