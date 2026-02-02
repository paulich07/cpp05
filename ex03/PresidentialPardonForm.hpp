/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 22:21:11 by plichota          #+#    #+#             */
/*   Updated: 2026/02/02 22:26:28 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    protected:
        virtual void executeAction() const; // virtual opzionale qui
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm & other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm & other);
        ~PresidentialPardonForm();
        const std::string &getTarget() const;
        // virtual void execute(Bureaucrat const &executor) const; // prende quello di AForm
};

#endif