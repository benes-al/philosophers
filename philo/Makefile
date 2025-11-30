# **************************************************************************** #
#                               MAKEFILE CONFIG                                #
# **************************************************************************** #

# Program name
NAME        = philo

# Compiler and flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

# Source and object directories
SRC_DIR     = src
OBJ_DIR     = objects

# Include paths
PHILO_INC			= -Iincludes

# Source files (paths relative to SRC_DIR)
SRC_FILES = \
	eating.c \
	print_state_change.c \
	read_boolean_simulation_should_end.c \
	routine.c \
	sleeping.c \
	take_drop_forks.c \
	thinking.c \
	change_boolean_simulation_should_end.c \
	is_philo_alive.c \
	is_philo_satisfied.c \
	supervise.c \
	atoi_mod.c \
	cleanup.c \
	ft_error_exit.c \
	timestamp.c \
	check_args.c \
	create_threads.c \
	init_table.c \
	join_threads.c \
	main.c \

# Convert source files to object files with prefix
OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Tell make where to find source files
VPATH = src src/utils src/routine src/supervise

# **************************************************************************** #
#                                MAKE RULES                                    #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(PHILO_INC) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re