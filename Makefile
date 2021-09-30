NAME		=	minitalk

SERV_NAME	=	server

CLNT_NAME	=	client

SERV_SRCS	=	./server.c\
				./lib.c

CLNT_SRCS	=	./client.c\
				./lib.c

CC			=	gcc

CLFAGS		=	-Werror -Wextra -Wall

SANFLAGS	=	-g -fsanitize=address

DEL			=	rm -f

SERV_OBJ	=	$(SERV_SRCS:.c=.o)

CLNT_OBJ	=	$(CLNT_SRCS:.c=.o)

$(NAME):		$(SERV_OBJ) $(CLNT_OBJ)
				$(CC) -o $(SERV_NAME) $(SERV_SRCS) $(CLFAGS)
				$(CC) -o $(CLNT_NAME) $(CLNT_SRCS) $(CLFAGS)

%.o:			%.c
				$(CC) $(CLFAGS) -o $@ -c $<

all:			$(NAME)

san:			$(SERV_OBJ) $(CLNT_OBJ)
				$(CC) -o $(SERV_NAME) $(SERV_SRCS) $(CFLAGS) $(SANFLAGS)
				$(CC) -o $(CLNT_NAME) $(CLNT_SRCS) $(CFLAGS) $(SANFLAGS)

clean:
				$(DEL) $(SERV_OBJ)
				$(DEL) $(CLNT_OBJ)

fclean:			clean
				$(DEL) $(SERV_NAME)
				$(DEL) $(CLNT_NAME)

re:				fclean all

.PHONY:			all san clean fclean re