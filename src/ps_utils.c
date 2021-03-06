/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 03:42:38 by sshakya           #+#    #+#             */
/*   Updated: 2021/07/04 23:49:38 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_min(t_stack *a, int *index)
{
	int	min;

	*index = 0;
	if (a == NULL)
		return (0);
	min = a->index;
	while (a)
	{
		if (a->index < min)
		{
			min = a->index;
			*index = a->n;
		}
		a = a->next;
	}
	return (min);
}

int	ps_max(t_stack *a, int *index)
{
	int	max;

	*index = 0;
	if (a == NULL)
		return (0);
	max = a->index;
	while (a)
	{
		if (a->index > max)
		{
			max = a->index;
			*index = a->n;
		}
		a = a->next;
	}
	return (max);
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

int	ps_find_best(t_stack *stack)
{
	int		n;
	int		tot;

	n = stack->index;
	tot = stack->tot;
	while (stack)
	{
		if (tot > stack->tot)
		{
			n = stack->index;
			tot = stack->tot;
		}
		stack = stack->next;
	}
	return (n);
}
