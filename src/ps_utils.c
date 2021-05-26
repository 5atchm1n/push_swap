/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 03:42:38 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/26 04:39:05 by sshakya          ###   ########.fr       */
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

	head = list->head;
	while (list != NULL)
	{
		printf("%3d\t", list->n);
		printf("next = %10p\t prev = %10p\t", list->next, list->prev);
		printf("list = %10p\t %10p\n", list, list->tail);
		list = list->next;
	}
	list = head;
}
