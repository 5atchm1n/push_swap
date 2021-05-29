/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 03:42:38 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/29 10:47:52 by sshakya          ###   ########.fr       */
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

void	my_print(t_pswap *list)
{
	t_pswap	*head;
	int		index;

	head = list->head;
	index = 0;
	while (list != NULL)
	{
		printf("|%3d|", list->n);
		printf("N = %14p | P = %14p | ", list->next, list->prev);
		printf("L = %14p | T = %14p | H = %14p\n", list, list->tail, list->head);
		list = list->next;
		index++;
	}
	list = head;
}
