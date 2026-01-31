/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:10:23 by plichota          #+#    #+#             */
/*   Updated: 2026/01/30 21:43:39 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

# define GREEN   	"\033[0;32m"
# define YELLOW  	"\033[0;33m"
# define BLUE    	"\033[0;34m"
# define MAGENTA 	"\033[0;35m"
# define RESET   	"\033[0m"

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
                        virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
                public:
                        virtual const char* what() const throw();
        };
};

// globale perche' usa streams
std::ostream &operator<<(std::ostream &stream, Bureaucrat const &bureaucrat);

#endif