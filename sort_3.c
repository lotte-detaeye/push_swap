/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:26:36 by lde-taey          #+#    #+#             */
/*   Updated: 2024/03/18 11:44:11 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	if ((*stack_a)->nbr == find_max(*stack_a) && !checksorted(*stack_a))
	{
		ra(stack_a);
		if ((*stack_a)->nbr > (*stack_a)->next->nbr)
			sa(stack_a);
	}
	else if ((*stack_a)->nbr == find_min(*stack_a) && !checksorted(*stack_a))
	{
		rra(stack_a);
		sa(stack_a);
	}
	else
	{
		if (find_index(*stack_a, find_max(*stack_a)) == 2)
			sa(stack_a);
		else
			rra(stack_a);
	}
}
