/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:04:26 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/24 02:37:30 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ps_swap(t_pswap *list)
{
	int	n;

	n = list->n;
	if (list->next != NULL)
	{
		list->n = list->next->n;
		list->next->n = n;
	}
}
