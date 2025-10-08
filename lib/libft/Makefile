# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sachanai <sachanai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/16 16:17:55 by tmalkawi          #+#    #+#              #
#    Updated: 2025/08/27 09:43:09 by sachanai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(BUILD_PATH)/bin/libft.a

STRING_FILE_PATH = src/string/
PRINT_FILE_PATH = src/print/
MEMORY_FILE_PATH = src/memory/
LINKED_LIST_FILE_PATH = src/lst/
CHECKS_FILE_PATH = src/checks/
FTPRINTF_FILE_PATH = src/ft_printf/
GNL_FILE_PATH = src/gnl/
BUILD_PATH = build

SOURCES = $(STRING_FILE_PATH)ft_atoi.c \
		  $(STRING_FILE_PATH)ft_itoa.c \
		  $(STRING_FILE_PATH)ft_atoll.c \
		  $(STRING_FILE_PATH)ft_split.c \
		  $(STRING_FILE_PATH)ft_strchr.c \
		  $(STRING_FILE_PATH)ft_strdup.c \
		  $(STRING_FILE_PATH)ft_striteri.c \
		  $(STRING_FILE_PATH)ft_strjoin.c \
		  $(STRING_FILE_PATH)ft_strlcat.c \
		  $(STRING_FILE_PATH)ft_strnull.c \
		  $(STRING_FILE_PATH)ft_strlcpy.c \
		  $(STRING_FILE_PATH)ft_strlen.c \
		  $(STRING_FILE_PATH)ft_strmapi.c \
		  $(STRING_FILE_PATH)ft_strncmp.c \
		  $(STRING_FILE_PATH)ft_strnstr.c \
		  $(STRING_FILE_PATH)ft_strrchr.c \
		  $(STRING_FILE_PATH)ft_strslen.c \
		  $(STRING_FILE_PATH)ft_strtrim.c \
		  $(STRING_FILE_PATH)ft_substr.c \
		  $(STRING_FILE_PATH)ft_tolower.c \
		  $(STRING_FILE_PATH)ft_toupper.c \
		  $(STRING_FILE_PATH)ft_strsdup.c \
		  $(STRING_FILE_PATH)ft_strcmp.c \
		  $(STRING_FILE_PATH)ft_strcpy.c \
		  $(STRING_FILE_PATH)ft_strcat.c \

SOURCES += $(PRINT_FILE_PATH)ft_putchar_fd.c \
		   $(PRINT_FILE_PATH)ft_putendl_fd.c \
		   $(PRINT_FILE_PATH)ft_putnbr_fd.c \
		   $(PRINT_FILE_PATH)ft_putstr_fd.c \
		   $(PRINT_FILE_PATH)ft_print_array.c \

SOURCES += $(MEMORY_FILE_PATH)ft_bzero.c \
		   $(MEMORY_FILE_PATH)ft_calloc.c \
		   $(MEMORY_FILE_PATH)ft_memchr.c \
		   $(MEMORY_FILE_PATH)ft_memcmp.c \
		   $(MEMORY_FILE_PATH)ft_memcpy.c \
		   $(MEMORY_FILE_PATH)ft_memmove.c \
		   $(MEMORY_FILE_PATH)ft_memset.c \
		   $(MEMORY_FILE_PATH)ft_free_tab.c \

SOURCES += $(LINKED_LIST_FILE_PATH)ft_lstadd_back_bonus.c \
		   $(LINKED_LIST_FILE_PATH)ft_lstadd_front_bonus.c \
		   $(LINKED_LIST_FILE_PATH)ft_lstclear_bonus.c \
		   $(LINKED_LIST_FILE_PATH)ft_lstdelone_bonus.c \
		   $(LINKED_LIST_FILE_PATH)ft_lstiter_bonus.c \
		   $(LINKED_LIST_FILE_PATH)ft_lstmap_bonus.c \
		   $(LINKED_LIST_FILE_PATH)ft_lstnew_bonus.c \
		   $(LINKED_LIST_FILE_PATH)ft_lstsize_bonus.c \
		   $(LINKED_LIST_FILE_PATH)ft_lstlast_bonus.c \

SOURCES += $(CHECKS_FILE_PATH)ft_isalnum.c \
		   $(CHECKS_FILE_PATH)ft_isalpha.c \
		   $(CHECKS_FILE_PATH)ft_isascii.c \
		   $(CHECKS_FILE_PATH)ft_isdigit.c \
		   $(CHECKS_FILE_PATH)ft_isprint.c \
		   $(CHECKS_FILE_PATH)ft_iswhitespace.c \

SOURCES += $(FTPRINTF_FILE_PATH)ft_baseten.c \
		   $(FTPRINTF_FILE_PATH)ft_hex.c \
		   $(FTPRINTF_FILE_PATH)ft_printf.c \
		   $(FTPRINTF_FILE_PATH)ft_string.c \

SOURCES += $(GNL_FILE_PATH)get_next_line.c \
		  $(GNL_FILE_PATH)get_next_line_utils.c \


OBJS = $(SOURCES:src/%.c=build/%.o)

CC = cc
INCLUDES = -I./include/
CC_FLAGS = -Wall -Wextra -Werror
AR_FLAGS = -rcs

all: $(NAME)

$(NAME): $(OBJS)
	@mkdir -p $(dir $(NAME))
	ar $(AR_FLAGS) $@ $^

build/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CC_FLAGS) $(INCLUDES) -c $< -o $@ -g3

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
