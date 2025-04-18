/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:54:27 by fepennar          #+#    #+#             */
/*   Updated: 2025/04/02 18:24:50 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack		*create_content(int content);
t_stack		*ft_contlast(t_stack *lst);
void		add_content(t_stack **stack, t_stack *content);
void		ft_error_message(void);
void		skip_sign(const char *str, int *i, int *sign);
void		free_stack(t_stack **a);
void		free_split(char **split);
void		ft_push(t_stack **srcstack, t_stack **desttack, int sign);
void		ft_swap(t_stack **stack, int sign);
void		ft_rotate(t_stack **stack, int sign);
void		ft_revrotate(t_stack **stack, int sign);
void		ss(t_stack **a, t_stack **b);
void		ft_rr(t_stack **a, t_stack **b);
void		ft_rrr(t_stack **a, t_stack **b);
void		ft_radix_sort(t_stack **a);
void		index_assignation(t_stack *a);
void		ft_destroy(t_stack **a, char **split);
void		ft_s_destroy(t_stack **a);
void		ft_small_sort(t_stack **a);
int			check_valid_arg(char *str);
int			find_dup(t_stack *a);
int			ft_stacksize(t_stack *lst);
int			ft_check_sort(t_stack *a);
int			max(t_stack *a);
int			ft_isspace(char *str);
long		ft_atol(char *str, t_stack *a);
long		ft_atol2(char *str, t_stack *a, char **split);
#endif
