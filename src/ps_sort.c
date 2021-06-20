/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:01:34 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/20 13:52:56 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_min(t_pswap *a, int *index)
{
	int min;

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
	int max;

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
