/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 22:30:59 by plichota          #+#    #+#             */
/*   Updated: 2026/02/02 22:37:51 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other) : Intern()
{
    (void)other;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &other)
{
    (void) other;
    return *this;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    AForm *form = new AForm(name, )
}