SRCS	= ft_printf.c ft_parser.c \
			ft_dop_functions.c \
			ft_print_int.c ft_with_width.c \
			ft_print_char.c ft_print_string.c ft_print_pointer.c ft_print_percent.c \
			
OBJS	=  ${SRCS:.c=.o}
INCS	= ./
NAME	= libftprintf.a
LIBC	= ar rc
LIBR	= ranlib
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

$(NAME): ${OBJS}
		${LIBC} ${NAME} ${OBJS}
		${LIBR} ${NAME}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re