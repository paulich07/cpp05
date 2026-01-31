/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 21:09:08 by plichota          #+#    #+#             */
/*   Updated: 2026/01/30 21:56:29 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    
    Bureaucrat bureaucrat("John", 100);
    Bureaucrat bureaucrat2("Cena", 150);
    Bureaucrat bureaucrat3("Mangio", 1);

    {
        std::cout << YELLOW << "---- Operator << overflow test ----" << RESET << std::endl;
        std::cout << bureaucrat << std::endl;
        std::cout << bureaucrat2 << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << YELLOW << "---- Exception test: create bureaucrat ----" << RESET << std::endl;
        try
        {
            Bureaucrat bureaucrat4("John", 160);
        }
        catch(const std::exception& e)
        {
        std::cerr << MAGENTA << e.what() << RESET << '\n';
        }
        try
        {
            Bureaucrat bureaucrat4("John", 0);
        }
        catch(const std::exception& e)
        {
            std::cerr << MAGENTA << e.what() << RESET << '\n';
        }
        std::cout << std::endl;
    }
    {
        std::cout << YELLOW << "---- Exception test: increment grades ----" << RESET << std::endl;
        try
        {
            bureaucrat.decrementGrade();
            bureaucrat2.decrementGrade();
        }
        catch(const std::exception& e)
        {
            std::cerr << MAGENTA << e.what() << RESET << '\n';
        }
        std::cout << std::endl;
    }
    {
        std::cout << YELLOW << "---- Duplicate test: ----" << RESET << std::endl;
        Bureaucrat bureaucrat4(bureaucrat);
        std::cout << "new " << bureaucrat4 << std::endl;
        std::cout << "old " << bureaucrat << std::endl;
        bureaucrat4.incrementGrade();
        std::cout << "new " << bureaucrat4 << std::endl;
        std::cout << "old " << bureaucrat << std::endl;
        std::cout << std::endl;
    }

}