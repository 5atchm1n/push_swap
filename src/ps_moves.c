/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:04:26 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/21 18:03:59 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ps_swap(t_pswap *list)
{
	t_pswap *temp;

	list = list->head;
	if (list->next != NULL)
	{
		temp = list;
		list = temp->next;
		list->next = temp;
		list->head = list;
		list->next->prev = list;
	}
	temp = list->head;
	while (list != NULL && i < 5)
	{
		list->head = temp;
		list = list->next;
		i++;
	}
}
