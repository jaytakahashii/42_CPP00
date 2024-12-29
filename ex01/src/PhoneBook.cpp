/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jay <jay@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:46:03 by jay               #+#    #+#             */
/*   Updated: 2024/12/29 15:49:03 by jay              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include "color.hpp"

PhoneBook::PhoneBook(void) {
  this->_index = 0;
  this->_full = false;
  this->_columnWidth = 10;
  std::cout << std::endl;
  // clang-format off
  std::cout << BLUE "d8888b. db   db  .d88b.  d8b   db d88888b d8888b.  .d88b.   .d88b.  db   dD "       << std::endl;
  std::cout <<      "88  `8D 88   88 .8P  Y8. 888o  88 88'     88  `8D .8P  Y8. .8P  Y8. 88 ,8P' "       << std::endl;
  std::cout <<      "88oodD' 88ooo88 88    88 88V8o 88 88ooooo 88oooY' 88    88 88    88 88,8P   "       << std::endl;
  std::cout <<      "88~~~   88~~~88 88    88 88 V8o88 88~~~~~ 88~~~b. 88    88 88    88 88`8b   "       << std::endl;
  std::cout <<      "88      88   88 `8b  d8' 88  V888 88.     88   8D `8b  d8' `8b  d8' 88 `88. "       << std::endl;
  std::cout <<      "88      YP   YP  `Y88P'  VP   V8P Y88888P Y8888P'  `Y88P'   `Y88P'  YP   YD " RESET << std::endl;
  // clang-format on
  std::cout << std::endl;
}

PhoneBook::~PhoneBook(void) {
  std::cout << std::endl;
  // clang-format off
  std::cout << BLUE " d888b   .d88b.   .d88b.  d8888b.   d8888b. db    db d88888b "       << std::endl;
  std::cout <<      "88' Y8b .8P  Y8. .8P  Y8. 88  `8D   88  `8D `8b  d8' 88'     "       << std::endl;
  std::cout <<      "88      88    88 88    88 88   88   88oooY'  `8bd8'  88ooooo "       << std::endl;
  std::cout <<      "88  ooo 88    88 88    88 88   88   88~~~b.    88    88~~~~~ "       << std::endl;
  std::cout <<      "88. ~8~ `8b  d8' `8b  d8' 88  .8D   88   8D    88    88.     "       << std::endl;
  std::cout <<      " Y888P   `Y88P'   `Y88P'  Y8888D'   Y8888P'    YP    Y88888P " RESET << std::endl;
  // clang-format on
  std::cout << std::endl;
}

void PhoneBook::putWarningPhonebookIsFull() const {
  std::cout << std::endl;
  std::cout << RED "WARNING" RESET << std::endl;
  std::cout << "Your PHONEBOOK is full." << std::endl;
  std::cout << "if you want to add a new contact, please delete an old one"
            << std::endl;
  std::cout << "Enter " RED "'yes'" RESET " to delete an old contact, or " GREEN
               "'no'" RESET " to cancel.\n"
            << std::endl;
}

std::string PhoneBook::askReplaceOldOne() {
  std::string input;

  std::cout << "yes/no: ";
  while (std::getline(std::cin, input)) {
    if (std::cin.eof())
      break;
    if (input == "yes") {
      for (int i = CONTACT_FIRST; i < CONTACT_LAST - 1; i++)
        this->_contacts[i] = this->_contacts[i + 1];
      this->_index = CONTACT_LAST - 1;
      this->_full = false;
      std::cout << RED "Deleted oldest contact.\n" RESET << std::endl;
      return STR_YES;
    } else if (input == "no") {
      return STR_NO;
    }
    input.clear();
    std::cout << "yes/no: ";
  }
  return STR_ERROR;
}

bool PhoneBook::setInfo() {
  std::string isReplace;

  if (this->_full) {
    putWarningPhonebookIsFull();
    isReplace = askReplaceOldOne();
    if (isReplace == STR_ERROR) {
      return false;
    } else if (isReplace == STR_NO) {
      std::cout << "Going back to main menu.\n" << std::endl;
      return true;
    }
  }
  std::cout << "Add contact #" << this->_index + 1 << std::endl;
  if (this->_contacts[this->_index].setContact()) {
    if (this->_index == 7)
      this->_full = true;
    else
      this->_index++;
  } else {
    return false;
  }
  return true;
}

static void displayContactsHeader() {
  std::cout << "|-------------------------------------------|" << std::endl;
  std::cout << "|  Index   |First Name|Last Name | Nickname |" << std::endl;
  std::cout << "|----------|----------|----------|----------|" << std::endl;
}

static void displayContactsFooter() {
  std::cout << "|-------------------------------------------|\n" << std::endl;
}

bool PhoneBook::isValidIndex(const std::string& input) const {
  if (input.length() != 1 || input < "0" || input > "8") {
    return false;
  }
  int index = std::atoi(input.c_str());
  if (index <= this->_index + 1)
    return true;
  return false;
}

std::string PhoneBook::askIndex() const {
  std::string input;

  std::cout << YELLOW "index: " << "(0~" << this->_index << ")" RESET
            << std::endl;
  while (std::getline(std::cin, input)) {
    if (std::cin.eof())
      break;
    if (isValidIndex(input)) {
      if (input == EXIT) {
        return EXIT;
      }
      return input;
    }
    std::cout << YELLOW "index: " << "(0~" << this->_index << ")" RESET
              << std::endl;
  }
  return ERROR;
}

std::string PhoneBook::promptForIndex() const {
  std::string answeredIndex;

  std::cout << "Please enter the Index of the contact you wish to display "
            << "(0~" << this->_index << ")" << std::endl;
  std::cout << "If you enter 0, you will exit the search mode." << std::endl;
  return askIndex();
}

bool PhoneBook::getInfo() const {
  std::string index;

  if (!this->_index) {
    std::cout << RED "Please add at least one contact before searching.\n" RESET
              << std::endl;
    return true;
  }
  index = promptForIndex();
  if (index == EXIT) {
    std::cout << "Exiting search mode now.\n" << std::endl;
    return true;
  } else if (index == ERROR) {
    return false;
  }
  displayContactsHeader();
  this->_contacts[std::atoi(index.c_str()) - 1].getContact(index,
                                                           this->_columnWidth);
  displayContactsFooter();
  return true;
}

void PhoneBook::showInstructions() const {
  std::cout << "Enter your command [ADD, SEARCH, EXIT]:" << std::endl;
  std::cout << YELLOW "$> " RESET;
}
