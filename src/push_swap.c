/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:27:54 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/22 23:07:50 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_issorted(t_pswap *stack)
{
	t_pswap	*temp;

	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->n > temp->next->n)
			return (0);
		temp = temp->next;
	}
	return (1);
}

static void	ps_sort_three(t_pswap **stack_a)
{
	while (ps_issorted(*stack_a) == 0)
	{
		if ((*stack_a)->n > (*stack_a)->next->n
			&& (*stack_a)->next->n > (*stack_a)->tail->n)
			ps_swap(*stack_a, 'a');
		if ((*stack_a)->head->n > (*stack_a)->tail->n
			&& (*stack_a)->next->n > (*stack_a)->head->n)
			ps_reverse(*stack_a, 'a');
		if ((*stack_a)->head->n > (*stack_a)->tail->n
			&& (*stack_a)->head->n > (*stack_a)->next->n)
			ps_rotate(*stack_a, 'a');
		if (ps_issorted(*stack_a) == 0)
			ps_swap(*stack_a, 'a');
	}
}

void	ps_sort_five(t_pswap **stack_a, t_pswap **stack_b)
{
	int	i;
	int	size;
	int	*list_a;

	list_a = ps_set_pivots(*stack_a);
	size = ps_size(*stack_a);
	i = 0;
	while (i < ps_npivots(size))
	{
		if ((*stack_a)->head->n < list_a[i])
			*stack_b = ps_push(stack_a, *stack_b, 'b');
		else
			ps_rotate(*stack_a, 'a');
		if (ps_islower(*stack_a, list_a[i]) == 0)
			i++;
	}
	ps_sort_three(stack_a);
	ps_pivot_sort(stack_a, stack_b);
	free(list_a);
}

static void	ps_sort(t_pswap **stack_a, t_pswap **stack_b)
{	
	int	size;

	size = ps_size(*stack_a);
	if (size <= 3)
		ps_sort_three(stack_a);
	if (size > 3 && size <= 5)
		ps_sort_five(stack_a, stack_b);
	if (size > 5)
	{
		ps_sort_pivots(stack_a, stack_b);
		ps_sort_max(stack_a, stack_b);
		ps_pivot_sort(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_pswap	*stack_a;
	t_pswap	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (ps_error(stack_a));
	stack_a = ps_init_stack_a(argc, argv);
	if (stack_a == NULL)
		return (0);
	if (ps_check(stack_a))
		ps_sort(&stack_a, &stack_b);
	ps_clear(stack_a);
	ps_clear(stack_b);
	return (0);
}
