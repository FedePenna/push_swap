/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:22:56 by fepennar          #+#    #+#             */
/*   Updated: 2025/04/16 16:22:57 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atol2(char *str, t_stack *a, char **split)
{
	long	n;
	int		sign;
	int		i;

	n = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		if (n > 2147483648 || n < -2147483649)
			ft_destroy(&a, split);
		i++;
	}
	return (n * sign);
}

void	ft_destroy(t_stack **a, char **split)
{
	if (a)
		free_stack(a);
	if (split)
		free_split(split);
	ft_error_message();
}

void	ft_s_destroy(t_stack **a)
{
	if (a)
		free_stack(a);
	ft_error_message();
}
