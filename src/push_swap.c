/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:27:54 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/24 02:40:11 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_pswap	*ps_set_head(t_pswap *list, char *head)
{
	list = malloc(sizeof(t_pswap));
	list->head = list;
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

	list = NULL;
	list = ps_set_head(list, stack[1]);
	i = 2;
	while (i < n)
	{
		list->next = malloc(sizeof(t_pswap));
		list->next->head = list->head;
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

	list = NULL;
	if (argc < 2)
		return (ps_error(list));
	if (argc == 2)
		return (0);
	list = ps_set_stack_a(argc, argv);
	my_print(list, argc);
	printf("%p\n", list);
	ps_swap(list);
	my_print(list, argc);
	list = list->head;
	ps_clear(list);
	write(1, "Success\n", 6);
	return (0);
}
