/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:19:05 by plichota          #+#    #+#             */
/*   Updated: 2026/02/02 17:21:35 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

#include <string>
#include <iostream>

class AForm
{
    private:
        const std::string name;
        bool isSigned; // always 0 at construction
        const int gradeToSign;
        const int gradeToExecute;

    protected:
        AForm();
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        AForm(const AForm & other);
        virtual void executeAction() const = 0;

    public:
        AForm &operator=(const AForm & other);
        virtual ~AForm();

        const std::string &getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool getIsSigned() const;

        // changes the form's status to signed if the bureaucrat's grade is high enough
        void beSigned(const Bureaucrat &bureaucrat); // Form::GradeTooLowException

        virtual void execute(Bureaucrat const &executor) const;

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
        class FormNotSignedException : public std::exception
        {
                public:
                    virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif