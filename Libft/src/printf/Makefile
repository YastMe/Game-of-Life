CFILES = ft_printf.c\
ft_putstrn.c\
ft_putptrn.c\
ft_putnbrn.c\
ft_putunsignedn.c\
ft_puthexn.c\
ft_putpercentage.c
OFILES = $(CFILES:.c=.o)

NAME = libftprintf.a

CC = gcc
CFALGS = -Wall -Wextra -Werror
ARCHIVER = ar rcs
REMOVE = rm -f

all: $(NAME)

$(NAME): $(OFILES)
	$(ARCHIVER) $(NAME) $(OFILES)

$(OFILES): $(CFILES)
	$(CC) $(CFLAGS) -c $(CFILES)

clean:
	$(REMOVE) $(OFILES)

fclean:
	$(REMOVE) $(OFILES) $(NAME)

re: fclean all

.PHONY : all clean fclean re