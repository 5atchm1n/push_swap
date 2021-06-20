NAME = push_swap

INC = push_swap.h

SRCS = push_swap.c \
	   ps_init.c \
	   ps_presort.c \
	   ps_sort.c \
	   ps_myprint.c \
	   ps_utils.c \
	   ps_push.c \
	   ps_moves.c

LIBFT = -L./inc/libft -lft

SRCDIR = src
OBJDIR = objs
INCDIR = inc

CC = clang
CFLAGS = -Wall -Wextra -Werror -g
CFLAGS += -MMD -MP
MEM = -fsanitize=address

OBJS = $(addprefix ${OBJDIR}/,${SRCS:.c=.o})
NORM = $(addprefix ${SRCDIR}/,${SRCS})
NORM += $(addprefix ${INCDIR}/,${INC})

DEP = ${OBJS:.o=.d}

all: ${NAME}

libft:
	@make -s -Cinc/libft

$(NAME): libft ${OBJS} 
	@echo -n "Compiling push_swap"
	@${CC} ${CFLAGS} ${MEM} ${OBJS} -o $@ ${LIBFT}
	@echo "\033[32m\t\t[OK]\033[0m"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p ${@D}
	@${CC} ${CFLAGS} -I./inc -c $< -o $@

re: fclean all

norm:
	norminette ${NORM}

clean:
	@make clean -s -Cinc/libft
	@echo -n "Cleaning push_swap objects"
	@rm -rf ${OBJDIR}
	@echo "\033[32m\t[OK]\033[0m"

fclean: clean
	@make fclean -s -Cinc/libft
	@echo -n "Removing push_swap"
	@rm -rf ${NAME}
	@echo "\033[32m\t\t[OK]\033[0m"

.PHONY : all clean re fclean norm

-include ${DEP}
