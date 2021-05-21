/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 03:42:38 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/21 04:41:07 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_clear(t_pswap *list)
{
	t_pswap *temp;

	if (list == NULL)
		return ;
	while (list != NULL)
	{
		temp = list;
		free(list);
		list = temp->next;
	}
}

int	ps_error(t_pswap *list)
{
	ps_clear(list);
	write(1, "Error\n", 6);
	return (1);
}
