/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 03:42:38 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/24 02:38:55 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_clear(t_pswap *list)
{
	t_pswap *temp;
	t_pswap *next;

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

void	my_print(t_pswap *list, int args)
{
	for (int i = 1; i < args; i++)
	{
		printf("%3d\t", list->n);
		printf("%10p  %10p\t %10p\n", list->next, list->prev, list->head);
		list = list->next;
	}
}
