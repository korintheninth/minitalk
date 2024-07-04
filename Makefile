CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBS =  ft_printf/libftprintf.a ft_printf/libft/libft.a

SRCSCLIENT = client.c

SRCSSERVER = server.c

CLIENTOBJS = $(SRCSCLIENT:.c=.o)

SERVEROBJS = $(SRCSSERVER:.c=.o)

TARGETCLIENT = client

TARGETSERVER = server

TARGET = $(TARGETCLIENT) $(TARGETSERVER)

$(TARGET): build_subdirs $(CLIENTOBJS) $(SERVEROBJS)
	$(CC) $(CFLAGS) -o $(TARGETCLIENT) $(CLIENTOBJS) $(LIBS);\
	$(CC) $(CFLAGS) -o $(TARGETSERVER) $(SERVEROBJS) $(LIBS)

clean: clean_subdirs
	rm -f $(SERVEROBJS) $(CLIENTOBJS)

fclean: fclean_subdirs clean
	rm -f $(TARGETCLIENT) $(TARGETSERVER)

build_subdirs:
			$(MAKE) -C ft_printf

fclean_subdirs:
			$(MAKE) -C ft_printf fclean

clean_subdirs:
			$(MAKE) -C ft_printf clean;

re: fclean all

all: $(TARGETCLIENT) $(TARGETSERVER)

.PHONY: all clean fclean re build_subdirs clean_subdirs fclean_subdirs