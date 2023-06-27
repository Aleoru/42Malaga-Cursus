/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:36:36 by aoropeza          #+#    #+#             */
/*   Updated: 2023/06/27 22:36:36 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource{

	private:
		AMateria	*materias[4];

	public:
		MateriaSource();
		MateriaSource(MateriaSource const &src);
		~MateriaSource();

		MateriaSource & operator=(MateriaSource const &rhs);

		AMateria*		getMateria(std::string const &type);
		AMateria*		createMateria(std::string const &type);
		void			learnMateria(AMateria *m);
		
};

#endif