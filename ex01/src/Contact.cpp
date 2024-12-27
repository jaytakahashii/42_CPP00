/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jay <jay@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 22:50:06 by jay               #+#    #+#             */
/*   Updated: 2024/12/27 23:51:11 by jay              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::_fields[5] = {"First Name", "Last Name", "Nickname",
                                   "Phone Number", "Darkest Secret"};

Contact::Contact() {
  for (int i = FIRST_NAME; i <= DARKEST_SECRET; i++)
    this->_info[i] = std::string();
};

Contact::~Contact() {};

bool Contact::setContact() {
  for (int i = FIRST_NAME; i <= DARKEST_SECRET; i++) {
    std::cout << "Please enter the " << Contact::_fields[i] << ":\n+";
    while (!(std::getline(std::cin, this->_info[i])) ||
           this->_info[i].length() == 0) {
      if (std::cin.eof() == true) {
        std::cout << "You Pressed ^D. Exiting phonebook now." << std::endl;
        std::exit(0);
      } else if (this->_info[i].length() == 0) {
        this->_info[i].clear();
        std::cout << "\033[31mEmpty contact information not allowed.\033[0m"
                  << std::endl;
        std::cout << "Please enter the " << Contact::_fields[i] << ":\n+";
      }
    }
  }
  std::cout << "\033[32mContact added successfully.\033[0m" << std::endl;
  return (true);
}

bool Contact::getContact(int index) const {
  std::cout << std::setw(10) << index;
  for (int i = FIRST_NAME; i <= DARKEST_SECRET; i++) {
    std::cout << "|";
    if (this->_info[i].length() > 10)
      std::cout << this->_info[i].substr(0, 9) << ".";
    else
      std::cout << std::setw(10) << this->_info[i];
  }
  std::cout << "|" << std::endl;
}
