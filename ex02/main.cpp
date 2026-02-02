/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 21:09:08 by plichota          #+#    #+#             */
/*   Updated: 2026/02/02 14:09:54 by plichota         ###   ########.fr       */
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

    ShrubberyCreationForm form1("form1");
    
    // non si puo'
    // AForm form1("form1", 50, 50);

    {
        std::cout << YELLOW << "---- Shrubbery form creation ----" << RESET << std::endl;
        std::cout << form1 << std::endl;
    }
    {
        std::cout << YELLOW << "---- Shrubbery form copy and execution ----" << RESET << std::endl;
        ShrubberyCreationForm form2(form1);
        std::cout << form2 << std::endl;
        bureaucrat3.signForm(form2); // exception
        bureaucrat2.signForm(form2);
        std::cout << form2 << std::endl;
    }
}