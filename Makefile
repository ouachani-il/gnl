SRCS		=	get_next_line.c \
				get_next_line_utils.c 

OBJS	=	${SRCS:.c=.o}

NAME	= get_next_line

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
BUF		=  -D BUFFER_SIZE=42

.c.o:
				${CC} ${CFLAGS} ${BUF} -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS}
				ar rc ${NAME} ${OBJS}
#				ranlib ${NAME}
				
clean:
				rm -f ${OBJS}

fclean:		clean
				rm -f ${NAME}

re:				fclean all

.PHONY:			all clean fclean re