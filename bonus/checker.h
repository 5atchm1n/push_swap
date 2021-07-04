/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 22:31:41 by sshakya           #+#    #+#             */
/*   Updated: 2021/07/05 00:01:59 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_psdata
{
	struct s_stack	*a;
	struct s_stack	*b;
	int				size;
}				t_psdata;

typedef struct s_stack
{
	int				index;
	struct s_stack	*head;
	struct s_stack	*tail;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/*
** INIT
*/
t_psdata	ps_init_stack(int n, char **args);
void		ps_set_tail(t_stack *head);
int			ps_set(int argc, char **argv, t_psdata *stack);
/*
** MOVES
*/
void		ps_rotate(t_stack *list);
void		ps_swap(t_stack *list);
void		ps_swap_s(t_psdata *stack);
void		ps_reverse(t_stack *list);
t_stack		*ps_push(t_stack **src, t_stack *dest);
void		ps_rotate_r(t_psdata *list);
void		ps_reverse_r(t_psdata *list);
/*
** CHECKS
*/
int			ps_check_arg(char **args, int size);
int			ps_check(t_stack *stack);
int			ps_error(t_psdata stack);
int			ps_issorted(t_stack *stack);
/*
**	UTILS
*/
int			ps_size(t_stack *a);
int			ps_isdigit(int c);
double		ps_atoi(const char *str);
int			ps_limit(double num);
void		ps_clear(t_psdata stack);
void		*ps_clear_stack(t_stack *stack);
int			ps_strcmp(char *s1, char *s2);
int			ps_strlen(const char *s);

#endif
