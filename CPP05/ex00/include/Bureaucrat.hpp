/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:05:56 by victorviter       #+#    #+#             */
/*   Updated: 2025/07/30 10:05:58 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



class Bureaucrat {
    public :
        Bureaucrat();
        Bureaucrat(std::string name, unsigned int grade);
        Bureaucrat(Bureaucrat &other);
        Bureaucrat &operator=(Bureaucrat &other);
        Bureaucrat();

}