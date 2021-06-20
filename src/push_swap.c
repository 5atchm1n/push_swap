/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:27:54 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/20 17:39:46 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{

	t_pswap	*stack_a;
	t_pswap	*stack_b;
	int	size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (ps_error(stack_a));
	if (argc == 2)
		return (0);
	// SET STACK A
	stack_a = ps_init_stack_a(argc, argv);
	size = ps_size(stack_a);
	// PRE SORT STACK && FIND PIVOTS
	int i;
	int	*list_a;

	list_a = ps_set_pivots(stack_a);	
	i = 0;
	// SEND TO STACK_B
	while (i <= ps_npivots(size))
	{
		if (stack_a->head->n < list_a[i])
			stack_b = ps_push(&stack_a, stack_b, 'b');
		else
			ps_rotate(stack_a, 'a');
		if (ps_islower(stack_a, list_a[i]) == 0)
			i++;
	}
	// SEND LAST CHUNCK
	int max;
	int index;
	
	max = ps_max(stack_a, &index);
	size = ps_size(stack_a);
	while (size > 1)
	{
		if (index < size / 2)
			while (stack_a->tail->n != max)
				ps_rotate(stack_a, 'a');
		else
			while (stack_a->tail->n != max)
				ps_reverse(stack_a, 'a');
		stack_b = ps_push(&stack_a, stack_b, 'b');
		size = ps_size(stack_a);
	}
	// SORT AND SEND TO STACK A
	while (ps_size(stack_b) > 0)
	{
		size = ps_size(stack_b);
		max = ps_max(stack_b, &index);
		if (index < size / 2)
			while (stack_b->head->n != max)
				ps_rotate(stack_b, 'b');
		else
			while (stack_b->head->n != max)
				ps_reverse(stack_b, 'b');
		stack_a = ps_push(&stack_b, stack_a, 'a');
	}
	free(list_a);
	//my_print(stack_a, stack_b);
	ps_clear(stack_a);
	ps_clear(stack_b);
	return (0);
}
