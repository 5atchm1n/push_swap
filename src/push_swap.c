/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:27:54 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/21 18:01:02 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_pswap	*ps_set_head(t_pswap *list, char *head)
{
	list = malloc(sizeof(t_pswap));
	list->head = list;
	list->i = 0;
	list->n = ft_atoi(head);
	list->tail = NULL;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

static t_pswap *ps_set_stack_a(int n, char **stack)
{
	t_pswap *list;
	int		i;

	i = 1;
	list = NULL;
	list = ps_set_head(list, stack[i]);
	i++;
	while (i < n)
	{
		list->next = malloc(sizeof(t_pswap));
		list->next->head = list->head;
		list->next->i = i;
		list->next->n = ft_atoi(stack[i]);
		list->next->tail = list->next;
		list->next->next = NULL;
		list->next->prev = list;
		list = list->next;
		i++;
	}
	return (list->head);
}

int	main(int argc, char **argv)
{
	t_pswap	*list;
	t_pswap	*head;

	list = NULL;
	if (argc < 2)
		return (ps_error(list));
	if (argc == 2)
		return (0);
	list = ps_set_stack_a(argc, argv);
	list = list->head;
	head = list->head;
	printf("%d\n", argc);
	for (int i = 1; i < argc; i++)
	{
		printf("%d\t %d\t", list->i, list->n);
		printf("%p\t %10p\t %p\n", list->next, list->prev, list->head);
		list = list->next;
	}
	/*
	ps_swap(head);
	for (int i = 1; i < argc; i++)
	{
		printf("%d\t %d\n", list->i, list->n);
		list = list->next;
	}
	*/
	ps_clear(head);
	write(1, "Success\n", 6);
	return (0);
}
