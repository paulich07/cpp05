/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:07:38 by plichota          #+#    #+#             */
/*   Updated: 2026/01/30 21:29:29 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(100)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    if (grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    else if (grade < 1)
    {
        throw Bureaucrat::GradeTooHighException(); 
    }
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        // this->name = other.name; // const non modificabile
        this->grade = other.grade;
    }
    return *this;
}

const std::string &Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
    return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &bureaucrat)
{
    stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return stream;
}