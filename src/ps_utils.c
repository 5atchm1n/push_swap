/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 03:42:38 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/24 18:36:00 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_npivots(int size)
{
	int	n;

	n = 0;
	if (size < 30)
		n = 1;
	if (size >= 30 && size < 80)
		n = 2;
	if (size >= 80 && size < 200)
		n = 5;
	if (size >= 200)
		n = size / 50;
	return (n);
}

int	ps_size(t_pswap *a)
{
	int	size;

	size = 0;
	while (a != NULL)
	{
		size++;
		a = a->next;
	}
	return (size);
}

int	ps_islower(t_pswap *list, int key)
{
	while (list != NULL)
	{
		if (list->n < key)
			return (1);
		list = list->next;
	}
	return (0);
}

int	ps_min(t_pswap *a, int *index)
{
	int	min;

	if (a == NULL)
		return (0);
	min = a->n;
	while (a)
	{
		if (a->n < min)
		{
			min = a->n;
			*index = a->index;
		}
		a = a->next;
	}
	return (min);
}

int	ps_max(t_pswap *a, int *index)
{
	int	max;

	if (a == NULL)
		return (0);
	max = a->n;
	while (a)
	{
		if (a->n > max)
		{
			max = a->n;
			*index = a->index;
		}
		a = a->next;
	}
	return (max);
}
