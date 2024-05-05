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
		//Fixed&				operator<<(const Fixed &arg_obj);
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		int					toInt(void) const;
		float				toFloat(void) const;
};

std::ostream& operator<<(std::ostream& out, Fixed const &obj);

#endif