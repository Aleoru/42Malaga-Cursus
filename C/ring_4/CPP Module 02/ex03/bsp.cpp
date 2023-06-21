/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 20:10:53 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/16 20:10:53 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	triangleOrientation(Point const p1, Point const p2, Point const p3){

	if ((p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) - (p2.getY() - p1.getY()) * (p3.getX() - p1.getX()) > 0)
		return (true);
	else
		return (false);

}

bool	bsp(Point const a, Point const b, Point const c, Point const point){

	bool	ori1 = triangleOrientation(point, a, b);
	bool	ori2 = triangleOrientation(point, b, c);
	bool	ori3 = triangleOrientation(point, c, a);

	if (ori1 && ori2 && ori3)
		return (true);
	else
		return (false);
}
