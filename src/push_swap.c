/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:27:54 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/20 23:27:19 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_pswap	*stack_a;
	t_pswap	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (ps_error(stack_a));
	if (argc == 2)
		return (0);
	stack_a = ps_init_stack_a(argc, argv);
	ps_sort_pivots(&stack_a, &stack_b);
	ps_sort_max(&stack_a, &stack_b);
	ps_pivot_sort(&stack_a, &stack_b);
	ps_clear(stack_a);
	ps_clear(stack_b);
	return (0);
}
