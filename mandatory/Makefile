NAME = miniRT

SRC_DIR = $(sort $(dir $(wildcard src/*/))) src/
OBJ_DIR = obj/
INC_DIR = ../include/ ../libft/include/
TARGET_DIR = ./
LIB_DIR = ../libft/ ../MinilibX/
LDIR = $(LIB_DIR:%=-L%)

CC = cc
OPT = -O3 -ffast-math
EXTRA =-Wall -Werror -Wextra
DEP = -MP -MMD
LIBS = ft mlx
LIB = $(LIBS:%=-l%)
FRAMEWORKS = OpenGL AppKit
FWK = $(FRAMEWORKS:%=-framework %)

# Colors

C_RESET = \033[0;39m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
B_MAGENTA = \033[1;35m
CYAN = \033[0;96m

# Sources
SRCS = \
main.c					\
parse_ambient.c			\
parse_camera.c			\
parse_light.c			\
parse_sphere.c			\
parse_cylinder.c		\
parse_plane.c			\
parse_file.c			\
parse_file_utils1.c		\
parse_file_utils2.c		\
parser_utils1.c			\
parser_utils2.c			\
parser_utils3.c			\
parser_checksets.c		\
parser_double_utils.c	\
get_normals.c			\
v3d.c					\
vector_arithmetic.c		\
vector_in_place.c		\
vector_math.c			\
vector_quad.c			\
vector_utils.c			\
ray.c					\
scene.c					\
data.c					\
camera.c				\
buttons.c				\
parse_atod.c			\
print_results.c			\
print_results_utils1.c	\
color.c					\
render.c				\
get_ray_hit.c			\
get_ray_hit_shapes.c	\
get_ray_hit_utils.c		\
get_light_ray_hit.c		\
get_ray_hit_cy_utils.c	\
shader.c				\
cap_utils.c

OBJS := $(SRCS:%.c=$(OBJ_DIR)%.o)
DEPS = $(SRCS:%.c=$(OBJ_DIR)%.d)

###

all:		$(NAME)

$(OBJS):	$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
			@echo "$(GREEN)Compiling: $(BLUE)$<$(C_RESET)"
			@$(CC) $(FLAGS) -c -o $@ $<

# Target
$(NAME):	$(OBJS) | $(TARGET_DIR) libft
			@$(CC) $(FLAGS) $(FWK) $(LDIR) $(LIB) -o $@ $^
			@echo "$(B_MAGENTA)\n...$(NAME) compiled successfully...\n$(C_RESET)"

libft:
			@make -C ../MinilibX
			@make -C ../libft

clean:
			@make clean -C ../MinilibX
			rm -rf $(OBJ_DIR)

fclean: clean
			rm -rf $(NAME)
			@make fclean -C ../MinilibX
			@make fclean -C ../libft

# Debug
debug:
			make fclean
			make all FLAGS="-g -fsanitize=address"

re: 		fclean all

# Dir creation
$(OBJ_DIR) $(TARGET_DIR):
	@mkdir -p $@

-include $(DEPS)

.PHONY: all clean fclean re debug libft

vpath %.c $(SRC_DIR)
override FLAGS +=\
$(EXTRA) $(OPT) $(DEP) \
$(INC_DIR:%=-I%) $(SRC_DIR:%=-I%)
