#pragma once

#include <iostream>

#include "Contact.hpp"

const int ERROR = -1;
const int YES = 1;
const int NO = 0;

const std::string EXIT = "0";
const std::string STR_ERROR = "error";

class PhoneBook {
 private:
  Contact _contacts[8];
  int _columnWidth;
  int _index;
  bool _full;

  enum addressNum {
    CONTACT_1 = 0,
    CONTACT_2,
    CONTACT_3,
    CONTACT_4,
    CONTACT_5,
    CONTACT_6,
    CONTACT_7,
    CONTACT_8
  };

 public:
  PhoneBook();
  ~PhoneBook();

  bool setInfo();
  bool getInfo() const;
  void showInstructions() const;
  int askReplaceOldOne();
  void putWarningPhonebookIsFull() const;
  bool isValidIndex(const std::string& input) const;
  void promptForIndex() const;
  std::string askIndex() const;
};
