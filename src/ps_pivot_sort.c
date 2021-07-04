/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pivot_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Shakira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 16:21:54 by Shakira           #+#    #+#             */
/*   Updated: 2021/07/03 20:51:30 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_islower(t_stack *list, int key)
{
	while (list != NULL)
	{
		if (list->index < key)
			return (1);
		list = list->next;
	}
	return (0);
}

static int	ps_pivot_next(t_stack *stack_a, int pivot)
{
	int		i;
	int		j;
	t_stack	*temp;

	i = 0;
	j = 0;
	temp = stack_a->head;
	while (temp != NULL)
	{
		if (temp->index < pivot)
			break ;
		i++;
		temp = temp->next;
	}
	temp = stack_a->tail;
	while (temp != NULL)
	{
		if (temp->index < pivot)
			break ;
		j++;
		temp = temp->prev;
	}
	if (i < j)
		return (1);
	return (0);
}

int	ps_pivot_sort(t_psdata *stack)
{
	int	i;

	i = 0;
	while (i < ps_npivots(stack->size) - 1)
	{
		if (stack->a->head->index < stack->pivots[i])
		{
			stack->b = ps_push(&stack->a, stack->b, 'b');
			if (stack->b == NULL)
				return (0);
		}
		else if (ps_pivot_next(stack->a, stack->pivots[i]))
			ps_rotate(stack->a, 'a');
		else
			ps_reverse(stack->a, 'a');
		if (ps_islower(stack->a, stack->pivots[i]) == 0)
			i++;
	}
	return (1);
}
