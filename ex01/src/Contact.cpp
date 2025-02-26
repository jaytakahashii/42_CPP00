/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jay <jay@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 22:50:06 by jay               #+#    #+#             */
/*   Updated: 2025/02/26 16:53:08 by jay              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#include "color.hpp"

std::string Contact::_fields[5] = {"First Name", "Last Name", "Nickname",
                                   "Phone Number", "Darkest Secret"};

Contact::Contact() {
  for (int i = FIRST_NAME; i <= DARKEST_SECRET; i++)
    this->_info[i] = std::string();
};

Contact::~Contact() {};

bool Contact::setContact() {
  for (int i = FIRST_NAME; i <= DARKEST_SECRET; i++) {
    std::cout << Contact::_fields[i] << ": ";
    while (!std::getline(std::cin, this->_info[i])) {
      if (std::cin.eof() == true)
        return false;
      if (this->_info[i].length() == 0) {
        this->_info[i].clear();
        std::cout << RED "Empty contact information not allowed." RESET
                  << std::endl;
        std::cout << Contact::_fields[i] << ": ";
      }
    }
    if (std::cin.eof() == true)
      return false;
  }
  std::cout << GREEN "Contact added successfully.\n" RESET << std::endl;
  return (true);
}

std::string centerAlign(const std::string& text, int width) {
  if (int(text.length()) >= width)
    return text.substr(0, width);
  int padding = width - text.length();
  int leftPadding = padding / 2;
  int rightPadding = padding - leftPadding;
  return std::string(leftPadding, ' ') + text + std::string(rightPadding, ' ');
}

void Contact::getContact(std::string index, int columnWidth) const {
  std::cout << "|";
  std::cout << centerAlign(index, columnWidth);
  for (int i = FIRST_NAME; i <= NICKNAME; i++) {
    std::cout << "|";
    if (int(this->_info[i].length()) > columnWidth) {
      std::cout << centerAlign(this->_info[i].substr(0, columnWidth - 1) + ".",
                               columnWidth);
    } else {
      std::cout << centerAlign(this->_info[i], columnWidth);
    }
  }
  std::cout << "|" << std::endl;
}
