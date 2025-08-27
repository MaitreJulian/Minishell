# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/03 11:33:48 by jowoundi          #+#    #+#              #
#    Updated: 2025/08/27 15:14:00 by jvenkata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

GREEN   = "\033[32m"
YELLOW  = "\033[33m"
NC      = "\033[0m"

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I ./header -I $(LIBFT_DIR)

SRC_DIR = src
OBJ_DIR = obj

# Source files
SRCS =	main.c lexer.c insert_node.c cleanex.c parsing.c find_type.c expander.c \
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

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

TOTAL_FILES := $(words $(SRCS))
CURRENT_FILE := 0

define progress_bar
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	@printf "\r$(YELLOW)Compiling minishell... [%-$(TOTAL_FILES)s] %d/%d $(NC)" \
	$$(for i in $$(seq 1 $(CURRENT_FILE)); do printf "#"; done) $(CURRENT_FILE) $(TOTAL_FILES)
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then echo ""; fi
endef

# Rule for .o (with subdirectories handling)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	$(call progress_bar)

LOGO = "\033[1;36m\
 __  __ _       _     _          _ _ \n\
|  \\/  (_)_ __ (_)___| |__   ___| | |\n\
| |\\/| | | '_ \\| / __| '_ \\ / _ \\ | |\n\
| |  | | | | | | \\__ \\ | | |  __/ | |\n\
|_|  |_|_|_| |_|_|___/_| |_|\\___|_|_|\n\
\033[0m"

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@printf $(LOGO)
	@echo "$(GREEN)Linking objects to create executable...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lreadline -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created!$(NC)"

$(LIBFT):
	@make -C $(LIBFT_DIR) -s

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean -s

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean -s

re: fclean all

.PHONY: all clean fclean re

