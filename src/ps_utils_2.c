/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 23:48:39 by sshakya           #+#    #+#             */
/*   Updated: 2021/07/04 23:49:35 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_size(t_stack *a)
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

int	ps_lower(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ps_limit(double num)
{
	if (num > 2147483647)
		return (0);
	if (num < -2147483648)
		return (0);
	return (1);
}

int	ps_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
