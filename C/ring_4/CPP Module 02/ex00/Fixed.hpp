/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:35:23 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/14 14:35:26 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

	public:

		Fixed(void);
		Fixed(Fixed const & src);
		~Fixed(void);
		Fixed & operator=(Fixed const & rhs);

		int		getRawBits() const;
		void	setRawBits(int const raw);

	private:

		int	_n;
		static const int _bits;

};

#endif
