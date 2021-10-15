CC			=	gcc
CLFAGS		=	-Werror -Wextra -Wall
SANFLAGS	=	-g -fsanitize=address
DEL			=	rm -f


SERV_NAME	=	server
SERV_SRCS	=	./srcs/server.c\
				./lib/lib.c\
				./lib/lib_2.c
SERV_OBJ	=	$(SERV_SRCS:.c=.o)

SERV_NAME_B	=	server_bonus
SERV_SRCS_B	=	./bonus/server_bonus.c\
				./lib/lib.c\
				./lib/lib_2.c
SERV_OBJ_B	=	$(SERV_SRCS_B:.c=.o)


CLNT_NAME	=	client
CLNT_SRCS	=	./srcs/client.c\
				./lib/lib.c\
				./lib/lib_2.c
CLNT_OBJ	=	$(CLNT_SRCS:.c=.o)

CLNT_NAME_B	=	client_bonus
CLNT_SRCS_B	=	./bonus/client_bonus.c\
				./lib/lib.c\
				./lib/lib_2.c
CLNT_OBJ_B	=	$(CLNT_SRCS_B:.c=.o)

all:			$(SERV_NAME) $(CLNT_NAME)

%.o:			%.c
				$(CC) $(CLFAGS) -o $@ -c $<

$(SERV_NAME):	$(SERV_OBJ)
				$(CC) -o $(SERV_NAME) $(SERV_SRCS) $(CLFAGS)

$(CLNT_NAME):	$(CLNT_OBJ)
				$(CC) -o $(CLNT_NAME) $(CLNT_SRCS) $(CLFAGS)

bonus:			$(SERV_NAME_B) $(CLNT_NAME_B)

$(SERV_NAME_B):	$(SERV_OBJ_B)
				$(CC) -o $(SERV_NAME_B) $(SERV_SRCS_B) $(CLFAGS)

$(CLNT_NAME_B):	$(CLNT_OBJ_B)
				$(CC) -o $(CLNT_NAME_B) $(CLNT_SRCS_B) $(CLFAGS)

san:			$(SERV_OBJ) $(CLNT_OBJ)
				$(CC) -o $(SERV_NAME) $(SERV_SRCS) $(CFLAGS) $(SANFLAGS)
				$(CC) -o $(CLNT_NAME) $(CLNT_SRCS) $(CFLAGS) $(SANFLAGS)

clean:
				$(DEL) $(SERV_OBJ)
				$(DEL) $(CLNT_OBJ)
				$(DEL) $(SERV_OBJ_B)
				$(DEL) $(CLNT_OBJ_B)

fclean:			clean
				$(DEL) $(SERV_NAME)
				$(DEL) $(CLNT_NAME)
				$(DEL) $(SERV_NAME_B)
				$(DEL) $(CLNT_NAME_B)
				
re:				fclean all

.PHONY:			all bonus san clean fclean re