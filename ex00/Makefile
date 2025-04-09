MAKEFILE 		= Makefile

NAME				= megaphone

SRC_DIR			= src/
OBJ_DIR			= .obj/

DEPS				= $(MAKEFILE)

CXX					= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98

RM					= rm -rf

SRC_DIR			= src/
SRC_FILES		=	megaphone.cpp

SRCS				= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS				= $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))

# color ************
Y		= "\033[33m"
R		= "\033[31m"
G		= "\033[32m"
B		= "\033[34m"
X		= "\033[0m"
UP	= "\033[A"
CUT	= "\033[K"
# ******************

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(DEPS)
	@echo $(Y) "src files successfully compiled.\n" $(X)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo $(G) "!! $(NAME) created !!\n" $(X)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
	@echo $(R) "$(OBJ_DIR) has been removed.\n" $(X)

fclean:
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME)
	@echo $(R) "$(NAME) and $(OBJ_DIR) has been removed.\n" $(X)

re: fclean all

.PHONY: all clean fclean re
