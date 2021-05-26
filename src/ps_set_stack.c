/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_set_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 04:11:30 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/26 05:05:23 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_set_head(t_pswap *list)
{
	t_pswap	*temp;

	temp = list;
	while (temp != NULL)
	{
		temp->head = list;
		temp = temp->next;
	}
}

void	ps_set_tail(t_pswap *head, t_pswap *tail)
{
	t_pswap	*temp;

	temp = head;
	while (temp != NULL)
	{
		temp->tail = tail;
		temp = temp->next;
	}
}

void	ps_push(t_pswap **a, t_pswap **b)
{
	t_pswap *temp;

	temp = *a;
	if (*b == NULL)
	{
		*b = *a;
		(*b)->next = NULL;
		(*a)->next = temp->next;
	}
	else
	{
		(*b)->prev = *a;
		(*a)->next = temp->next;
		ps_set_head((*b)->prev);
	}
}
