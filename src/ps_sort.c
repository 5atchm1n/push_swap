/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 17:51:11 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/21 17:48:18 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_next(t_pswap *stack_a, int pivot)
{
	int		i;
	int		j;
	t_pswap	*temp;

	i = 0;
	j = 0;
	temp = stack_a->head;
	while (temp != NULL)
	{
		if (temp->n < pivot)
			break ;
		i++;
		temp = temp->next;
	}
	temp = stack_a->tail;
	while (temp != NULL)
	{
		if (temp->n < pivot)
			break ;
		j++;
		temp = temp->prev;
	}
	if (i < j)
		return (1);
	return (0);
}

void	ps_sort_pivots(t_pswap **stack_a, t_pswap **stack_b)
{
	int	i;
	int	size;
	int	*list_a;

	list_a = ps_set_pivots(*stack_a);
	size = ps_size(*stack_a);
	i = 0;
	while (i <= ps_npivots(size))
	{
		if ((*stack_a)->head->n < list_a[i])
			*stack_b = ps_push(stack_a, *stack_b, 'b');
		else if (ps_next(*stack_a, list_a[i]))
			ps_rotate(*stack_a, 'a');
		else
			ps_reverse(*stack_a, 'a');
		if (ps_islower(*stack_a, list_a[i]) == 0)
			i++;
	}
	free(list_a);
}

void	ps_sort_max(t_pswap **stack_a, t_pswap **stack_b)
{
	int	max;
	int	index;
	int	size;

	max = ps_max(*stack_a, &index);
	size = ps_size(*stack_a);
	while (size > 1)
	{
		if (index < size / 2)
			while ((*stack_a)->tail->n != max)
				ps_rotate(*stack_a, 'a');
		else
			while ((*stack_a)->tail->n != max)
				ps_reverse(*stack_a, 'a');
		*stack_b = ps_push(stack_a, *stack_b, 'b');
		size = ps_size(*stack_a);
	}
}

void	ps_pivot_sort(t_pswap **stack_a, t_pswap **stack_b)
{
	int	max;
	int	index;
	int	size;

	index = 0;
	while (ps_size(*stack_b) > 0)
	{
		size = ps_size(*stack_b);
		max = ps_max(*stack_b, &index);
		if (index < size / 2)
			while ((*stack_b)->head->n != max)
				ps_rotate(*stack_b, 'b');
		else
			while ((*stack_b)->head->n != max)
				ps_reverse(*stack_b, 'b');
		*stack_a = ps_push(stack_b, *stack_a, 'a');
	}
}
