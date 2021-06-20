/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:51:36 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/20 14:09:50 by sshakya          ###   ########.fr       */
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
	int				index;
	struct s_pswap	*head;
	struct s_pswap	*tail;
	struct s_pswap	*next;
	struct s_pswap	*prev;
}					t_pswap;

/*
** INIT
*/
t_pswap	*ps_init_stack_a(int n, char **stack);
void	ps_set_tail(t_pswap *head);
/*
** MOVES
*/
void	ps_rotate(t_pswap *list, char stack);
void	ps_swap(t_pswap *list, char stack);
void	ps_reverse(t_pswap *list, char stack);
void	sort_small(t_pswap *a, t_pswap *b);
/*
** TESTING
*/

t_pswap	*ps_push(t_pswap **src, t_pswap *dest, char stack);
/*
**	UTILS
*/
int		*ps_set_presort(t_pswap *stack_a);
int		ps_error(t_pswap *list);
void	ps_clear(t_pswap *list);
void	my_print(t_pswap *list_a, t_pswap *list_b);
int		ps_max(t_pswap *list, int *index);
int		ps_min(t_pswap *list, int *index);
int		ps_islower(t_pswap *list, int key);
int		ps_size(t_pswap *a);
int		ps_npivots(int size);

#endif
