/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:46:27 by sshakya           #+#    #+#             */
/*   Updated: 2021/07/02 02:15:19 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ps_check(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*head;

	head = stack->head;
	while (stack->next != NULL)
	{
		temp = stack->next;
		while (temp != NULL)
		{
			if (stack->n == temp->n)
				return (0);
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (1);
}

void	*ps_clear_stack(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*next;

	if (stack == NULL)
		return (NULL);
	temp = stack;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	return (NULL);
}

void	ps_clear(t_psdata stack)
{
	ps_clear_stack(stack.a);
	ps_clear_stack(stack.b);
	free(stack.list);
	free(stack.pivots);
}

int	ps_error(t_psdata stack)
{
	ps_clear(stack);
	write(2, "Error\n", 6);
	return (0);
}
