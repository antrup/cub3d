# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atruphem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/20 18:28:25 by atruphem          #+#    #+#              #
#    Updated: 2020/11/22 20:41:16 by atruphem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a 

OBJ = 	ft_atoi.o ft_putchar_fd.o ft_strmapi.o ft_bzero.o \
		ft_putendl_fd.o ft_strncmp.o ft_calloc.o ft_putnbr_fd.o ft_strnstr.o \
		ft_isalnum.o ft_putendl_fd.o  ft_strrchr.o ft_isalpha.o ft_putstr_fd.o \
		ft_strtrim.o ft_isascii.o ft_split.o ft_substr.o ft_isdigit.o \
		ft_memccpy.o ft_strchr.o ft_tolower.o ft_isprint.o ft_memchr.o \
		ft_strdup.o  ft_toupper.o ft_itoa.o ft_memcmp.o ft_strjoin.o \
		ft_memcpy.o ft_strlcat.o ft_memmove.o ft_strlcpy.o ft_memset.o \
		ft_strlen.o

OBJB =	ft_lstadd_back.o ft_lstdelone.o ft_lstmap.o ft_lstadd_front.o \
		ft_lstiter.o ft_lstnew.o ft_lstclear.o ft_lstlast.o ft_lstsize.o

all: $(NAME)

bonus: $(NAME) $(OBJB)
	ar q $^
	ranlib $<

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

%.o: %.c
	clang -Wall -Werror -Wextra -o $@ -c $<

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME)

re: fclean all
