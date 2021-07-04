/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 22:19:07 by sshakya           #+#    #+#             */
/*   Updated: 2021/07/04 23:56:20 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

static void	ps_init(t_psdata *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->size = 0;
}

static int	ps_do_move(t_psdata *stack, char *move)
{
	if (!ps_strcmp(move, "pa"))
		stack->a = ps_push(&stack->b, stack->a);
	else if (!ps_strcmp(move, "pb"))
		stack->b = ps_push(&stack->a, stack->b);
	else if (!ps_strcmp(move, "ra"))
		ps_rotate(stack->a);
	else if (!ps_strcmp(move, "rb"))
		ps_rotate(stack->b);
	else if (!ps_strcmp(move, "rra"))
		ps_reverse(stack->a);
	else if (!ps_strcmp(move, "rrb"))
		ps_reverse(stack->b);
	else if (!ps_strcmp(move, "rr"))
		ps_rotate_r(stack);
	else if (!ps_strcmp(move, "rrr"))
		ps_reverse_r(stack);
	else if (!ps_strcmp(move, "sa"))
		ps_swap(stack->a);
	else if (!ps_strcmp(move, "sb"))
		ps_swap(stack->b);
	else if (!ps_strcmp(move, "ss"))
		ps_swap_s(stack);
	else
		return (0);
	return (1);
}

int	ps_checker_moves(t_psdata *stack)
{
	char	move[4];
	int		i;
	int		n;

	i = 0;
	while (i < 4)
	{
		n = i;
		i += read(0, &move[i], 1);
		if (n == i)
			break ;
		if (move[n] == '\n')
		{
			move[n] = '\0';
			if (!ps_do_move(stack, move))
				return (ps_error(*stack));
			i = 0;
		}
	}
	if (i == 4)
		return (ps_error(*stack));
	return (1);
}

int	main(int argc, char **argv)
{
	t_psdata	stack;

	ps_init(&stack);
	if (argc < 2)
		return (0);
	if (ps_check_arg(argv, argc) == 0)
		return (ps_error(stack));
	if (ps_set(argc, argv, &stack) == 0)
		return (ps_error(stack));
	if (ps_checker_moves(&stack) == 0)
		return (0);
	if (ps_issorted(stack.a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ps_clear(stack);
	return (0);
}
