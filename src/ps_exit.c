/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:46:27 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/28 13:07:58 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_limit(double num)
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

int	ps_check_arg(char **args, int size)
{
	int		i;
	int		j;
	double	n;

	i = 1;
	while (i < size)
	{
		n = ps_atoi(args[i]);
		if (!ps_limit(n))
			return (0);
		if (args[i][0] == '\0')
			return (0);
		j = 0;
		while (args[i][j] != '\0')
		{
			if (!ps_isdigit(args[i][j]) && args[i][j] != '-')
				return (0);
			if (args[i][j] == '-' && !ps_isdigit(args[i][j + 1]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ps_check(t_pswap *stack)
{
	t_pswap	*temp;
	t_pswap	*head;

	head = stack->head;
	while (stack->next != NULL)
	{
		temp = stack->next;
		while (temp != NULL)
		{
			if (stack->n == temp->n)
			{
				write (1, "Error\n", 6);
				return (0);
			}
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (1);
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
