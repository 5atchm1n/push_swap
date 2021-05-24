NAME = push_swap

INC = push_swap.h

SRCS = push_swap.c \
	   ps_utils.c \
	   ps_moves.c

LIBFT = inc/libft/libft.a

SRCDIR = src
OBJDIR = objs
INCDIR = inc

CC = clang
CFLAGS = -Wall -Wextra -Werror -g
MEM = -fsanitize=address

OBJS = $(addprefix ${OBJDIR}/,${SRCS:.c=.o})
NORM = $(addprefix ${SRCDIR}/,${SRCS})
NORM += $(addprefix ${INCDIR}/,${INC})

all: ${NAME}

libft:
	make -s -Cinc/libft

$(NAME): libft ${OBJS} 
	${CC} ${CFLAGS} ${MEM} ${OBJS} ${LIBFT} -o ${NAME}

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p ${@D}
	${CC} ${CFLAGS} -I./inc -c $< -o $@

re: fclean all

norm:
	norminette ${NORM}

clean:
	@make clean -s -Cinc/libft
	@rm -rf ${OBJDIR}

fclean: clean
	@make fclean -s -Cinc/libft
	@rm -rf ${NAME}

