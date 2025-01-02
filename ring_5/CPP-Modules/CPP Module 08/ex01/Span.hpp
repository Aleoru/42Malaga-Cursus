/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:46:50 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/03 19:19:09 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class	Span {

	private:
		unsigned int		_N;
		std::vector<int>	_nums;
		Span(void);

	public:
		Span(unsigned int N);
		Span(Span &src);
		~Span(void);

		Span	&operator=(Span const &rhs);

		void	addNumber(int num);

};

#endif