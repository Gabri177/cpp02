#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed (void): _nbr_val(0) {

	//std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed (void) {

	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &arg_obj){

	//std::cout << "Copy constructor called" << std::endl;
	//this->setRawBits (arg_obj.getRawBits());
	*this = arg_obj;
}

Fixed&	Fixed::operator=(const Fixed &arg_obj){

	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &arg_obj)
		this->_nbr_val = arg_obj.getRawBits ();
	return *this;
}

int		Fixed::getRawBits(void) const {

	//std::cout << "getRawBits member function called" << std::endl;
	return _nbr_val;
}

void		Fixed::setRawBits(int const raw){

	_nbr_val = raw;
}

Fixed::Fixed(const int num): _nbr_val(num << _nbr_bits){

	//std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num): _nbr_val(std::roundf(num * (1 << _nbr_bits))){

	//std::cout << "Float constructor called" << std::endl;
}

int			Fixed::toInt(void) const{

	return this->_nbr_val >> _nbr_bits;
}

float		Fixed::toFloat(void) const{

	return static_cast<float>(this->getRawBits ()) / (1 << _nbr_bits);
}

std::ostream& operator<<(std::ostream& out, Fixed const &obj){

	//std::cout << "Copy assignment operator called" << std::endl;
	out << obj.toFloat();
	return out;
}

Fixed				Fixed::operator+(const Fixed &arg_obj){

	return Fixed(static_cast<float>(this->getRawBits() + arg_obj.getRawBits()) / (1 << _nbr_bits));
}

Fixed				Fixed::operator-(const Fixed &arg_obj){
	
	return Fixed(static_cast<float>(this->getRawBits() - arg_obj.getRawBits()) / (1 << _nbr_bits));
}

Fixed				Fixed::operator*(const Fixed &arg_obj){
	
	return Fixed(static_cast<float>((arg_obj.getRawBits () >> this->_nbr_bits) * this->getRawBits()) / (1 << _nbr_bits));
}

Fixed				Fixed::operator/(const Fixed &arg_obj){
	
	return Fixed(static_cast<float>((arg_obj.getRawBits () >> this->_nbr_bits) / this->getRawBits()) / (1 << _nbr_bits));
}

bool				Fixed::operator>(const Fixed &arg_obj){
	
	return this->_nbr_val > arg_obj._nbr_val;
}

bool				Fixed::operator<(const Fixed &arg_obj){
	
	return this->_nbr_val < arg_obj._nbr_val;
}

bool				Fixed::operator>=(const Fixed &arg_obj){
	
	return this->_nbr_val >= arg_obj._nbr_val;
}

bool				Fixed::operator<=(const Fixed &arg_obj){
	
	return this->_nbr_val <= arg_obj._nbr_val;
}

bool				Fixed::operator==(const Fixed &arg_obj){
	
	return this->_nbr_val == arg_obj._nbr_val;
}

bool				Fixed::operator!=(const Fixed &arg_obj){
	
	return this->_nbr_val != arg_obj._nbr_val;
}

Fixed&				Fixed::operator++(void){

	this->_nbr_val += 1;
	return *this;
}

Fixed				Fixed::operator++(int){

	Fixed	tem(*this);
	++(*this);
	return tem;
}

Fixed&				Fixed::operator--(void){

	this->_nbr_val -= 1;
	return *this;
}

Fixed				Fixed::operator--(int){

	Fixed	tem(*this);
	--(*this);
	return tem;
}


Fixed&		Fixed::min(Fixed& o1, Fixed& o2){

	return o1.getRawBits() < o2.getRawBits () ? o1 : o2;
}

const Fixed&		Fixed::min(const Fixed& o1, const Fixed& o2){

	return o1.getRawBits() < o2.getRawBits () ? o1 : o2;
}

Fixed&		Fixed::max(Fixed& o1, Fixed& o2){

	return o1.getRawBits() > o2.getRawBits () ? o1 : o2;
}

const Fixed&		Fixed::max(const Fixed& o1, const Fixed& o2){

	return o1.getRawBits() > o2.getRawBits () ? o1 : o2;
}
