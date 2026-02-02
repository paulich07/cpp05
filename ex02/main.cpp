/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 21:09:08 by plichota          #+#    #+#             */
/*   Updated: 2026/02/02 22:25:56 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <string>

int main()
{
    Bureaucrat bureaucrat1("President", 1);
    Bureaucrat bureaucrat2("John Cena", 100);
    Bureaucrat bureaucrat3("dummy bureaucrat", 150);

    ShrubberyCreationForm form1("form1");
    ShrubberyCreationForm signedForm("signedForm");
    bureaucrat1.signForm(signedForm);

    RobotomyRequestForm roboform("roboform");
    
    PresidentialPardonForm pardonForm("pardonForm");
    
    // non si puo'
    // AForm form1("form1", 50, 50);
    {
        std::cout << YELLOW << "---- Shrubbery form creation ----" << RESET << std::endl;
        std::cout << form1 << std::endl;
    }
    {
        std::cout << YELLOW << "---- Shrubbery form copy and execution ----" << RESET << std::endl;
        ShrubberyCreationForm form2(form1);
        std::cout << form2 << std::endl;
        bureaucrat3.signForm(form2); // exception
        bureaucrat2.signForm(form2);
        std::cout << form2 << std::endl;
    }
    {
        std::cout << YELLOW << "---- Shrubbery form execution: not signed ----" << RESET << std::endl;
        std::cout << form1 << std::endl;
        ShrubberyCreationForm form(form1);
        try
        {
            form.execute(bureaucrat2);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        bureaucrat1.signForm(form);
        try
        {
            form.execute(bureaucrat2);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    {
        std::cout << YELLOW << "---- Shrubbery form execution: low grade ----" << RESET << std::endl;
        std::cout << signedForm << std::endl;
        try
        {
            signedForm.execute(bureaucrat3);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        signedForm.execute(bureaucrat2);
    }
    {
        std::cout << YELLOW << "---- Shrubbery form execution: success ----" << RESET << std::endl;
        std::cout << form1 << std::endl;
        try
        {
            form1.execute(bureaucrat2);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        bureaucrat1.signForm(form1);
        form1.execute(bureaucrat2);
    }
    {
        std::cout << YELLOW << "---- Shrubbery bureaucrat execution ----" << RESET << std::endl;
        std::cout << form1 << std::endl;
        bureaucrat3.executeForm(form1);
        bureaucrat2.executeForm(form1);
    }
    {
        std::cout << YELLOW << "---- Shrubbery form execution: success ----" << RESET << std::endl;
        std::cout << form1 << std::endl;
        try
        {
            form1.execute(bureaucrat2);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        bureaucrat1.signForm(form1);
        form1.execute(bureaucrat2);
    }
    {
        std::cout << YELLOW << "---- Shrubbery bureaucrat execution ----" << RESET << std::endl;
        std::cout << form1 << std::endl;
        bureaucrat3.executeForm(form1);
        bureaucrat2.executeForm(form1);
    }
    {
        std::cout << YELLOW << "---- Robotomy form execution: success ----" << RESET << std::endl;
        std::cout << roboform << std::endl;
        
        bureaucrat2.executeForm(roboform);
        bureaucrat2.signForm(roboform);
        bureaucrat1.executeForm(roboform);
        bureaucrat1.signForm(roboform);
        bureaucrat1.executeForm(roboform);
    }
    {
        std::cout << YELLOW << "---- Pardon form execution: success ----" << RESET << std::endl;
        std::cout << pardonForm << std::endl;
        
        bureaucrat2.executeForm(pardonForm);
        bureaucrat2.signForm(pardonForm);
        bureaucrat1.executeForm(pardonForm);
        bureaucrat1.signForm(pardonForm);
        bureaucrat1.executeForm(pardonForm);
    }
}