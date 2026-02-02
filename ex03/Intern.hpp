/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 22:28:39 by plichota          #+#    #+#             */
/*   Updated: 2026/02/02 22:58:08 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include <iostream>

class Intern
{
    public:
        Intern();
        Intern(const Intern & other);
        ~Intern();
        Intern &operator=(const Intern & other);

        AForm* makeForm(std::string name, std::string target);
};

#endif