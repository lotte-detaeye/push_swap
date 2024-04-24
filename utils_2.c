/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:46:07 by lde-taey          #+#    #+#             */
/*   Updated: 2024/03/19 16:56:47 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// this function finds the right place for the number in stack b. there
// are three options: - either nbr is already right between the two right 
// values when pushed on top of stack b. 
// - nbr can also be the new max or min nbr of stack_b
// - and then there are all the other cases
int	findplace_b(t_stack *stack_b, int nbr)
{
	t_stack	*temp;
	int		pos;

	pos = 1;
	if (nbr > stack_b->nbr && nbr < find_last(stack_b)->nbr)
		pos = 0;
	else if (nbr > find_max(stack_b) || nbr < find_min(stack_b))
		pos = find_index(stack_b, find_max(stack_b));
	else
	{
		temp = stack_b->next;
		while (stack_b->nbr < nbr || temp->nbr > nbr)
		{
			stack_b = stack_b->next;
			temp = stack_b->next;
			pos++;
		}
	}
	return (pos);
}

int	findplace_a(t_stack *stack_a, int nbr)
{
	t_stack	*temp;
	int		pos;

	pos = 1;
	if (nbr < stack_a->nbr && nbr > find_last(stack_a)->nbr)
		pos = 0;
	else if (nbr > find_max(stack_a) || nbr < find_min(stack_a))
		pos = find_index(stack_a, find_min(stack_a));
	else
	{
		temp = stack_a->next;
		while (!(nbr > stack_a->nbr && nbr < temp->nbr))
		{
			stack_a = stack_a->next;
			temp = stack_a->next;
			pos++;
		}
	}
	return (pos);
}

void	setrightindex(t_stack **stack_a)
{
	int	index;

	index = find_index(*stack_a, find_min(*stack_a));
	if ((stack_len(*stack_a) - index) < index)
	{
		while ((*stack_a)->nbr != find_min(*stack_a))
			rra (stack_a);
	}
	else
	{
		while ((*stack_a)->nbr != find_min(*stack_a))
			ra (stack_a);
	}
}
