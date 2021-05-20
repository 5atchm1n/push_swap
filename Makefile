NAME = push_swap

INC = push_swap.h

SRCS = push_swap.c

SRCDIR = src
OBJDIR = objs
INCDIR = inc

CC = clang
CFLAGS = -Wall -Wextra -Werror
MEM = -fsanitize=address

OBJS = $(addprefix ${OBJDIR}/,${SRCS:.c=.o})
NORM = $(addprefix ${SRCDIR}/,${SRCS})
NORM += $(addprefix ${INCDIR}/,${INC})

all: ${NAME}

libft:
	make -s -Cinc/libft

$(NAME): libft ${OBJS} 
	${CC} ${CFLAGS} -I./inc ${OBJS} -o ${NAME}

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p ${@D}
	${CC} ${CFLAGS} -I./inc -c $< -o $@

norm:
	norminette ${NORM}

clean:
	@make clean -s -Cinc/libft
	@rm -rf ${OBJDIR}

fclean: clean
	@make fclean -s -Cinc/libft
	@rm -rf ${NAME}

