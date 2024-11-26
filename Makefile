# Name
NAME				=	cub3D

# Directories
SRC_DIR				=	sources/
BLD_DIR				=	build/
OBJ_DIR				=	./build/objects/
LIBMLX				=	./libraries/MLX42
LIBFT				=	./libraries/libft/libft.a
INC					=	-I ./include -I $(LIBMLX)/include

# Compiler and CFlags
CC					=	cc
CFLAGS				=	-g -Wall -Wextra -Werror -Wunreachable-code -Ofast -fsanitize=address
MLXFLAGS			=	$(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -fsanitize=address
RM					=	rm -f

# Source Files
MAIN_DIR			=	$(SRC_DIR)main.c

PARSING_DIR			=	$(SRC_DIR)parsing/check_file.c \
						$(SRC_DIR)parsing/process_element.c \
						$(SRC_DIR)parsing/check_scenario.c \
						$(SRC_DIR)parsing/linklist_xy_instance.c \
						$(SRC_DIR)parsing/map_validation.c \
						$(SRC_DIR)parsing/depth_first_search.c \
						$(SRC_DIR)parsing/map_check_charater_duplicate.c \
						$(SRC_DIR)parsing/map_allocation_filling.c \
						$(SRC_DIR)parsing/color_validation.c

UTILS_DIR			=	$(SRC_DIR)utils/free_exit.c \
						$(SRC_DIR)utils/draw.c \
						$(SRC_DIR)utils/utils.c

EXEC_DIR			=	$(SRC_DIR)execution/input.c \
						$(SRC_DIR)execution/mini_map.c \
						$(SRC_DIR)execution/ray_casting.c \
						$(SRC_DIR)execution/ray_cast_utils.c


INIT_DIR			=	$(SRC_DIR)init/init.c

# Concatenate all source files
SRCS 				=	$(MAIN_DIR) $(PARSING_DIR) $(UTILS_DIR) $(INIT_DIR) $(EXEC_DIR)

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJS 				=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

start:
					@make all

$(LIBFT):
					@make -C ./libraries/libft

all: 				libmlx $(NAME)

libmlx:
					@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): 			$(OBJS) $(LIBFT)
					@$(CC) $(OBJS) $(LIBFT) $(MLXFLAGS) $(INC) -o $(NAME)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					@echo "Compiling ${notdir $<}"
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Cleanups
clean:
					@echo "Cleaning..."
					@$(RM) -r $(OBJ_DIR)
					@$(RM) -r $(BLD_DIR)
					@$(RM) -r $(LIBMLX)/build
					@make clean -C ./libraries/libft

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)
					@echo "All clean"

re: 				fclean all

# Phony targets represent actions not files
.PHONY: 			all, clean, fclean, re, libmlx