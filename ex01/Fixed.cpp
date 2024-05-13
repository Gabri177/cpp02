/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 02:41:10 by yugao             #+#    #+#             */
/*   Updated: 2024/05/13 02:41:11 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed (void): _nbr_val(0) {

	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed (void) {

	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &arg_obj){

	std::cout << "Copy constructor called" << std::endl;
	//this->setRawBits (arg_obj.getRawBits());
	*this = arg_obj;
}

Fixed&	Fixed::operator=(const Fixed &arg_obj){

	std::cout << "Copy assignment operator called" << std::endl;
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

	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num): _nbr_val(roundf(num * (1 << _nbr_bits))){

	std::cout << "Float constructor called" << std::endl;
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