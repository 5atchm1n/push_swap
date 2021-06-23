/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:46:27 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/23 22:03:26 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ps_check_arg(char **args, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
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

int	ps_error(t_pswap *list)
{
	ps_clear(list);
	write(1, "Error\n", 6);
	return (1);
}
