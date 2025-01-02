/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:47:05 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/16 19:47:05 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <cmath>

class Point {

	private:

		Fixed const _x;
		Fixed const _y;

	public:

		Point(void);
		Point(Point	const &src);
		Point(float const x, float const y);
		~Point(void);

		Point & operator=(Point const &rhs);
		Fixed	getX() const;
		Fixed	getY() const;
		void	setX(Fixed const x);
		void	setY(Fixed const y);

};

std::ostream & operator<<(std::ostream & o, Point const & rhs);

#endif