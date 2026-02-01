/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 20:05:38 by plichota          #+#    #+#             */
/*   Updated: 2026/02/01 22:35:38 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default"), isSigned(false), gradeToSign(100), gradeToExecute(100)
{
}

// se il controllo fallisce lancia eccezione (oggetto non e' completamente costruito)
Form::Form(std::string name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToExecute > 150 || gradeToSign > 150)
    {
        throw Form::GradeTooLowException();
    }
    else if (gradeToSign < 1 || gradeToExecute < 1)
    {
        throw Form::GradeTooHighException();
    }
}

Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

Form::~Form()
{
}

// tutti gli altri sono const
Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

const std::string &Form::getName() const
{
    return name;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= gradeToSign)
        isSigned = true;
    else
        throw Form::GradeTooLowException();
}

void Form::signForm(const Bureaucrat &bureaucrat)
{
    try
    {
        beSigned(bureaucrat);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << form.getName() << ", isSigned: " << form.getIsSigned()
        << ", gradeToSign: " << form.getGradeToSign()
        << ", gradeToExecute: " << form.getGradeToExecute();
    return out;
}
