# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/03 11:33:48 by jowoundi          #+#    #+#              #
#    Updated: 2025/08/28 18:11:50 by jvenkata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address
GREEN   = "\\033[32m"
YELLOW	= "\\033[33m"
NC      = "\\033[0m"

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I ./header -I $(LIBFT_DIR)

SRC_DIR = src/
OBJ_DIR = obj/

# Source files from the src directory
SRCS = main.c lexer.c insert_node.c cleanex.c parsing.c find_type.c expander.c fill_structure.c \
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

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

TOTAL_FILES := $(words $(SRCS))
CURRENT_FILE := 0

define progress_bar
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	@printf "\r$(YELLOW)Compiling michel... [%-$(TOTAL_FILES)s] %d/%d $(NC)" \
	$$(for i in $$(seq 1 $(CURRENT_FILE)); do printf "#"; done) $(CURRENT_FILE) $(TOTAL_FILES)
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES)  ]; then echo ""; fi
endef

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	$(call progress_bar)


LOGO = "\033[5;36m\
Michel\n\
\033[0m"


all:  $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@printf $(LOGO)
	@echo "$(GREEN)Linking objects to create executable...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lreadline -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created!$(NC)"

$(LIBFT):
	@make -C $(LIBFT_DIR) -s

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re test
