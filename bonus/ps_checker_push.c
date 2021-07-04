/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 04:11:30 by sshakya           #+#    #+#             */
/*   Updated: 2021/07/04 00:02:52 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_stack	*ps_set_head(t_stack *list)
{
	t_stack	*temp;

	temp = list;
	if (list == NULL)
		return (NULL);
	while (temp != NULL)
	{
		temp->head = list;
		temp = temp->next;
	}
	list->head->prev = NULL;
	return (list->head);
}

static t_stack	*ps_head(t_stack **src, t_stack *dest)
{
	t_stack	*temp;

	temp = (*src)->head;
	dest = malloc(sizeof(t_stack));
	if (dest == NULL)
		return (NULL);
	dest->head = dest;
	dest->tail = dest;
	dest->index = (*src)->index;
	dest->next = NULL;
	dest->prev = NULL;
	*src = ps_set_head((*src)->next);
	free(temp);
	return (dest);
}

t_stack	*ps_push(t_stack **src, t_stack *dest)
{
	t_stack	*temp;

	if (*src == NULL)
		return (dest);
	if (dest == NULL)
		return (ps_head(src, dest));
	dest->prev = malloc(sizeof(t_stack));
	if (dest->prev == NULL)
		return (ps_clear_stack(dest->head));
	dest->prev->index = (*src)->index;
	dest->prev->next = dest;
	dest->prev->prev = NULL;
	dest = ps_set_head(dest->prev);
	ps_set_tail(dest);
	temp = (*src)->head;
	*src = ps_set_head((*src)->next);
	free(temp);
	return (dest->head);
}
