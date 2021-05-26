/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:04:26 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/26 03:55:52 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap(t_pswap *list)
{
	int	n;

	n = list->n;
	if (list->next != NULL)
	{
		list->n = list->next->n;
		list->next->n = n;
	}
	list = list->head;
}

void	ps_rotate(t_pswap *list)
{
	int	n;
	n = list->n;
	if (list->next != NULL)
	{
		while (list->next != NULL)
		{
			list->n = list->next->n;
			list = list->next;
		}
		list->n = n;
	}
	list = list->head;
}

void	ps_reverse(t_pswap *list)
{
	int	n;
	t_pswap *tail;

	n = list->tail->n;
	tail = list->tail;
	while (tail->prev != NULL)
	{
		tail->n = tail->prev->n;
		tail = tail->prev;
	}
	list->n = n;
}
