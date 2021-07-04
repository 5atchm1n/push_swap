/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 19:05:14 by sshakya           #+#    #+#             */
/*   Updated: 2021/07/03 21:25:02 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_sort_three(t_psdata *stack)
{
	while (ps_issorted(stack->a) == 0)
	{
		if (stack->a->index > stack->a->next->index
			&& stack->a->next->index > stack->a->tail->index)
			ps_swap(stack->a, 'a');
		if (stack->a->head->index > stack->a->tail->index
			&& stack->a->next->index > stack->a->head->index)
			ps_reverse(stack->a, 'a');
		if (stack->a->head->index > stack->a->tail->index
			&& stack->a->head->index > stack->a->next->index)
			ps_rotate(stack->a, 'a');
		if (ps_issorted(stack->a) == 0)
			ps_swap(stack->a, 'a');
	}
}

static void	ps_sort_four(t_psdata *stack)
{
	int	min;
	int	index;

	min = ps_min(stack->a, &index);
	if (index > 2)
		while (stack->a->index != min)
			ps_reverse(stack->a, 'a');
	else
		while (stack->a->index != min)
			ps_rotate(stack->a, 'a');
	stack->b = ps_push(&stack->a, stack->b, 'b');
	ps_sort_three(stack);
	stack->a = ps_push(&stack->b, stack->a, 'a');
}

static void	ps_sort_five(t_psdata *stack)
{
	int	i;

	i = 0;
	while (ps_size(stack->a) > 3)
	{
		if (stack->a->head->index < 2)
			stack->b = ps_push(&stack->a, stack->b, 'b');
		else
			ps_rotate(stack->a, 'a');
	}
	ps_sort_three(stack);
	while (stack->b)
	{
		if (stack->b->next && stack->b->index < stack->b->next->index)
			ps_rotate(stack->b, 'b');
		stack->a = ps_push(&stack->b, stack->a, 'a');
	}
}

void	ps_sort_small(t_psdata *stack)
{
	if (stack->size <= 3)
		ps_sort_three(stack);
	else if (stack->size <= 4)
		ps_sort_four(stack);
	else if (stack->size <= 5)
		ps_sort_five(stack);
}
