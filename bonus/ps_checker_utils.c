/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 03:42:38 by sshakya           #+#    #+#             */
/*   Updated: 2021/07/04 01:14:50 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

double	ps_atoi(const char *str)
{
	int		sign;
	double	num;

	sign = 1;
	num = 0;
	while (*str)
	{
		if (*str == '-')
			sign = -1;
		if (*str == '-' || *str == '+')
			str++;
		if (ps_isdigit(*str))
		{
			num = num * 10 + (*str - '0');
			str++;
		}
		if (!(ps_isdigit(*str)))
			return (num * sign);
	}
	return (num * sign);
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

int	ps_issorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->index > temp->next->index)
			return (0);
		temp = temp->next;
	}
	return (1);
}
