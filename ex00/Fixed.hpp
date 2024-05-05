#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed{

	private:
		int					_nbr_val;
		static const int	_nbr_bits = 8;

	public:
							Fixed(void);
							~Fixed(void);
							Fixed(const Fixed &arg_obj);
		Fixed&				operator=(const Fixed &arg_obj);
		int					getRawBits(void) const;
		void				setRawBits(int const raw);

};
#endif