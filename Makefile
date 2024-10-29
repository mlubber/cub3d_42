# # Name
# NAME				= cub3d

# # Directories
# LIBFT				= ./libraries/libft/libft.a
# LIBMLX				= ./libraries/MLX42
# INC					= -I .include/ -I $(LIBMLX)/include
# SRC_DIR				= sources/
# BLD_DIR				= build/
# OBJ_DIR				= ./build/objects/

# # Compiler and CFlags
# CC					= cc
# CFLAGS				= -g -Wall -Werror -Wextra #-g -fsanitize=address
# MLXFLAGS			= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
# RM					= rm -f

# # Source Files
# MAIN_DIR			=	$(SRC_DIR)main.c

# PARSING_DIR			=	$(SRC_DIR)/parsing/check_file.c \
# 						$(SRC_DIR)/parsing/process_element.c \
# 						$(SRC_DIR)/parsing/check_scenario.c \
# 						$(SRC_DIR)/parsing/linklist_xy_instance.c \
# 						$(SRC_DIR)/parsing/map_validation.c \
# 						$(SRC_DIR)/parsing/depth_first_search.c \
# 						$(SRC_DIR)/parsing/map_check_charater_duplicate.c \
# 						$(SRC_DIR)/parsing/map_allocation_filling.c \
# 						$(SRC_DIR)/parsing/color_validation.c \
# 						$(SRC_DIR)/parsing/texture_validation.c

# UTILS_DIR			=	$(SRC_DIR)/utils/free_exit.c \
# 						$(SRC_DIR)/utils/utils.c

# EXECUTION_DIR		= 	$(SRC_DIR)/execution/load_game.c

# # Concatenate all source files
# SRCS 				= $(MAIN_DIR) $(PARSING_DIR) $(UTILS_DIR) $(EXECUTION_DIR)

# # Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
# OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# # Build rules
# start:
# 					@make all

# $(LIBFT):
# 					@make -C ./libraries/libft

# all: 				libmlx $(NAME)

# libmlx:
# 					@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# $(NAME): 			$(OBJ) $(LIBFT)
# 					@$(CC) $(CFLAGS) $(MLXFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

# # Compile object files from source files
# $(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
# 					@echo "Compiling ${notdir $<}"
# 					@mkdir -p $(@D)
# 					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# # Cleanups
# clean:
# 					@echo "Cleaning..."
# 					@$(RM) -r $(OBJ_DIR)
# 					@$(RM) -r $(BLD_DIR)
# 					@$(RM) -r $(LIBMLX)/build
# 					@make clean -C ./libraries/libft

# fclean: 			clean
# 					@$(RM) $(NAME)
# 					@$(RM) $(LIBFT)
# 					@echo "All clean"

# re: 				fclean all

# # Phony targets represent actions not files
# .PHONY: 			start all clean fclean re



# Compiler and Flags
CC      = cc
CFLAGS  = -g -Wall -Werror -Wextra # -g -fsanitize=address
MLX_DIR = ./libraries/MLX42
LIBMLX  = $(MLX_DIR)/build/libmlx42.a
LIBFT   = ./libraries/libft/libft.a
GLFW     = -lglfw -lm
RM      = rm -f

# Output Name
NAME    = cub3d

# Source Directories
SRC_DIR = ./sources
OBJ_DIR = ./build/objects

# Source Files
MAIN_DIR = $(SRC_DIR)/main.c

PARSING_DIR = $(SRC_DIR)/parsing/check_file.c \
              $(SRC_DIR)/parsing/process_element.c \
              $(SRC_DIR)/parsing/check_scenario.c \
              $(SRC_DIR)/parsing/linklist_xy_instance.c \
              $(SRC_DIR)/parsing/map_validation.c \
              $(SRC_DIR)/parsing/depth_first_search.c \
              $(SRC_DIR)/parsing/map_check_charater_duplicate.c \
              $(SRC_DIR)/parsing/map_allocation_filling.c \
              $(SRC_DIR)/parsing/color_validation.c \
              $(SRC_DIR)/parsing/texture_validation.c

UTILS_DIR = $(SRC_DIR)/utils/free_exit.c \
            $(SRC_DIR)/utils/utils.c

EXECUTION_DIR = $(SRC_DIR)/execution/load_game.c \
				$(SRC_DIR)/execution/move.c

# All source files
SRCS = $(MAIN_DIR) $(PARSING_DIR) $(UTILS_DIR) $(EXECUTION_DIR)

# Object files
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Build rules
all: $(LIBFT) libmlx $(NAME)

$(LIBFT):
	@make -C ./libraries/libft

libmlx:
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && \
	make -C $(MLX_DIR)/build -j4

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBMLX) $(GLFW) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $<"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	@echo "Cleaning..."
	@$(RM) -r $(OBJ_DIR)
	@make clean -C ./libraries/libft
	@$(RM) -r $(MLX_DIR)/build

fclean: clean
	@$(RM) $(NAME)

re: fclean all

# Phony targets
.PHONY: all clean fclean re libmlx
