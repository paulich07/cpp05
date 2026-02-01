/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:19:05 by plichota          #+#    #+#             */
/*   Updated: 2026/02/01 20:05:08 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

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

        std::string getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool getIsSigned() const;

        // changes the form's status to signed if the bureaucrat's grade is high enough
        void beSigned(const Bureaucrat &bureaucrat); // Form::GradeTooLowException
        // call Form:beSigned to attempt sign the form, print if succeed
        void signForm(const Bureaucrat &bureaucrat);

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