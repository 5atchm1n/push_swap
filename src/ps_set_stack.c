/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_set_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 04:11:30 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/29 11:51:04 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_pswap	*ps_new_head(t_pswap *list)
{
	t_pswap	*temp;

	temp = list;
	while (temp != NULL)
	{
		temp->head = list;
		temp = temp->next;
	}
	return (list->head);
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

static		t_pswap	*ps_head(t_pswap **src, t_pswap *dest)
{
	t_pswap *temp;
	
	temp = (*src)->head;
	dest = malloc(sizeof(t_pswap));
	dest->head = dest;
	dest->tail = dest;
	dest->n = (*src)->head->n;
	dest->next = NULL;
	dest->prev = NULL;
	*src = ps_new_head((*src)->next);
	free(temp);
	return (dest);
}

t_pswap *ps_push(t_pswap **src, t_pswap *dest)
{
	t_pswap *temp;

	if (*src == NULL)
		return (dest);
	if (dest == NULL)
		return(ps_head(src, dest));
	dest->prev = malloc(sizeof(t_pswap));
	dest->prev->n = (*src)->n;
	dest->prev->next = dest;
	dest->prev->prev = NULL;
	ps_set_tail(dest->head, dest->prev);
	dest = ps_new_head(dest->prev);
	dest->head->n = (*src)->n;
	temp = (*src)->head;
	*src = ps_new_head((*src)->next);
	free(temp);
	return (dest->head);
}
