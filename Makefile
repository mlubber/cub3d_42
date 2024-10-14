# Name
NAME				= cub3d

# Directories
LIBFT				= ./libraries/libft/libft.a
LIBMLX				= ./libraries/MLX42
INC					= -I .include/ -I $(LIBMLX)/include
SRC_DIR				= sources/
BLD_DIR				= build/
OBJ_DIR				= ./build/objects/

# Compiler and CFlags
CC					= cc
CFLAGS				= -g -Wall -Werror -Wextra #-g -fsanitize=address
MLXFLAGS			= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
RM					= rm -f

# Source Files
MAIN_DIR			= $(SRC_DIR)main.c

# Concatenate all source files
SRCS 				= $(MAIN_DIR)

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules
start:
					@make all

$(LIBFT):
					@make -C ./libraries/libft

all: 				libmlx $(NAME)

libmlx:
					@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(MLXFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

# Compile object files from source files
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
.PHONY: 			start all clean fclean re