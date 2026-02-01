/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:19:05 by plichota          #+#    #+#             */
/*   Updated: 2026/02/01 22:58:29 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

#include <string>
#include <iostream>

class Form
{
    private:
        const std::string name;
        bool isSigned; // always 0 at construction
        const int gradeToSign;
        const int gradeToExecute;

    public:
        Form();
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(const Form & other);
        Form &operator=(const Form & other);
        ~Form();

        const std::string &getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool getIsSigned() const;

        // changes the form's status to signed if the bureaucrat's grade is high enough
        void beSigned(const Bureaucrat &bureaucrat); // Form::GradeTooLowException

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif