CC		= cc
SRCS	= client.c server.c
OBJS	= $(SRCS:%.c=%.o)
RM		= rm -f
CFLAGS 	= -Wall -Wextra -Werror

all:		server client

%.o:	%.c
		${CC} ${CFLAGS} -Ilibft -c $? -o $@
	
server:		server.o
		@make -C libft
		${CC} ${CFLAGS} $? -Llibft -lft  -o server

client:		client.o
		@make -C libft
		${CC} ${CFLAGS} $? -Llibft -lft -o client

libft:
		make -C libft

clean:
			make clean -C libft
			${RM} ${OBJS}

fclean:		clean
			make fclean -C libft
			${RM} server client

re:			fclean all

.PHONY:		libft all fclean clean re