/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:10:23 by plichota          #+#    #+#             */
/*   Updated: 2026/01/30 21:19:43 by plichota         ###   ########.fr       */
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
        int grade; // from 0 to 100
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat & other);
        ~Bureaucrat();
        Bureaucrat & operator=(const Bureaucrat & other);
        std::string getName() const;
        int getGrade() const;

// attenzione 1 e' il piu' alto, quindi se aumento il grado devo fare --
        void incrementGrade(); // If the grade goes out of range, both functions must throw the same exceptions as the
// constructor.

        void decrementGrade(); // If the grade goes out of range, both functions must throw the same exceptions as the
// constructor.

        class GradeTooHighException : public std::exception
        {
                public:
                        const char* what() const noexcept override;
        };
        class GradeTooLowException : public std::exception
        {
                public:
                        const char* what() const noexcept override;
        };
};

// globale perche' usa streams
std::ostream &operator<<(std::ostream &stream, Bureaucrat const &bureaucrat);

#endif