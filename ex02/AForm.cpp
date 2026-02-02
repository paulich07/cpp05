/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 23:45:18 by plichota          #+#    #+#             */
/*   Updated: 2026/02/02 16:43:36 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("default"), isSigned(false), gradeToSign(100), gradeToExecute(100)
{
}

// se il controllo fallisce lancia eccezione (oggetto non e' completamente costruito)
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToExecute > 150 || gradeToSign > 150)
    {
        throw AForm::GradeTooLowException();
    }
    else if (gradeToSign < 1 || gradeToExecute < 1)
    {
        throw AForm::GradeTooHighException();
    }
}

AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

AForm::~AForm()
{
}

// tutti gli altri sono const
AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

const std::string &AForm::getName() const
{
    return name;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw AForm::GradeTooLowException();
    else
        isSigned = true;
}

const char * AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

const char * AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char * AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
    out << AForm.getName() << ", isSigned: " << AForm.getIsSigned()
        << ", gradeToSign: " << AForm.getGradeToSign()
        << ", gradeToExecute: " << AForm.getGradeToExecute();
    return out;
}
