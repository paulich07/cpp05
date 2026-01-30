/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:10:23 by plichota          #+#    #+#             */
/*   Updated: 2026/01/30 21:29:21 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

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
        const std::string &getName() const;
        int getGrade() const;

        void incrementGrade(); // throw the same exceptions as the constructor
        void decrementGrade(); // throw the same exceptions as the constructor

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