/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 03:42:38 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/20 13:31:12 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ps_npivots(int size)
{
	int	n;
	
	n = 0;
	if (size < 10)
		return (n);
	if (size >= 10 && size < 80)
		n = 3;
	if (size >= 80 && size < 200)
		n = 4;
	if (size >= 200)
		n = size / 50;
	return (n);
}

int	ps_size(t_pswap *a)
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

int	ps_islower(t_pswap *list, int key)
{
	while (list != NULL)
	{
		if (list->n < key)
			return (1);
		list = list->next;
	}
	return (0);
}

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
	fprintf(stderr, "| stack_a |\t| stack_b |\n");
	while (list_a != NULL || list_b != NULL)
	{
		if (list_a != NULL)
			fprintf(stderr, "A|%3d|%6d|\t", list_a->index, list_a->n);
		if (list_a == NULL)
			fprintf(stderr, "A|(0)|(null)|\t");
		if (list_b != NULL)
			fprintf(stderr, "B|%3d|%6d|\n", list_b->index, list_b->n);
		if (list_b == NULL)
			fprintf(stderr, "B|(0)|(null)|\n");
		   if (list_b != NULL)
		   {
		   printf("N = %14p | P = %14p | ", list_b->next, list_b->prev);
		   printf("L = %14p | T = %14p | H = %14p\n", list_b, list_b->tail, list_b->head);
		   }
		if (list_a)
			list_a = list_a->next;
		if (list_b)
			list_b = list_b->next;
	}
}
