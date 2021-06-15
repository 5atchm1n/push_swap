/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 03:42:38 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/15 15:41:17 by sshakya          ###   ########.fr       */
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

void	my_print(t_pswap *list_a, t_pswap *list_b)
{
	t_pswap	*head;

	head = list_a->head;
	printf("| stack_a |\t| stack_b |\n");
	while (list_a != NULL || list_b != NULL)
	{
		if (list_a != NULL)
			printf("A|%3d|%6d|\t", list_a->index, list_a->n);
		if (list_b != NULL)
			printf("B|%3d|%6d|\n", list_b->index, list_b->n);
		if (list_a == NULL)
			printf("A|(0)|(null)|\t");
		if (list_b == NULL)
			printf("B|(0)|(null)|\n");
		//printf("N = %14p | P = %14p | ", list->next, list->prev);
		//printf("L = %14p | T = %14p | H = %14p\n", list, list->tail, list->head);
		if (list_a)
			list_a = list_a->next;
		if (list_b)
			list_b = list_b->next;
	}
}
