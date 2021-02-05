# CONFIGURACIÓN
NAME		= cub3D

SRCS		= srcs/genmap.c\
			srcs/getnextline.c\
			srcs/main.c\
			srcs/errors.c\
			srcs/errors1.c\
			srcs/errors2.c\
			srcs/errors3.c\
			srcs/errors4.c\
			srcs/finalizer.c\
			srcs/supportft.c\
			srcs/saveconfigerror.c\
			srcs/saveconfigerror2.c\
			srcs/raycasting.c\
			srcs/preraycasting.c\
			srcs/preraycasting2.c\
			srcs/dirpos.c\
			srcs/raycasting2.c\
			srcs/main_loop.c\
			srcs/rays.c\
			srcs/textures.c

OBJS		= $(SRCS:.c=.o)

LIBFT		:= libft/libft.a
FLAGS		= -Wall -Wextra -Werror -g #-fsanitize=address
GCC			= gcc
INCLUDE		= -I minilibx -I headers
MLX_DIR		= minilibx_opengl

all:		$(NAME)

$(NAME):	$(OBJS)
				@echo "\033[0;31m[Remove last version...]"
				@rm -rf cub3D
				@echo "\033[0;35m[minilib compilation...]"
			$(MAKE) -C minilibx_opengl
				@echo "\033[0;36m[Libft compilation...]"
			$(MAKE) -C libft
				@echo "\033[0;33m[cub3D compilation...]"
			$(GCC) $(LIBFT) $(SRCS) -L $(MLX_DIR) $(FLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
				@echo "\033[1;32m[* * * * * * * * * * * * * * * * * * * * * * *]"
				@echo "\033[1;32m[ C O M P I L E D        S U C C E S F U L L Y]"
				@echo "\033[1;32m[* * * * * * * * * * * * * * * * * * * * * * *]"
fclean: clean
	rm -f $(NAME)
clean:
	@echo "\033[0;31m[Deleting Objects...]"
	$(RM) $(OBJS)
re:		fclean $(NAME)