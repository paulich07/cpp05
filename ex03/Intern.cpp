/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 22:30:59 by plichota          #+#    #+#             */
/*   Updated: 2026/02/02 23:05:28 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
    *this = other;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &other)
{
    (void) other;
    return *this;
}

// NO if else (subject)
// no switch (does not work with strings)
AForm* Intern::makeForm(std::string name, std::string target)
{
    int x = -1;

    const std::string names[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    int n = sizeof(names) / sizeof(names[0]);

    for (int i = 0; i < n; i++)
    {
        if (names[i] == name)
            x = i;
    }
    
    if (x == -1) // throw exception??
    {
        std::cout << MAGENTA << "Error: " << name << " does not exist" << RESET << std::endl;
        return NULL;
    }

    AForm *newForm = NULL;
    switch (x)
    {
        case 0:
            newForm = new ShrubberyCreationForm(target);
            break;
        case 1:
            newForm = new RobotomyRequestForm(target);
            break;
        case 2:
            newForm = new PresidentialPardonForm(target);
            break;
    }
    if (newForm != NULL)
        std::cout << GREEN << "Intern creates " << name << RESET << std::endl;
    return newForm;
}
