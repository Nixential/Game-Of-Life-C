# Compiler and compiling flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Name of the final executable
NAME = GameOfLife

# Source and object directories
SRC_DIR = srcs
OBJ_DIR = objs
INC_DIR = incs

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Rule to make everything
all: $(NAME)

# Rule for linking the program
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -I $(INC_DIR)

# Rule for compiling source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

# Rule to create the object directory
$(OBJ_DIR):
	mkdir -p $@

# Rule to clean object files
clean:
	rm -rf $(OBJ_DIR)

# Rule to full clean (objects and executable)
fclean: clean
	rm -f $(NAME)

# Rule to re-make everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
