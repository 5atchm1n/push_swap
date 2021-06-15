/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:01:34 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/15 15:57:26 by sshakya          ###   ########.fr       */
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

void	sort_small(t_pswap *a, t_pswap *b)
{
	int min;
	int max;
	int	index;
	
	min = ps_min(a, &index);
	printf("index = %d, min = %d\n", index, min);
	min = ps_min(b, &index);
	printf("index = %d, min = %d\n", index, min);
	max = ps_max(a, &index);
	printf("index = %d, max = %d\n", index, max);
	max = ps_max(b, &index);
	printf("index = %d, max = %d\n", index, max);
}



