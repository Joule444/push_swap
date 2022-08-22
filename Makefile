# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jules <jules@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 16:02:47 by jthuysba          #+#    #+#              #
#    Updated: 2022/08/22 20:57:39 by jules            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES:=	main ft_atoi ft_split grab lst_fonctions lst_index lst_init lst_previous push bubble_sort rev_rotate rotate swap check_sorted split_stack
FILES_BONUS:=

NAME:= push_swap
BONUS:=

# ------------------
CC:=clang
SRCPATH:=./
BONUSPATH:=
HDRPATH:=include/
CCHPATH:=obj/
CCHPATH_BONUS:=obj/
IFLAGS:=-I ${HDRPATH}
CFLAGS:=-Wall -Wextra -Werror -g3 ${IFLAGS}
# ==================

# ----- Colors -----
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
# ==================

# ------ Auto ------
SRC:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
SRC_BONUS:=$(addprefix $(BONUSPATH),$(addsuffix .c,$(FILES_BONUS)))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
OBJ_BONUS:=$(addprefix $(CCHPATH_BONUS),$(addsuffix .o,$(FILES_BONUS)))
# ==================
CCHF:=.cache_exists

all: ${NAME} ${BONUS}

${NAME}: ${OBJ}
	@echo ${CYAN} " - Compiling $@" $(RED)
	@${CC} ${CFLAGS} ${SRC} -o ${NAME}
	@echo $(GREEN) " - OK" $(EOC)

${CCHPATH}%.o: ${SRCPATH}%.c | ${CCHF}
	@echo ${PURPLE} " - Compiling $< into $@" ${EOC}
	@${CC} ${CFLAGS} -c $< -o $@

# ${BONUS}: ${OBJ_BONUS}
# 	@echo ${CYAN} " - Compiling $@" $(RED)
# 	@${CC} ${CFLAGS} ${SRC_BONUS} -o ${BONUS}
# 	@echo $(GREEN) " - OK" $(EOC)

# ${CCHPATH_BONUS}%.o: ${BONUSPATH}%.c | ${CCHF}
# 	@echo ${PURPLE} " - Compiling $< into $@" ${EOC}
# 	@${CC} ${CFLAGS} -c $< -o $@

%.c:
	@echo ${RED}"Missing file : $@" ${EOC}

$(CCHF):
	@mkdir $(CCHPATH)
	@touch $(CCHF)

clean:
	@rm -rf ${CCHPATH}
	@rm -f ${CCHF}

fclean:	clean
	@rm -f ${NAME}
	@rm -f ${BONUS}
	@rm -rf ${NAME}.dSYM/
	@rm -rf ${BONUS}.dSYM/

re:	fclean
	@${MAKE} all

.PHONY:	all clean fclean re