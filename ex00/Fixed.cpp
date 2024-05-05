#include "Fixed.hpp"

Fixed::Fixed (void): _nbr_val(0) {

	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed (void) {

	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &arg_obj){

	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits (arg_obj.getRawBits());
}

Fixed&	Fixed::operator=(const Fixed &arg_obj){

	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &arg_obj)
		this->_nbr_val = arg_obj.getRawBits ();
	return *this;
}

int		Fixed::getRawBits(void) const {

	std::cout << "getRawBits member function called" << std::endl;
	return _nbr_val;
}

void		Fixed::setRawBits(int const raw){

	_nbr_val = raw;
}