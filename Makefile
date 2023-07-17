# Targets
NAME		= miniRT

SRC_DIR		= $(sort $(dir $(wildcard src/*/))) src/
OBJ_DIR		=	obj/
INCLUDE	 	=	-I include
LIBFT		=	libft
LIBFT_A		=	$(LIBFT)/libft.a

CC			=	cc
CFLAGS		=	-O3 -Wall -Werror -Wextra
MLXFLAGS	=	-framework OpenGL -framework AppKit
MATH		=	-lm

# Colors

C_RESET = \033[0;39m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
B_MAGENTA = \033[1;35m
CYAN = \033[0;96m

#Sources

SRC_FILES	=	main				\
				plane


SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###

all:		makelibs
			@$(MAKE) $(NAME)

makelibs:
			@$(MAKE) -C $(LIBFT)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L. $(LIBFT_A) -L. -lmlx $(MLXFLAGS) $(MATH)
			@echo "$(B_MAGENTA)\n...$(NAME) compiled successfully...\n$(C_RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(OBJ_DIR)
			@echo "$(GREEN)Compiling: $(BLUE)$<$(C_RESET)"
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
			@make clean -C $(LIBFT)
			@rm -rf $(OBJ_DIR)
			@echo "$(BLUE)MINILIB OBJECTS DELETED$(C_RESET)"


fclean:		clean
			@rm -f $(NAME)
			@rm -f $(LIBFT_A)
			@echo "$(CYAN)EXECUTABLE DELETED$(C_RESET)"

re:			fclean all

.PHONY:		all clean fclean re makelibs
