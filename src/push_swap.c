/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:27:54 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/11 17:35:50 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_size(t_pswap *a)
{
	int	size;

	size = 0;
	while (a->next != NULL)
	{
		size++;
		a = a->next;
	}
	return (size);
}

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
	printf("%d\n", size);

	
	int	*list;

	list = ps_set_presort(stack_a);	
	printf("stack_a = %p\n", stack_a);
	my_print(stack_a);
	/*
	// TEST SWAP
	ps_swap(stack_a);
	my_print(stack_a);
	printf("stack_a = %p\n", stack_a);
	//TEST ROT
	ps_rotate(stack_a);
	my_print(stack_a);
	printf("stack_a = %p\n", stack_a);
	//TEST REV
	ps_reverse(stack_a);
	my_print(stack_a);
	printf("stack_a = %p\n", stack_a);
	my_print(stack_a);
	*/
	// TEST PUSH
	stack_b = ps_push(&stack_a, stack_b);
	printf("stack_b = %p\n", stack_b);
	my_print(stack_b);
	printf("stack_a = %p\n", stack_a);
	my_print(stack_a);
	stack_b = ps_push(&stack_a, stack_b);
	printf("stack_b = %p\n", stack_b);
	my_print(stack_b);
	printf("stack_a = %p\n", stack_a);
	my_print(stack_a);
	stack_b = ps_push(&stack_a, stack_b);
	printf("stack_b = %p\n", stack_b);
	my_print(stack_b);
	printf("stack_a = %p\n", stack_a);
	my_print(stack_a);

	
	ps_clear(stack_a);
	ps_clear(stack_b);
	write(1, "Success\n", 6);
	return (0);
}
