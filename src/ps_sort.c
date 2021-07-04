/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 17:51:11 by sshakya           #+#    #+#             */
/*   Updated: 2021/07/03 19:18:43 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_quick_sort(t_psdata *stack)
{
	if (stack->size > 100)
		ps_pivot_sort(stack);
	while (ps_size(stack->a) != 1 && ps_issorted(stack->a) == 0)
	{
		if (stack->a->index > stack->a->tail->index)
			ps_rotate(stack->a, 'a');
		stack->b = ps_push(&stack->a, stack->b, 'b');
		if (stack->b == NULL)
			return (0);
	}
	return (1);
}

int	ps_insert_sort(t_psdata *stack)
{
	t_moves	moves;

	while (stack->b != NULL)
	{
		ps_set_moves(stack, &moves);
		while (moves.rr-- > 0)
			ps_rotate_r(stack, 'r');
		while (moves.rrr-- > 0)
			ps_reverse_r(stack, 'r');
		while (moves.ra-- > 0)
			ps_rotate(stack->a, 'a');
		while (moves.rb-- > 0)
			ps_rotate(stack->b, 'b');
		while (moves.rra-- > 0)
			ps_reverse(stack->a, 'a');
		while (moves.rrb-- > 0)
			ps_reverse(stack->b, 'b');
		stack->a = ps_push(&stack->b, stack->a, 'a');
		if (stack->a == NULL)
			return (0);
	}
	return (1);
}

int	ps_sort(t_psdata *stack)
{
	int		index;

	if (ps_issorted(stack->a))
		return (1);
	if (stack->size <= 5)
		ps_sort_small(stack);
	if (stack->size > 5)
	{
		if (!ps_quick_sort(stack))
			return (0);
		if (!ps_insert_sort(stack))
			return (0);
		ps_max(stack->a, &index);
		while (!ps_issorted(stack->a))
		{
			if (index < stack->size / 2)
				ps_rotate(stack->a, 'a');
			else
				ps_reverse(stack->a, 'a');
		}
	}
	return (1);
}
