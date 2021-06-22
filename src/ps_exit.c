/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:46:27 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/22 17:18:51 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if (!ft_isdigit(args[i][j]) && !ft_isspace(args[i][j])
				&& args[i][j] != '-')
				return (0);
			if (args[i][j] == '-' && !ft_isdigit(args[i][j + 1]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_pswap	*ps_check(t_pswap *stack)
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
				return (NULL);
			}
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (head);
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
