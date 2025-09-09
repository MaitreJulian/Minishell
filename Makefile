# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/03 11:33:48 by jowoundi          #+#    #+#              #
#    Updated: 2025/09/09 16:30:13 by jowoundi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

# Colors
GREEN   = "\033[32m"
YELLOW	= "\033[33m"
NC      = "\033[0m"

# Libft
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I ./header -I $(LIBFT_DIR)

# Dirs
SRC_DIR = src
OBJ_DIR = obj

# Source files (relative to SRC_DIR)
SRCS =	main.c lexer.c insert_node.c cleanex.c parsing.c find_type.c expander.c fill_structure.c \
		ft_getenv.c \
		split_space.c \
		fill_struct_utils.c \
		pars_utils.c \
		handle_error.c \
		builtins/ft_cd.c \
		builtins/ft_echo.c \
		builtins/ft_env.c \
		builtins/ft_exportc.c \
		builtins/ft_pwd.c \
		builtins/ft_unset.c \
		builtins/ft_exit.c \
		built_in.c \
		copy_env.c \
		pipeline.c \
		ft_exeve.c \
		ft_exec_builtin.c \
		pipeornot.c \
		make_cmd_list.c \
		free.c \
		red_spec.c \
		redirection.c \
		utils.c \
		signals.c

# Expand with SRC_DIR prefix
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

# Objects in OBJ_DIR
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Progress bar
TOTAL_FILES := $(words $(SRCS))
CURRENT_FILE := 0
define progress_bar
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	@printf "\r$(YELLOW)Compiling minishell... [%-$(TOTAL_FILES)s] %d/%d $(NC)" \
	$$(for i in $$(seq 1 $(CURRENT_FILE)); do printf "#"; done) $(CURRENT_FILE) $(TOTAL_FILES)
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES)  ]; then echo ""; fi
endef

# Compilation rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	$(call progress_bar)

# Logo
LOGO = "\033[5;36mMinishell\033[0m"

# Main rules
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo -e $(LOGO)
	@echo -e $(GREEN)"Linking objects to create executable..."$(NC)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lreadline -o $(NAME)
	@echo -e $(GREEN)"Executable $(NAME) created!"$(NC)

$(LIBFT):
	@make -C $(LIBFT_DIR) -s

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re
