# # Name
# NAME				=	cub3D

# # Directories
# SRC_DIR				=	sources/
# BLD_DIR				=	build/
# OBJ_DIR				=	./build/objects/
# LIBMLX				=	./libraries/MLX42
# LIBFT				=	./libraries/libft/libft.a
# INC					=	-I ./include -I $(LIBMLX)/include

# # Compiler and CFlags
# CC					=	cc
# CFLAGS				=	-g -Wall -Wextra -Werror -Wunreachable-code -Ofast -fsanitize=address
# MLXFLAGS			=	$(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -fsanitize=address
# RM					=	rm -f

# # Source Files
# MAIN_DIR			=	$(SRC_DIR)main.c

# PARSING_DIR			=	$(SRC_DIR)parsing/check_file.c \
# 						$(SRC_DIR)parsing/process_element.c \
# 						$(SRC_DIR)parsing/check_scenario.c \
# 						$(SRC_DIR)parsing/map_validation.c \
# 						$(SRC_DIR)parsing/map_check_charater_duplicate.c \
# 						$(SRC_DIR)parsing/map_allocation_filling.c \
# 						$(SRC_DIR)parsing/color_validation.c

# UTILS_DIR			=	$(SRC_DIR)utils/free_exit.c \
# 						$(SRC_DIR)utils/utils.c

# EXEC_DIR			=	$(SRC_DIR)execution/input.c \
# 						$(SRC_DIR)execution/ray_casting.c \
# 						$(SRC_DIR)execution/ray_cast_utils.c \
# 						$(SRC_DIR)execution/draw_texture.c

# INIT_DIR			=	$(SRC_DIR)init/init.c

# # Concatenate all source files
# SRCS 				=	$(MAIN_DIR) $(PARSING_DIR) $(UTILS_DIR) $(INIT_DIR) $(EXEC_DIR)

# # Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
# OBJS 				=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# start:
# 					@make all

# $(LIBFT):
# 					@make -C ./libraries/libft

# all: 				libmlx $(NAME)

# libmlx:
# 					@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# $(NAME): 			$(OBJS) $(LIBFT)
# 					@$(CC) $(OBJS) $(LIBFT) $(MLXFLAGS) $(INC) -o $(NAME)

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
# .PHONY: 			all, clean, fclean, re, libmlx

# Name
NAME				=	cub3D
NAME_BONUS			=	cub3D_bonus

# Directories
SRC_DIR				=	sources/
BONUS_DIR			=	sources_bonus/
BLD_DIR				=	build/
OBJ_DIR				=	./build/objects/
OBJ_BONUS_DIR		=	./build/objects_bonus/
LIBMLX				=	./libraries/MLX42
LIBFT				=	./libraries/libft/libft.a
INC					=	-I ./include -I $(LIBMLX)/include
INC_BONUS			=	-I ./include_bonus -I $(LIBMLX)/include

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
						$(SRC_DIR)parsing/map_validation.c \
						$(SRC_DIR)parsing/map_check_charater_duplicate.c \
						$(SRC_DIR)parsing/map_allocation_filling.c \
						$(SRC_DIR)parsing/color_validation.c

UTILS_DIR			=	$(SRC_DIR)utils/free_exit.c \
						$(SRC_DIR)utils/utils.c

EXEC_DIR			=	$(SRC_DIR)execution/input.c \
						$(SRC_DIR)execution/ray_casting.c \
						$(SRC_DIR)execution/ray_cast_utils.c \
						$(SRC_DIR)execution/draw_texture.c

INIT_DIR			=	$(SRC_DIR)init/init.c


# Bonus Source Files

MAIN_BONUS			=	$(BONUS_DIR)main.c

PARSING_BONUS		=	$(BONUS_DIR)parsing/check_file.c \
						$(BONUS_DIR)parsing/check_scenario.c \
						$(BONUS_DIR)parsing/color_validation.c \
						$(BONUS_DIR)parsing/doors.c \
						$(BONUS_DIR)parsing/linklist_xy_instance.c \
						$(BONUS_DIR)parsing/map_allocation_filling.c \
						$(BONUS_DIR)parsing/map_check_charater_duplicate.c \
						$(BONUS_DIR)parsing/map_validation.c \
						$(BONUS_DIR)parsing/process_element.c

UTILS_BONUS			=	$(BONUS_DIR)utils/free_exit.c \
						$(BONUS_DIR)utils/free.c \
						$(BONUS_DIR)utils/utils.c

EXEC_BONUS			=	$(BONUS_DIR)execution/choose_texture.c \
						$(BONUS_DIR)execution/draw_texture.c \
						$(BONUS_DIR)execution/input.c \
						$(BONUS_DIR)execution/mini_map.c \
						$(BONUS_DIR)execution/mouse_moved.c \
						$(BONUS_DIR)execution/ray_cast_utils.c \
						$(BONUS_DIR)execution/ray_casting.c \
						$(BONUS_DIR)execution/space_pressed.c

INIT_BONUS			=	$(BONUS_DIR)init/init.c \
						$(BONUS_DIR)init/init_animation.c

# Concatenate all source files
SRCS 				=	$(MAIN_DIR) $(PARSING_DIR) $(UTILS_DIR) $(INIT_DIR) $(EXEC_DIR)
SRCS_BONUS			=	$(MAIN_BONUS) $(PARSING_BONUS) $(UTILS_BONUS) $(EXEC_BONUS) $(INIT_BONUS)

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJS 				=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
OBJS_BONUS			=	$(patsubst $(BONUS_DIR)%.c,$(OBJ_BONUS_DIR)%.o,$(SRCS_BONUS))

all: 					libmlx $(NAME)

bonus: 					libmlx $(NAME_BONUS)

# Build the regular program
$(NAME): 				$(OBJS) $(LIBFT)
						@echo "Building $(NAME)"
						@$(CC) $(OBJS) $(LIBFT) $(MLXFLAGS) $(INC) -o $(NAME)

# Build the bonus program
$(NAME_BONUS): 			$(OBJS_BONUS) $(LIBFT)
						@echo "Building $(NAME_BONUS)"
						@$(CC) $(OBJS_BONUS) $(LIBFT) $(MLXFLAGS) $(INC_BONUS) -o $(NAME_BONUS)

# Compile regular object files
$(OBJ_DIR)%.o: 			$(SRC_DIR)%.c
						@echo "Compiling $< for $(NAME)"
						@mkdir -p $(@D)
						@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Compile bonus object files
$(OBJ_BONUS_DIR)%.o:	$(BONUS_DIR)%.c
						@echo "Compiling $< for $(NAME_BONUS)"
						@mkdir -p $(@D)
						@$(CC) $(CFLAGS) $(INC_BONUS) -c $< -o $@

# Build the MLX library
libmlx:
						@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# Build the libft library
$(LIBFT):
						@make -C ./libraries/libft

# Cleanup rules
clean:
						@echo "Cleaning..."
						@$(RM) -r $(OBJ_DIR)
						@$(RM) -r $(OBJ_BONUS)
						@$(RM) -r $(BLD_DIR)
						@$(RM) -r $(LIBMLX)/build
						@make clean -C ./libraries/libft

fclean: 				clean
						@echo "Removing binaries..."
						@$(RM) $(NAME)
						@$(RM) $(NAME_BONUS)
						@$(RM) $(LIBFT)
						@echo "All clean"

re: fclean all

.PHONY: all bonus clean fclean re libmlx