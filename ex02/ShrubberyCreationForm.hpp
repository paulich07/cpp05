/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 23:46:24 by plichota          #+#    #+#             */
/*   Updated: 2026/02/01 23:53:27 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

// Required grades: sign 145, exec 137
// Creates a file <target>_shrubbery in the working directory and writes ASCII trees
// inside it.
class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm(); // sign 145, exec 137
        ShrubberyCreationForm(std::string target); // ex home
        ShrubberyCreationForm(const ShrubberyCreationForm & other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm & other);
        ~ShrubberyCreationForm();

        const std::string &getTarget() const;
        virtual void execute(Bureaucrat const &executor) const;
};

#endif