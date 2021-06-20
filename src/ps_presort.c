/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_presort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:01:34 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/20 17:42:04 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_presort_list(int *list, int size)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (list[j] > list[j + 1])
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	*ps_find_pivots(int *list, int size)
{
	int	n;
	int	i;
	int	*keys;

	i = 0;
	n = ps_npivots(size);
	if (n == 0)
		return (NULL);
	keys = malloc(sizeof(int) * n);
	if (keys == NULL)
		return (NULL);
	while (i < n)
	{
		keys[i] = list[(int)(i * (size / n))];
		i++;
	}
	free(list);
	return (keys);
}

int	*ps_set_pivots(t_pswap *a)
{
	int		size;
	int		*list;
	int		i;

	i = 0;
	size = ps_size(a);
	list = malloc(sizeof(int) * size);
	if (list == NULL)
		return (NULL);
	while (i < size)
	{
		list[i] = a->n;
		a = a->next;
		i++;
	}
	ps_presort_list(list, size);
	list = ps_find_pivots(list, size);
	return (list);
}
