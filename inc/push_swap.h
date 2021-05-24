/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:51:36 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/24 02:41:49 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdint.h>
# include "libft/inc/libft.h"
# include <stdio.h>

typedef struct s_pswap
{
	int				n;
	struct s_pswap	*head;
	struct s_pswap	*tail;
	struct s_pswap	*next;
	struct s_pswap	*prev;
}					t_pswap;

/*
** UTIL FUNCTIONS
*/
int		ps_error(t_pswap *list);
void	ps_clear(t_pswap *list);
void	ps_swap(t_pswap *list);
void	my_print(t_pswap *list, int args);

#endif
