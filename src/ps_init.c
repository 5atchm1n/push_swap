/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 04:18:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/26 04:23:44 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_pswap	*ps_set_head(t_pswap *list, char *head)
{
	list = malloc(sizeof(t_pswap));
	list->head = list;
	list->n = ft_atoi(head);
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

t_pswap *ps_init_stack_a(int n, char **stack)
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
		list->next->next = NULL;
		list->next->prev = list;
		list = list->next;
		i++;
	}
	ps_set_tail(list->head, list);
	return (list->head);
}
