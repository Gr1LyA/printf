SRCS	=	ft_printf.c func_spec.c func_spec2.c sub_func.c sub2_func.c spec_d.c
OBJS	=	${SRCS:.c=.o}
NAME	=	libftprintf.a
CC	=		gcc
RM	=		rm -f
CFLAGS	=	-Wall -Wextra -Werror

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
.PHONY: all clean fclean re
