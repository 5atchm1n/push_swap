/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:27:54 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/15 16:07:00 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_size(t_pswap *a)
{
	int	size;

	size = 0;
	while (a != NULL)
	{
		size++;
		a = a->next;
	}
	return (size);
}

static int	ps_islower(t_pswap *list, int key)
{
	while (list != NULL)
	{
		if (list->n < key)
			return (1);
		list = list->next;
	}
	return (0);
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
	sort_small(stack_a, stack_b);
	
	int	*list;

	list = ps_set_presort(stack_a);	
	printf("stack_a = %p\n", stack_a);
	my_print(stack_a, stack_b);
	
	int i;

	i = 0;
	printf("list[0] = %d\n", list[0]);
	while (ps_islower(stack_a, list[0]))
	{
	//	if (stack_a->head->next->n > list[0] && stack_a->head->n < list[0])
	//		ps_swap(stack_a);
		if (stack_a->head->n < list[0])
			stack_b = ps_push(&stack_a, stack_b);
		else
			ps_rotate(stack_a);
		my_print(stack_a, stack_b);
	}

	free(list);
	list = ps_set_presort(stack_a);
	printf("list[0] = %d\n", list[0]);
	while (ps_islower(stack_a, list[0]))
	{
	//	if (stack_a->head->next->n > list[0] && stack_a->head->n < list[0])
	//		ps_swap(stack_a);
		if (stack_a->head->n < list[0])
			stack_b = ps_push(&stack_a, stack_b);
		else
			ps_rotate(stack_a);
		my_print(stack_a, stack_b);
	}
	free(list);
	list = ps_set_presort(stack_a);
	printf("list[0] = %d\n", list[0]);
	while (ps_islower(stack_a, list[0]))
	{
	//	if (stack_a->head->next->n > list[0] && stack_a->head->n < list[0])
	//		ps_swap(stack_a);
		if (stack_a->head->n < list[0])
			stack_b = ps_push(&stack_a, stack_b);
		else
			ps_rotate(stack_a);
		my_print(stack_a, stack_b);
	}
	free(list);
	int min;
	int index;

	min = ps_min(stack_a, &index);
	printf("index = %d, min = %d\n", index, min);
	if (index < size / 2)
		while (stack_a->head->n != min)
			ps_rotate(stack_a);
	else
		while (stack_a->head->n != min)
			ps_reverse(stack_a);
	my_print(stack_a, stack_b);
	
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
	/*
	printf("stack_b = %p\n", stack_b);
	my_print(stack_b);
	printf("stack_a = %p\n", stack_a);
	my_print(stack_a);
	*/
	stack_b = ps_push(&stack_a, stack_b);
	/*
	printf("stack_b = %p\n", stack_b);
	my_print(stack_b);
	printf("stack_a = %p\n", stack_a);
	my_print(stack_a);
	*/
	stack_b = ps_push(&stack_a, stack_b);
	/*
	printf("stack_b = %p\n", stack_b);
	my_print(stack_b);
	printf("stack_a = %p\n", stack_a);
	my_print(stack_a);
	*/
	
	ps_clear(stack_a);
	ps_clear(stack_b);
	//write(1, "Success\n", 6);
	return (0);
}
