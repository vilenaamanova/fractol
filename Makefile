NAME	=	fractol

SRCS	=	main.c \
			mandelbrot.c \
			julia.c \
			burningship.c \
			control_img.c \
			fractol_utils.c \
			init.c \
			keyboard_control.c \
			mouse_control.c \
			draw_fractal.c \
			parse.c \

LIBFT	=	./libft/libft.a

HEADER	=	fractol.h

OBJ		=	$(patsubst %.c, %.o, $(SRCS))

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

MLX		=	-lmlx -framework OpenGL -framework AppKit

.PHONY	:	all clean fclean re

all 	:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
			@$(MAKE) -C ./libft --silent
			$(CC) $(CFLAGS) $(MLX) $(OBJ) $(LIBFT) -o $(NAME)

%.o	:	%.c	$(HEADER)
	$(CC)	$(CFLAGS) -c $< -o $@

clean	:
	@rm -rf $(OBJ)
	@$(MAKE) clean -C ./libft

fclean	:	clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C ./libft

re		:	fclean all
