/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:10:23 by plichota          #+#    #+#             */
/*   Updated: 2026/01/29 22:14:20 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

//  Bureaucrat::G radeTooHighException or a Bureaucrat::GradeTooLowException.
// use try catch

// try
// {
// /* do some stuff with bureaucrats */
// }
// catch (std::exception & e)
// {
// /* handle exception */
// }

class Bureaucrat
{
    private:
        const std::string name;
        unsigned int grade; // from 0 to 100
    public:
        getName();
        getGrade();

// attenzione 1 e' il piu' alto, quindi se aumento il grado devo fare --
        incrementGrade(); // If the grade goes out of range, both functions must throw the same exceptions as the
// constructor.

        decrementGrade(); // If the grade goes out of range, both functions must throw the same exceptions as the
// constructor.
        // overload insertion << 
        // OUTPUT LIKE THIS <name>, bureaucrat grade <grade>

};

#endif