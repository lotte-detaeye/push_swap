/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_execs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:37:42 by lde-taey          #+#    #+#             */
/*   Updated: 2024/03/18 11:52:09 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	apply_ra_rb(t_stack **stack_a, t_stack **stack_b, int nbr, char c)
{
	if (c == 'a')
	{
		while ((*stack_a)->nbr != nbr && findplace_b(*stack_b, nbr) != 0)
			rr(stack_a, stack_b);
		while ((*stack_a)->nbr != nbr)
			ra(stack_a);
		while (findplace_b(*stack_b, nbr) != 0)
			rb(stack_b);
		pb(stack_a, stack_b);
	}
	else
	{
		while ((*stack_b)->nbr != nbr && findplace_a(*stack_a, nbr) != 0)
			rr(stack_a, stack_b);
		while ((*stack_b)->nbr != nbr)
			rb(stack_b);
		while (findplace_a(*stack_a, nbr) != 0)
			ra(stack_a);
		pa(stack_a, stack_b);
	}
	return (-1);
}

int	apply_ra_rrb(t_stack **stack_a, t_stack **stack_b, int nbr, char c)
{
	if (c == 'a')
	{
		while ((*stack_a)->nbr != nbr)
			ra(stack_a);
		while (findplace_b(*stack_b, nbr) != 0)
			rrb(stack_b);
		pb(stack_a, stack_b);
	}
	else
	{
		while (findplace_a(*stack_a, nbr) != 0)
			ra(stack_a);
		while ((*stack_b)->nbr != nbr)
			rrb(stack_b);
		pa(stack_a, stack_b);
	}
	return (-1);
}

int	apply_rra_rb(t_stack **stack_a, t_stack **stack_b, int nbr, char c)
{
	if (c == 'a')
	{
		while ((*stack_a)->nbr != nbr)
			rra(stack_a);
		while (findplace_b(*stack_b, nbr) != 0)
			rb(stack_b);
		pb(stack_a, stack_b);
	}
	else
	{
		while (findplace_a(*stack_a, nbr) != 0)
			rra(stack_a);
		while ((*stack_b)->nbr != nbr)
			rb(stack_b);
		pa(stack_a, stack_b);
	}
	return (-1);
}

int	apply_rra_rrb(t_stack **stack_a, t_stack **stack_b, int nbr, char c)
{
	if (c == 'a')
	{
		while ((*stack_a)->nbr != nbr && findplace_b(*stack_b, nbr) != 0)
			rrr(stack_a, stack_b);
		while ((*stack_a)->nbr != nbr)
			rra(stack_a);
		while (findplace_b(*stack_b, nbr) != 0)
			rrb(stack_b);
		pb(stack_a, stack_b);
	}
	else
	{
		while ((*stack_b)->nbr != nbr && findplace_a(*stack_a, nbr) != 0)
			rrr(stack_a, stack_b);
		while ((*stack_b)->nbr != nbr)
			rrb(stack_b);
		while (findplace_a(*stack_a, nbr) != 0)
			rra(stack_a);
		pa(stack_a, stack_b);
	}
	return (-1);
}
