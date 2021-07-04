/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:04:26 by sshakya           #+#    #+#             */
/*   Updated: 2021/07/04 01:16:15 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ps_swap(t_stack *list)
{
	int	i;

	list = list->head;
	i = list->index;
	if (list->next != NULL)
	{
		list->index = list->next->index;
		list->next->index = i;
	}
}

void	ps_rotate(t_stack *list)
{
	int	i;

	i = list->index;
	if (list->next != NULL)
	{
		while (list->next != NULL)
		{
			list->index = list->next->index;
			list = list->next;
		}
		list->index = i;
	}
	list = list->head;
}

void	ps_rotate_r(t_psdata *stack)
{
	ps_rotate(stack->a);
	ps_rotate(stack->b);
}

void	ps_reverse(t_stack *list)
{
	int		i;
	t_stack	*tail;

	i = list->tail->index;
	tail = list->tail;
	while (tail->prev != NULL)
	{
		tail->index = tail->prev->index;
		tail = tail->prev;
	}
	list->index = i;
	list = list->head;
}

void	ps_reverse_r(t_psdata *stack)
{
	ps_reverse(stack->a);
	ps_reverse(stack->b);
}
