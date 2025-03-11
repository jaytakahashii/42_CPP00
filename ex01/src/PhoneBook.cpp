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
  std::cout << "Your PhoneBook is full." << std::endl;
  std::cout << "if you want to add a new contact, please delete an old one."
            << std::endl;
  std::cout << "Enter " RED "'yes'" RESET " to delete an old contact, or " GREEN
               "'no'" RESET " to cancel.\n"
            << std::endl;
}

int PhoneBook::askReplaceOldOne() {
  std::string input;

  std::cout << "yes/no: ";
  while (std::getline(std::cin, input)) {
    if (std::cin.eof())
      break;
    if (input == "yes") {
      for (int i = CONTACT_1; i <= CONTACT_7; i++)
        this->_contacts[i] = this->_contacts[i + 1];
      this->_full = false;
      this->_index--;
      std::cout << RED "Deleted oldest contact.\n" RESET << std::endl;
      return YES;
    } else if (input == "no") {
      return NO;
    }
    input.clear();
    std::cout << "yes/no: ";
  }
  return ERROR;
}

bool PhoneBook::setInfo() {
  int isReplace;

  if (this->_full) {
    putWarningPhonebookIsFull();
    isReplace = askReplaceOldOne();
    if (isReplace == ERROR) {
      return false;
    } else if (isReplace == NO) {
      std::cout << "Going back to main menu.\n" << std::endl;
      return true;
    }
  }
  std::cout << "Add contact #" << this->_index + 1 << std::endl;
  if (this->_contacts[this->_index].setContact()) {
    if (this->_index == CONTACT_8)
      this->_full = true;
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
  int index;

  if (input.length() != 1 || input < "0" || input > "8") {
    return false;
  }
  index = std::atoi(input.c_str());
  if (index > this->_index)
    return false;
  return true;
}

std::string PhoneBook::askIndex() const {
  std::string input;

  std::cout << YELLOW "-> " RESET;
  while (std::getline(std::cin, input)) {
    if (std::cin.eof())
      break;
    if (isValidIndex(input)) {
      if (input == EXIT) {
        return EXIT;
      }
      return input;
    }
    std::cout << YELLOW "-> " RESET;
  }
  return STR_ERROR;
}

void PhoneBook::promptForIndex() const {
  std::cout << "Please enter the Index of the contact you wish to display."
            << std::endl;
  std::cout << RED "If you enter 0, you will exit the search mode." RESET
            << std::endl;
}

bool PhoneBook::getInfo() const {
  std::string index;

  if (!this->_index) {
    std::cout << RED "Please add at least one contact before searching.\n" RESET
              << std::endl;
    return true;
  }
  std::cout << _index << " contacts in the PhoneBook." << std::endl;
  displayContactsHeader();
  for (int i = CONTACT_1; i < this->_index; i++)
    this->_contacts[i].showContactToTable(std::to_string(i + 1),
                                          this->_columnWidth);
  displayContactsFooter();
  promptForIndex();
  while (true) {
    index = askIndex();
    if (index == EXIT) {
      std::cout << "Exiting search mode now.\n" << std::endl;
      return true;
    } else if (index == STR_ERROR) {
      return false;
    }
    this->_contacts[std::atoi(index.c_str()) - 1].showDetails();
  }
}

void PhoneBook::showInstructions() const {
  std::cout << "Enter your command [ADD, SEARCH, EXIT]:" << std::endl;
  std::cout << YELLOW "$> " RESET;
}
