CC = gcc
SRCS = ft_printf.c put.c helper_funcs.c hex_len.c
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
LIBC = ar rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

${NAME}: make_libft ${OBJS}
	${LIBC} ${NAME} ${OBJS} libft/libft.a

make_libft: 
	$(MAKE) -C libft

fclean_libft: 
	$(MAKE) -C libft fclean

clean_libft: 
	$(MAKE) -C libft clean

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

bonus: ${NAME} ${OBJS}
		${LIBC} ${NAME} ${OBJS}

clean: clean_libft
	${RM} ${OBJS} ${OBJS}\

fclean: clean fclean_libft
	${RM} ${NAME} ${bonus}\

re: fclean all

all: ${NAME}

.PHONY : all bonus clean fclean re make_libft fclean_libft clean_libft
