/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 04:18:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/11 17:37:31 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_pswap	*ps_set_head(t_pswap *list, char *head)
{
	list = malloc(sizeof(t_pswap));
	list->head = list;
	list->n = ft_atoi(head);
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

t_pswap *ps_init_stack_a(int n, char **stack)
{
	t_pswap *list;
	int		i;

	list = NULL;
	list = ps_set_head(list, stack[1]);
	i = 2;
	while (i < n)
	{
		list->next = malloc(sizeof(t_pswap));
		list->next->head = list->head;
		list->next->n = ft_atoi(stack[i]);
		list->next->next = NULL;
		list->next->prev = list;
		list = list->next;
		i++;
	}
	ps_set_tail(list->head, list);
	return (list->head);
}

static void	ps_presort_list(int *list, int size)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (list[j] > list[j + 1])
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static int *ps_find_pivots(int *list, int size)
{
	int n;
	int i;
	int *keys;

	i = 0;
	n = size / 50 - 1;
	if (i <= 0)
	{
		keys = malloc(sizeof(int));
		keys[0] = list[size / 2];
		return (keys);
	}
	keys = malloc(sizeof(int) * n);
	while (n > 0)
	{
		keys[i] = list[n * 50];
		n--;
		i++;
	}
	free(list);
	return (keys);
}

int *ps_set_presort(t_pswap *a)
{
	int		size;
	int		*list;
	t_pswap *temp;
	int		i;

	temp = a;
	i = 0;
	size = 1;
	while (temp->next != NULL)
	{
		size++;
		temp = temp->next;
	}
	list = malloc(sizeof(int) * size);
	while (i < size)
	{
		list[i] = a->n;
		a = a->next;
		i++;
	}
	ps_presort_list(list, size);
	list = ps_find_pivots(list, size);
	return (list);
}
