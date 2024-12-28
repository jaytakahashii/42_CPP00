/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jay <jay@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:05:41 by jay               #+#    #+#             */
/*   Updated: 2024/12/28 21:19:45 by jay              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "Contact.hpp"

class PhoneBook {
 private:
  Contact _contacts[8];
  int _columnWidth;
  int _index;
  bool _full;

 public:
  PhoneBook();
  ~PhoneBook();

  bool setInfo();
  bool fullLoop();
  bool isValidIndex(const std::string& input) const;
  int promptForIndex() const;
  void getInfo() const;
  void showInstructions() const;
};
