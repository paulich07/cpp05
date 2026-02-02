/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 21:09:08 by plichota          #+#    #+#             */
/*   Updated: 2026/02/02 22:44:16 by plichota         ###   ########.fr       */
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

    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    }
    {
        Intern someRandomIntern;
        AForm* scf;
        scf = someRandomIntern.makeForm("shrubbery creation", "Home");
    }
    {
        Intern someRandomIntern;
        AForm* ppf;
        ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    }
    {
        Intern someRandomIntern;
        AForm* unknown;
        unknown = someRandomIntern.makeForm("unknown form", "Nobody");
    }
}
