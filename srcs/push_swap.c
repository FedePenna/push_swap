/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:18:36 by fepennar          #+#    #+#             */
/*   Updated: 2025/04/02 19:18:40 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error_message(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

t_stack	*multargstack(int ac, char **av)
{
	int			i;
	t_stack		*a;
	long		nums;

	i = 1;
	a = NULL;
	while (i < ac)
	{
		if (check_valid_arg(av[i]) == 0)
			ft_s_destroy(&a);
		if (ft_isspace(av[i]) == 1)
			ft_s_destroy(&a);
		nums = ft_atol(av[i], a);
		add_content(&a, create_content((int)nums));
		i++;
	}
	return (a);
}

t_stack	*create_astack(int ac, char **av)
{
	t_stack	*a;
	int		i;
	long	nums;
	char	**m_matrix;

	a = NULL;
	i = -1;
	if (ac == 2)
	{
		m_matrix = ft_split(av[1], 32);
		while (m_matrix[++i])
		{
			if (check_valid_arg(m_matrix[i]) == 0)
				ft_destroy(&a, m_matrix);
			nums = ft_atol2(m_matrix[i], a, m_matrix);
			add_content(&a, create_content((int)nums));
		}
		free_split(m_matrix);
	}
	else
		a = multargstack(ac, av);
	return (a);
}

int	main(int ac, char **av)
{
	t_stack	*a;

	if (ac == 1 || av[1][0] == '\0')
		return (0);
	a = create_astack(ac, av);
	if (!a || find_dup(a) == 1)
	{
		free_stack(&a);
		ft_error_message();
	}
	if (ft_stacksize(a) <= 5 && !ft_check_sort(a))
		ft_small_sort(&a);
	else if (ft_check_sort(a) == 0)
	{
		index_assignation(a);
		ft_radix_sort(&a);
	}
	free_stack(&a);
	return (0);
}
