#pragma once

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

class Contact {
 private:
  static std::string _fields[5];
  std::string _info[5];

  enum Field {
    FIRST_NAME = 0,
    LAST_NAME,
    NICKNAME,
    PHONE_NUMBER,
    DARKEST_SECRET
  };

 public:
  Contact();
  ~Contact();

  bool setContact();
  void showContactToTable(std::string index, int columnWidth) const;
  void showDetails() const;
};
