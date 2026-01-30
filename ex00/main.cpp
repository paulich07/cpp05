/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 21:09:08 by plichota          #+#    #+#             */
/*   Updated: 2026/01/30 21:26:59 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat bureaucrat("John", 100);
    Bureaucrat bureaucrat2("Cena", 150);

    std::cout << bureaucrat << std::endl;
    std::cout << bureaucrat2 << std::endl;

    try
    {
        bureaucrat.decrementGrade();
        bureaucrat2.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}