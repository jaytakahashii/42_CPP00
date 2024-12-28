/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jay <jay@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:04:53 by jay               #+#    #+#             */
/*   Updated: 2024/12/28 20:34:40 by jay              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "color.hpp"

int main(void) {
  PhoneBook PhoneBook;
  bool eof = true;
  std::string command;

  PhoneBook.showInstructions();
  while (std::getline(std::cin, command)) {
    if (std::cin.eof() == true) {
      break;
    } else if (command == "ADD") {
      if (!PhoneBook.setInfo())
        break;
    } else if (command == "SEARCH") {
      PhoneBook.getInfo();
    } else if (command == "EXIT") {
      eof = false;
      break;
    }
    command.clear();
    PhoneBook.showInstructions();
  }
  if (eof) {
    std::cout << std::endl;
    std::cout << RED "You pressed ^D, exiting now." RESET << std::endl;
  }
  return (0);
}
