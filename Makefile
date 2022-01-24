NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_num.c ft_printf_str.c

OBJS = ${SRCS:.c=.o}

CC              = gcc
RM              = rm -f

CFLAGS = -Wall -Wextra -Werror

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

all:    ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all