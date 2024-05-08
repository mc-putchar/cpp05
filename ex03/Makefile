# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcutura <mcutura@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 03:15:52 by mcutura           #+#    #+#              #
#    Updated: 2024/05/08 06:19:13 by mcutura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := a.out
SRCS := main.cpp Bureaucrat.cpp AForm.cpp Intern.cpp \
	PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
OBJS := $(SRCS:%.cpp=%.o)
HDRS := Bureaucrat.hpp AForm.hpp Intern.hpp \
	PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -Wpedantic
debug: CXXFLAGS += -ggdb3 -Og

RM := rm -rf

.PHONY: all clean debug fclean re

all: $(NAME)

$(NAME): $(OBJS) $(HDRS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	
$(OBJS) : %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

debug: all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
