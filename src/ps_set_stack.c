/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_set_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 04:11:30 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/20 12:12:29 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_pswap	*ps_new_head(t_pswap *list)
{
	t_pswap	*temp;
	int	i;

	temp = list;
	if (list == NULL)
		return (NULL);
	i = 0;
	while (temp != NULL)
	{
		temp->head = list;
		temp->index = i;
		temp = temp->next;
		i++;
	}
	return (list->head);
}

void	ps_set_tail(t_pswap *head)
{
	t_pswap	*temp;
	t_pswap	*tail;

	int	i;

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

static		t_pswap	*ps_head(t_pswap **src, t_pswap *dest, char stack)
{
	t_pswap *temp;
	
	temp = (*src)->head;
	dest = malloc(sizeof(t_pswap));
	dest->head = dest;
	dest->tail = dest;
	dest->index = 0;
	dest->n = (*src)->head->n;
	dest->next = NULL;
	dest->prev = NULL;
	*src = ps_new_head((*src)->next);
	free(temp);
	if (stack == 'a')
		write(1, "pa\n", 3);
	if (stack == 'b')
		write(1, "pb\n", 3);
	return (dest);
}

t_pswap *ps_push(t_pswap **src, t_pswap *dest, char stack)
{
	t_pswap *temp;

	if (*src == NULL)
		return (dest);
	if (dest == NULL)
		return(ps_head(src, dest, stack));
	dest->prev = malloc(sizeof(t_pswap));
	dest->prev->n = (*src)->n;
	dest->prev->next = dest;
	dest->prev->prev = NULL;
	dest = ps_new_head(dest->prev);
	ps_set_tail(dest);
	dest->head->n = (*src)->n;
	temp = (*src)->head;
	*src = ps_new_head((*src)->next);
	free(temp);
	if (stack == 'a')
		write(1, "pa\n", 3);
	if (stack == 'b')
		write(1, "pb\n", 3);
	return (dest->head);
}
