# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/17 11:47:51 by ycribier          #+#    #+#              #
#    Updated: 2015/05/09 15:50:12 by ycribier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	g++
FLAG			=	-Wall -Wextra -Werror
SFMLFLAGS		=	-lncurses -framework ApplicationServices -F SFML/Frameworks -framework sfml-window -framework sfml-graphics -framework sfml-system -framework sfml-network -rpath SFML/Frameworks/
NAME			=	ft_gkrellm
INCLUDES		=	-I ./ -I SFML/include/
SRCS			=	main.cpp						\
					Module.cpp						\
					ModuleCurve.cpp					\
					ModuleCpu.cpp					\
					ModuleRam.cpp					\
					ModuleDate.cpp					\
					ModuleInfos.cpp					\
					ModuleNetwork.cpp				\
					ModuleKitty.cpp
OBJS			=	$(SRCS:%.cpp=%.obj)

# COLORS
C_NO			=	"\033[00m"
C_OK			=	"\033[35m"
C_GOOD			=	"\033[32m"
C_ERROR			=	"\033[31m"
C_WARN			=	"\033[33m"

# DBG MESSAGE
SUCCESS			=	$(C_GOOD)SUCCESS$(C_NO)
OK				=	$(C_OK)OK$(C_NO)

all: $(NAME)

$(NAME): $(OBJS)
	@clang++ -o $@ $^ $(FLAGS) -Wno-deprecated $(SFMLFLAGS)
	@echo "Compiling" [ $(NAME) ] $(SUCCESS)

%.obj: %.cpp
	@clang++ -c -o $@ $< $(FLAGS) -Wno-deprecated $(INCLUDES)
	@echo "Linking" [ $< ] $(OK)

clean:
	@rm -f $(OBJS)
	@rm -rf obj
	@echo "Cleaning" [ $(NAME) ] $(OK)

fclean: clean
	@rm -f $(NAME)
	@echo "Delete" [ $(NAME) ] $(OK)

re: fclean all

.PHONY: all clean fclean re
