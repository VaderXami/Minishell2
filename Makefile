##
## EPITECH PROJECT, 2017
## makefile
## File description:
## makefile
##

SRC	=	main.c				\
		functions/functions2.c		\
		functions/functions.c		\
		functions/my_str_word_tab.c	\
		functions/my_puterr.c		\
		functions/rb_epurstr.c		\
		functions/my_stris.c		\
		functions/my_stris2.c		\
		functions/my_word_tab_dstr.c	\
		src/pipe.c			\
		src/display_signals.c		\
		src/init_and_display.c		\
		src/my_redirection.c		\
		src/my_add_to_array.c		\
		src/my_remove_to_array.c	\
		src/my_env2.c			\
		src/my_env.c			\
		src/my_getenv.c			\
		src/my_setenv.c			\
		src/my_cd.c			\
		src/my_execpath.c		\
		src/my_execpath2.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

HEAD	=	-I./include

LDFLAGS	=	-lgnl -L./include -I.

CFLAGS	=	$(HEAD) -W -Wall -Wextra -g -g3 -ggdb

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o  $(NAME)	$(OBJ)	$(LDFLAGS)

clean:
	@echo -n "["
	@echo -n -e " \e[1;32mOK\e[0m "
	@echo -n "] "
	@echo -e "\e[1;31mRemoving OBJ files ...\e[0m"
	@$(RM) $(OBJ)
	@$(RM) *~ src/*~ functions/*~
	@$(RM) *.gcno
	@$(RM) $(SRC_UT_DIR)/*~
	@$(RM) $(SRC_UT_DIR)/*.gcno
	@$(RM) $(SRC_UT_DIR)/*.gcda


fclean:	clean
	@echo -n "[ "
	@echo -n -e "\e[1;32mOK\e[0m"
	@echo -n " ] "
	@echo -e "\e[1;31mDeleting binaries ...\e[0m"
	@$(RM) $(NAME)
	@$(RM) $(NAME_UT)

re:	fclean all

tests_run:
	make -C tests
	./tests/units
