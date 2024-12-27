/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jay <jay@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:24:54 by jay               #+#    #+#             */
/*   Updated: 2024/12/27 22:56:29 by jay              ###   ########.fr       */

/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int main(int argc, char **argv) {
  if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      for (int j = 0; argv[i][j] != '\0'; j++)
        argv[i][j] = (char)toupper(argv[i][j]);
      std::cout << argv[i];
      if (i < argc - 1)
        std::cout << " ";
    }
    std::cout << std::endl;
  } else
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  return 0;
}
