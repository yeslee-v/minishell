NAME = pipe

HEADER = -I ./includes

CC = gcc
CFLAGES = -Wall -Wextra -Werror -g3 -fsanitize=address

LIBFT = ./libs/libft
LIBFT_NAME = libft.a

RM = rm
RMFLAGS = -f

SRCS = ./srcs/pipe.c \
	   ./srcs/print_error.c \
	   ./srcs/set_cmd.c \
	   ./srcs/redirect.c \
	   ./srcs/run.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@make all -C $(LIBFT)
	@cp $(LIBFT)/$(LIBFT_NAME) $(LIBFT_NAME)
	$(CC) $(CFLAGES) -L. -lft $(LFLAGES) $(LIBS) -o $@ $^

%.o:%.c
	@$(CC) $(CFLAGES) $(HEADER) -o $@ -c $<	

clean :
	$(RM) $(RMFLAGS) $(OBJS)
	 make clean -C $(LIBFT)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)
	$(RM) $(RMFLAGS) ./libft.a
	@make fclean -C $(LIBFT)

re : fclean all

.PHONY : all fclean clean re
