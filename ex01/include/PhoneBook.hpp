/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jay <jay@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:05:41 by jay               #+#    #+#             */
/*   Updated: 2024/12/29 15:47:01 by jay              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "Contact.hpp"

#define ERROR "-1"
#define EXIT "0"

#define STR_YES "yes"
#define STR_NO "no"
#define STR_ERROR "error"

class PhoneBook {
 private:
  Contact _contacts[8];
  int _columnWidth;
  int _index;
  bool _full;

  enum addressNum {
    CONTACT_FIRST = 0,
    CONTACT_2,
    CONTACT_3,
    CONTACT_4,
    CONTACT_5,
    CONTACT_6,
    CONTACT_7,
    CONTACT_LAST
  };

 public:
  PhoneBook();
  ~PhoneBook();

  bool setInfo();
  std::string askReplaceOldOne();
  void putWarningPhonebookIsFull() const;
  bool isValidIndex(const std::string& input) const;
  std::string promptForIndex() const;
  bool getInfo() const;
  void showInstructions() const;
  std::string askIndex() const;
};
