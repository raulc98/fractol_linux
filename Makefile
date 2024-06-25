# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/24 21:04:14 by rcabrero          #+#    #+#              #
#    Updated: 2024/03/25 20:12:39 by rcabrero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binaries variables
BIN         =   bin
SRC         =   src
INCLUDE_L   =   includes
MLX_LIB     =   minilibx-linux/libmlx.a
MLX_FLAGS   =   -Lminilibx-linux -lmlx -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz

# Compiler options
CC          =   gcc
CFLAGS      =   -Wall -Wextra -Werror -I$(INCLUDE_L) -g3
INCLUDE     =   -I./$(INCLUDE_L)
COMPILE     =   @$(CC) $(CFLAGS) $(INCLUDE)

NAME        =   fractol

# Colors:
NC          =   \033[0m
RED         =   \033[0;31m
GREEN       =   \033[0;32m
LRED        =   \033[1;31m
LGREEN      =   \033[1;32m
YELLOW      =   \033[1;33m
LBLUE       =   \033[1;34m
TITLE       =   \033[38;5;33m

ACTIONS     =   iterations.c \
                move.c \
                zoom.c
FRACTAL     =   color.c \
				fractal_calculator.c 
LIBFT       =   ft_putstr_fd.c \
                ft_strcmp.c \
                ft_strlen.c \
				atof.c \
				is_numeric.c \
				ft_isdigit.c
MAIN        =   instructions.c \
                leaks_controller.c \
                controller.c \
				initializers.c \
				checkers.c \
                main.c
WINDOW      =   key_controller.c \
                mouse_controller.c 
FRACTOL_SRC =   $(ACTIONS:%=actions/%) \
                $(FRACTAL:%=fractal/%) \
                $(LIBFT:%=libft_utils/%) \
                $(MAIN:%=main/%) \
                $(WINDOW:%=window_controller/%)
SOURCE      =   $(FRACTOL_SRC)
SRC_CODE    =   $(SOURCE:%=$(SRC)/%)
OBJ         =   $(SRC_CODE:$(SRC)/%.c=$(BIN)/%.o)

# Triggers
all: $(NAME)

$(BIN)/%.o: $(SRC)/%.c
	@echo "- ${TITLE}Compiling${NC} $< -> $@"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo " ${GREEN}[OK]${NC}"

$(NAME): mlx $(OBJ)
	@echo "\n${TITLE}Compiling${NC} ${YELLOW}$(NAME)${NC}"
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)
	@echo " ${GREEN}[OK]${NC}\n"

.PHONY: all clean fclean re mlx

mlx:
	@echo "Compiling minilibx-linux..."
	@$(MAKE) -C minilibx-linux

clean:
	@echo "- ${RED}Removing${NC} binary directory"
	@rm -rf $(BIN)
	@echo "- ${RED}Cleaning minilibx-linux${NC}"
	@$(MAKE) -C minilibx-linux clean

fclean: clean
	@echo "- ${RED}Removing${NC} $(NAME)"
	@rm -f $(NAME)
	@echo "Project ${YELLOW}fractol ${GREEN}fully clean${NC}.\n"

re: fclean all
