CC			= gcc -Wall -Wextra -Werror
LFLAGS		= -framework OpenGL -framework AppKit
NAME		= so_long
SRCS 		= src/*.c
BNAME		= so_long_bonus
BSRCS 		= bonus/*.c

all : $(NAME)

$(NAME): LIBS
	@$(CC) $(LFLAGS) $(SRCS) libft/libft.a ft_printf/libftprintf.a minilibx/libmlx.a -I ./includes/so_long.h -o $(NAME)

bonus: $(BNAME)
$(BNAME): LIBS
	@$(CC) $(LFLAGS) $(BSRCS) libft/libft.a ft_printf/libftprintf.a minilibx/libmlx.a -I ./includes/so_long_bonus.h -o $(BNAME)

LIBS:
	@make -s -C minilibx
	@make -s -C libft
	@make -s -C ft_printf
norm:
	@norminette src/*.c
	@norminette includes/*.h
	@norminette libft/*.c
	@norminette libft/*.h
clean:
	@rm -rf libft/*.o
fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(BNAME)
	@make clean -s -C minilibx
	@make fclean -s -C libft
	@make fclean -s -C ft_printf
re: fclean all
rebonus : fclean bonus