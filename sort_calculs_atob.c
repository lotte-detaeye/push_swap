/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_calculs_atob.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:06:41 by lde-taey          #+#    #+#             */
/*   Updated: 2024/03/18 11:53:28 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// these functions calculate the number of rotations needed
int	case_ra_rb(t_stack **stack_a, t_stack **stack_b, int nbr)
{
	int	opnum;

	opnum = findplace_b(*stack_b, nbr);
	if (opnum < find_index(*stack_a, nbr))
		opnum = find_index(*stack_a, nbr);
	return (opnum);
}

int	case_rra_rb(t_stack **stack_a, t_stack **stack_b, int nbr)
{
	int	opnum;

	opnum = 0;
	if (find_index(*stack_a, nbr))
		opnum = stack_len(*stack_a) - find_index(*stack_a, nbr);
	opnum = opnum + findplace_b(*stack_b, nbr);
	return (opnum);
}

int	case_ra_rrb(t_stack **stack_a, t_stack **stack_b, int nbr)
{
	int	opnum;

	opnum = 0;
	if (findplace_b(*stack_b, nbr))
		opnum = stack_len(*stack_b) - findplace_b(*stack_b, nbr);
	opnum = opnum + find_index(*stack_a, nbr);
	return (opnum);
}

int	case_rra_rrb(t_stack **stack_a, t_stack **stack_b, int nbr)
{
	int	opnum;

	opnum = 0;
	if (findplace_b(*stack_b, nbr))
		opnum = stack_len(*stack_b) - findplace_b(*stack_b, nbr);
	if ((opnum < (stack_len(*stack_a) - find_index(*stack_a, nbr))) \
		&& find_index(*stack_a, nbr))
		opnum = stack_len(*stack_a) - find_index(*stack_a, nbr);
	return (opnum);
}
