/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 21:09:08 by plichota          #+#    #+#             */
/*   Updated: 2026/02/02 13:56:50 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <string>

int main()
{
    Bureaucrat bureaucrat1("John", 1);
    Bureaucrat bureaucrat2("Cena", 100);
    Bureaucrat bureaucrat3("bureaucrat3", 150);

    {
        std::cout << YELLOW << "---- Shrubbery form: ----" << RESET << std::endl;
        ShrubberyCreationForm form1("form1");
        std::cout << form1 << std::endl;
    }
    {
        // non si puo'
        // AForm form1("form1", 50, 50);
    }
}