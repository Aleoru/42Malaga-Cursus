/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:51:06 by aoropeza          #+#    #+#             */
/*   Updated: 2023/12/23 18:51:07 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void) {

    Base    *something;

    something = Base::generate();
    Base    &another = *something;

    Base::identify(something);
    Base::identify(another);

    return (0);

}