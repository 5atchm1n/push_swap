/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 04:18:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/22 13:55:45 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_pswap	*ps_head(t_pswap *list, char *head)
{
	list = malloc(sizeof(t_pswap));
	list->head = list;
	list->index = 0;
	list->n = ft_atoi(head);
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

void	ps_set_tail(t_pswap *head)
{
	t_pswap	*temp;
	t_pswap	*tail;
	int		i;

	i = 1;
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	tail = temp;
	temp = head;
	while (temp != NULL)
	{
		temp->tail = tail;
		temp->index = i;
		temp = temp->next;
		i++;
	}
}

t_pswap	*ps_init_stack_a(int n, char **stack)
{
	t_pswap	*list;
	int		i;

	list = NULL;
	if (ps_check_arg(stack, n) == 0)
	{
		write(1, "Error\n", 6);
		return (NULL);
	}
	list = ps_head(list, stack[1]);
	i = 2;
	while (i < n)
	{
		list->next = malloc(sizeof(t_pswap));
		list->next->index = i - 1;
		list->next->head = list->head;
		list->next->n = ft_atoi(stack[i]);
		list->next->next = NULL;
		list->next->prev = list;
		list = list->next;
		i++;
	}
	ps_set_tail(list->head);
	return (list->head);
}
