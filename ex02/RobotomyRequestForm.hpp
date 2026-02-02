/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 21:05:58 by plichota          #+#    #+#             */
/*   Updated: 2026/02/02 21:08:23 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
    protected:
        virtual void executeAction() const; // virtual opzionale qui
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm & other);
        RobotomyRequestForm &operator=(const RobotomyRequestForm & other);
        ~RobotomyRequestForm();

        const std::string &getTarget() const;
        // virtual void execute(Bureaucrat const &executor) const; // prende quello di AForm
};
    
#endif