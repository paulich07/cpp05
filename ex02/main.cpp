/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 21:09:08 by plichota          #+#    #+#             */
/*   Updated: 2026/02/01 23:44:43 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <iostream>
#include <string>

int main()
{
    Bureaucrat bureaucrat1("John", 1);
    Bureaucrat bureaucrat2("Cena", 100);
    Bureaucrat bureaucrat3("bureaucrat3", 150);

    Form form1("form1", 50, 50);
    Form form2("form2", 10, 10);

    {
        std::cout << YELLOW << "---- Operator << test ----" << RESET << std::endl; 
        std::cout << form1 << std::endl;
    }
    {
        std::cout << YELLOW << "---- Operator = test (isSigned only) ----" << RESET << std::endl;
        Form form3("form3", 10, 10);
        form3.beSigned(bureaucrat1);
        form3 = form1;
        std::cout << form1 << std::endl;
        std::cout << form3 << std::endl;
    }
    {
        std::cout << YELLOW << "---- Exception test: create form ----" << RESET << std::endl;
        try
        {
            // too low
            Form form3("form3", 10, 160);
            // too high
            // Form form4("form3", 1, -1);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    {
        Form form3(form1);
        std::cout << YELLOW << "---- Sign form ----" << RESET << std::endl;
        std::cout << form3 << std::endl;
        form3.beSigned(bureaucrat1);
        std::cout << form3 << std::endl;
    }
    {
        std::cout << YELLOW << "---- Bureaucrat signs form ----" << RESET << std::endl;
        std::cout << form1 << std::endl;
        bureaucrat1.signForm(form1);
        std::cout << form1 << std::endl;
    }
    {
        std::cout << YELLOW << "---- Bureaucrat signs form: failure ----" << RESET << std::endl;
        std::cout << form2 << std::endl;
        bureaucrat2.signForm(form2);
        std::cout << form2 << std::endl;
        bureaucrat1.signForm(form2);
        std::cout << form2 << std::endl;
    }
}