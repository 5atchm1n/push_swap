NAME = push_swap

BNAME = checker

INC = push_swap.h

SRCS = ps_push_swap.c \
	   ps_init.c \
	   ps_next.c \
	   ps_exit.c \
	   ps_presort.c \
	   ps_sort.c \
	   ps_sort_small.c \
	   ps_pivot_sort.c \
	   ps_utils.c \
	   ps_utils_2.c \
	   ps_push.c \
	   ps_moves.c

BONUS = ps_checker.c \
		ps_checker_init.c \
		ps_checker_exit.c \
	    ps_checker_utils.c \
	    ps_checker_utils_2.c \
	    ps_checker_push.c \
	    ps_checker_moves.c

SRCDIR = src
B_SRCDIR = bonus
OBJDIR = objs
INCDIR = inc

CC = clang
CFLAGS = -Wall -Wextra -Werror
#MEM = -fsanitize=address

OBJS = $(addprefix ${OBJDIR}/,${SRCS:.c=.o})
BOBJS = $(addprefix ${OBJDIR}/,${BONUS:.c=.o})

all: ${NAME}

$(NAME): ${OBJS} 
	${CC} ${CFLAGS} ${MEM} ${OBJS} -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p ${@D}
	${CC} ${CFLAGS} -I./inc -c $< -o $@

$(OBJDIR)/%.o: $(B_SRCDIR)/%.c
	@mkdir -p ${@D}
	${CC} ${CFLAGS} -I./${B_SRCDIR} -c $< -o $@

bonus : ${BNAME}

$(BNAME): ${BOBJS}
	${CC} ${CFLAGS} ${MEM} ${BOBJS} -o $@


re: fclean all

clean:
	@echo  "Cleaning objects\c"
	@rm -rf ${OBJDIR}
	@echo "\033[32m\t[OK]\033[0m"

fclean: clean
	@echo  "Removing push_swap\c"
	@rm -rf ${NAME} ${BNAME}
	@echo "\033[32m\t[OK]\033[0m"

.PHONY : all clean re fclean bonus
