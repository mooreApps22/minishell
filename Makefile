NAME	= minishell
CC		= cc -Wall -Wextra -Werror -g
SRC		= $(wildcard src/*.c)
OBJ		= $(SRC:.c=.o)
HEADER	= libft/include/libft.h include/minishell.h
IFLAG	= -I./include
LIBFT	= libft/libft.a
LINKER	= -lreadline -ltermcap

all: $(NAME) $(LIBFT)

$(LIBFT):
	@make -C libft/ all

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(OBJ) $(LIBFT) $(IFLAG) -o $(NAME) $(LINKER)

%.o: %.c $(HEADER)
	@$(CC) -c $< -o $@ $(IFLAG)

clean:
	@make -C ./libft clean
	@rm -f src/*.o
	@rm -f *.o

fclean: clean
	@make -C ./libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re minishell libft
