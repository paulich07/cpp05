/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 21:09:08 by plichota          #+#    #+#             */
/*   Updated: 2026/02/02 23:20:15 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <string>

int main()
{
    Bureaucrat bureaucrat1("President", 1);
    Bureaucrat bureaucrat2("John Cena", 100);
    Bureaucrat bureaucrat3("dummy bureaucrat", 150);

    Intern someRandomIntern;
    {
        std::cout << YELLOW << "---- Intern creates robotomy: success ----" << RESET << std::endl;
        AForm* form = someRandomIntern.makeForm("robotomy request", "Bender");
        if (form)
        {
            bureaucrat1.signForm(*form);
            bureaucrat1.executeForm(*form);
        }
        delete form;
    }
    {
        std::cout << YELLOW << "---- Intern creates shrubbery: success ----" << RESET << std::endl;
        AForm* form = someRandomIntern.makeForm("shrubbery creation", "Home");
        if (form)
        {
            bureaucrat1.signForm(*form);
            bureaucrat1.executeForm(*form);
        }
        delete form;
    }
    {
        std::cout << YELLOW << "---- Intern creates presidential: success ----" << RESET << std::endl;
        AForm* form = someRandomIntern.makeForm("presidential pardon", "Pres");
        if (form)
        {
            bureaucrat1.signForm(*form);
            bureaucrat1.executeForm(*form);
        }
        delete form;
    }
    {
        std::cout << YELLOW << "---- Intern creates unknown: fail ----" << RESET << std::endl;
        AForm* form = someRandomIntern.makeForm("unknown", "Random");
        if (form)
        {
            bureaucrat1.signForm(*form);
            bureaucrat1.executeForm(*form);
        }
        delete form;
    }
}
