/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 02:43:01 by yugao             #+#    #+#             */
/*   Updated: 2024/05/13 02:43:02 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed{

	private:
		int					_nbr_val;
		static const int	_nbr_bits = 8;

	public:
							Fixed(void);
							Fixed(const int num);
							Fixed(const float num);
							~Fixed(void);
							Fixed(const Fixed &arg_obj);
		Fixed&				operator=(const Fixed &arg_obj);
		Fixed 				operator+(const Fixed &arg_obj);
		Fixed				operator-(const Fixed &arg_obj);
		Fixed				operator*(const Fixed &arg_obj);
		Fixed				operator/(const Fixed &arg_obj);
		bool				operator>(const Fixed &arg_obj);
		bool				operator<(const Fixed &arg_obj);
		bool				operator>=(const Fixed &arg_obj);
		bool				operator<=(const Fixed &arg_obj);
		bool				operator==(const Fixed &arg_obj);
		bool				operator!=(const Fixed &arg_obj);
		Fixed&				operator++(void);
		Fixed				operator++(int);
		Fixed&				operator--(void);
		Fixed				operator--(int);
		//Fixed&				operator<<(const Fixed &arg_obj);
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		int					toInt(void) const;
		float				toFloat(void) const;
		static Fixed&		min(Fixed& o1, Fixed& o2);
		static const Fixed&	min(const Fixed& o1, const Fixed& o2);
		static Fixed&		max(Fixed& o1, Fixed& o2);
		static const Fixed&	max(const Fixed& o1, const Fixed& o2);


};

std::ostream& operator<<(std::ostream& out, Fixed const &obj);

#endif