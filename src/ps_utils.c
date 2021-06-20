/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 03:42:38 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/20 14:08:47 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_npivots(int size)
{
	int	n;

	n = 0;
	if (size < 10)
		return (n);
	if (size >= 10 && size < 80)
		n = 3;
	if (size >= 80 && size < 200)
		n = 4;
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

void	ps_clear(t_pswap *list)
{
	t_pswap	*temp;
	t_pswap	*next;

	if (list == NULL)
		return ;
	temp = list;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	list = NULL;
}

int	ps_error(t_pswap *list)
{
	ps_clear(list);
	write(1, "Error\n", 6);
	return (1);
}
