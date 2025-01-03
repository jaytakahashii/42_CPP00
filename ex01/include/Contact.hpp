/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jay <jay@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:49:56 by jay               #+#    #+#             */
/*   Updated: 2024/12/29 15:49:29 by jay              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

class Contact {
 private:
  static std::string _fields[5];
  std::string _info[11];

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
  void getContact(std::string index, int columnWidth) const;
};
