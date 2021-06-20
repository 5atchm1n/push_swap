/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_myprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 13:53:46 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/20 13:54:35 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
