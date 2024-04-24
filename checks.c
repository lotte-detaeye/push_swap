/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:49:14 by lde-taey          #+#    #+#             */
/*   Updated: 2024/03/27 16:40:25 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkdups(t_stack *stack_a)
{
	t_stack	*tmp;

	while (stack_a)
	{
		tmp = stack_a;
		while (tmp->next)
		{
			tmp = tmp->next;
			if (tmp->nbr == stack_a->nbr)
				return (0);
		}
		stack_a = stack_a->next;
	}
	return (1);
}

// fix necessary here for input ./push_swap "7 8" "9 1"
int	check_digits(char *argv1)
{
	int	i;

	i = 0;
	while (argv1[i] != '\0')
	{
		if (ft_isdigit(argv1[i]) || argv1[i] == 32 || \
			(argv1[i] == '-' && ft_isdigit(argv1[i + 1])) || \
			(argv1[i] == '+' && ft_isdigit(argv1[i + 1])))
			i++;
		else
			return (0);
	}
	return (1);
}

int	checksorted(t_stack *stack_a)
{
	int	i;

	i = stack_a->nbr;
	while (stack_a->next)
	{
		stack_a = stack_a->next;
		if (i > stack_a->nbr)
			return (0);
		i = stack_a->nbr;
	}
	return (1);
}
