/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 03:42:38 by sshakya           #+#    #+#             */
/*   Updated: 2021/07/04 01:16:04 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ps_swap_s(t_psdata *stack)
{
	int	temp;

	temp = stack->a->index;
	stack->a->index = stack->b->index;
	stack->b->index = temp;
}

int	ps_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ps_strcmp(char *s1, char *s2)
{
	int	l1;
	int	l2;
	int	i;

	l1 = ps_strlen(s1);
	l2 = ps_strlen(s2);
	i = 0;
	if (l1 != l2)
		return (1);
	while (i < l1)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}
