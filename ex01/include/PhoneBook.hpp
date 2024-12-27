/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jay <jay@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:05:41 by jay               #+#    #+#             */
/*   Updated: 2024/12/27 22:55:08 by jay              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "Contact.hpp"

class PhoneBook {
 private:
  Contact _contacts[8];
  int _index;
  bool _full;

 public:
  PhoneBook();
  ~PhoneBook();

  void setInfo();
  void getInfo() const;
  void showInstructions();
};
