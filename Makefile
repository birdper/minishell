NAME				= minishell
DEBUG_APP			= debug_minishell

C_FLAG				= -Wall -Werror -Wextra
DEBUG_FLAG			= -g

DIR_SRC				= src/
DIR_SRC_PARSER		= src/parser/
DIR_SRC_EXEC		= src/exec/
DIR_SRC_SUBSHELL	= src/subshell/

SOURCE_DIRS			:=	src \
						src/parser \
						src/exec \
						src/subshell

DIR_OBJ				= bin/
DIR_DEB_OBJ			= bin_debug/

INCLUDES			= includes
LIBFT_PATH			= libft

LIBFT				= libft.a
VPATH 				:= $(SOURCE_DIRS)

HEADERS				:= minishell.h

SRC_PARSER		:=	\
					parser.c				\
					signals.c				\
					split_cmd.c				\
					split_args.c			\
					pre_parser.c			\
					spec_symbols.c			\
					parse_utils.c			\
					parse_cmd.c				\
					parse_argv.c			\
					pre_parse_validate.c	\
					pre_parse_utils.c		\
					pre_parse_quotes_env.c	\
					signals.c				\
					parse_env_utils.c		\
					validate_symbols.c		\
					validate_env.c			\
					validate_cmd.c			\
					get_redirects.c			\
					input_buttons.c			\
					cmd_reader.c			\
					cmd_reader_utils.c		\
					libft_utils.c			\
					counter_utils.c			\
					skip_utils.c			\
					clear_utils.c			\
					dbl_lst.c				\
					intr_signals.c			\

SRC_EXEC		:=	\
					executor.c				\
					run_pipeline.c			\
					simple_command.c		\
					set_redirect.c			\
					outer_exec.c			\
					builtins.c				\
					b_echo.c				\
					b_pwd.c					\
					b_change_dir.c			\
					cd_update_pwd.c			\
					b_export.c				\
					b_unset.c				\
					b_env.c					\
					b_exit.c				\
					print_envp.c			\
					write_env.c				\
					dup2close.c				\
					print_err.c				\
					get_paths.c				\
					validate_key.c			\
					is_notnumber.c			\

SRC_SUBSHELL	:=	\
					init_subshell.c			\
					update_shlvl.c			\
					export_envp.c			\
					set_status.c			\
					get_ptr_env.c			\
					get_env_value.c			\
					get_env_key.c			\
					set_value_by_key.c		\
					insert_env.c			\

SRC				:=	\
					main.c					\
					exec_args.c				\



OBJ					:= $(SRC:c=o)
OBJ_PARSER			:= $(SRC_PARSER:c=o)
OBJ_EXEC			:= $(SRC_EXEC:c=o)
OBJ_SUBSHELL		:= $(SRC_SUBSHELL:c=o)
DEBUG_OBJ			:= $(SRC:c=o)

SRC					:= $(addprefix $(DIR_SRC), $(SRC))
SRC_PARSER			:= $(addprefix $(DIR_SRC_PARSER), $(SRC_PARSER))
SRC_EXEC			:= $(addprefix $(DIR_SRC_EXEC), $(SRC_EXEC))
SRC_SUBSHELL		:= $(addprefix $(DIR_SRC_SUBSHELL), $(SRC_SUBSHELL))
#SRC					+= $(addprefix $(DIR_SRC_EXEC), $(SRC))
OBJ					:= $(addprefix $(DIR_OBJ), $(OBJ))
OBJ_PARSER			:= $(addprefix $(DIR_OBJ), $(OBJ_PARSER))
OBJ_EXEC			:= $(addprefix $(DIR_OBJ), $(OBJ_EXEC))
OBJ_SUBSHELL		:= $(addprefix $(DIR_OBJ), $(OBJ_SUBSHELL))
DEBUG_OBJ			:= $(addprefix $(DIR_DEB_OBJ), $(DEBUG_OBJ))


$(DIR_OBJ)%.o:		$(DIR_SRC)%.c $(INCLUDES)/$(HEADERS)
	gcc $(C_FLAG) -c $< -o $@ -I$(INCLUDES)

$(DIR_OBJ)%.o:		$(DIR_SRC_PARSER)%.c $(INCLUDES)/$(HEADERS)
	gcc $(C_FLAG) -c $< -o $@ -I$(INCLUDES)

$(DIR_OBJ)%.o:		$(DIR_SRC_EXEC)%.c $(INCLUDES)/$(HEADERS)
	gcc $(C_FLAG) -c $< -o $@ -I$(INCLUDES)

$(DIR_OBJ)%.o:		$(DIR_SRC_SUBSHELL)%.c $(INCLUDES)/$(HEADERS)
	gcc $(C_FLAG) -c $< -o $@ -I$(INCLUDES)

#$(DIR_OBJ)%.o:		$(DIR_SRC_EXEC)%.c $(INCLUDES)/$(HEADERS)
#	gcc $(C_FLAG) -c $< -o $@ -I$(INCLUDES)

$(DIR_DEB_OBJ)%.o:	$(DIR_SRC)%.c $(INCLUDES)/$(HEADERS)
	@gcc -g -c $< -o $@ -I$(INCLUDES)


all:			$(LIBFT) $(NAME)

debug:			$(LIBFT) $(DEBUG_APP)



$(NAME):		$(OBJ) $(OBJ_PARSER) $(OBJ_EXEC) $(OBJ_SUBSHELL)
	gcc $(C_FLAG) $^ -L. -lft -ltermcap -o $(NAME)


$(DEBUG_APP):	$(DEBUG_OBJ)
	gcc -g $^ -L. -lft -ltermcap -o $(DEBUG_APP)


$(LIBFT):
	cp -f libft/libft.h includes/libft.h
	mkdir -p bin
	mkdir -p bin_debug
	@$(MAKE) -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)/$(LIBFT) .

clean:
	@make clean -C $(LIBFT_PATH)
	rm -rf $(DIR_OBJ) $(DIR_DEB_OBJ)
	rm -f $(OBJ) $(OBJ_EXEC) $(OBJ_PARSER) $(OBJ_SUBSHELL)
	rm -f $(DEBUG_OBJ)
	rm -f $(LIBFT)

fclean:			clean
	$(MAKE) fclean -C $(LIBFT_PATH)
	rm -f $(NAME) 
	rm -f $(DEBUG_APP)

re:				fclean all

.PHONY:			clean fclean re
