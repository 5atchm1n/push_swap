NAME = push_swap

INC = push_swap.h

SRCS = push_swap.c

OBJDIR = objs
SRCDIR = src

CC = clang

CFLAGS = -Wall -Wextra -Werror

MEM = -fsanitize=address

OBJS = $(addprefix ${OBJDIR}/,${SRCS:.c=.o})

all: ${NAME}

libft:
	make -s -Cinc/libft

$(NAME): libft ${OBJS} 
	{CC} {CFLAGS} I./inc {INC} {OBJS} -o ${NAME}

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p ${@D}
	${CC} ${CFLAGS} -I./inc -c $< -o $@

