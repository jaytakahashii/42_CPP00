#include "PhoneBook.hpp"
#include "color.hpp"

int main(void) {
  PhoneBook PhoneBook;
  bool eof = true;
  std::string command;

  PhoneBook.showInstructions();
  while (std::getline(std::cin, command)) {
    if (std::cin.eof()) {
      break;
    } else if (command == "ADD") {
      if (!PhoneBook.setInfo())
        break;
    } else if (command == "SEARCH") {
      if (!PhoneBook.getInfo())
        break;
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
