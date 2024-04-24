/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_calculs_btoa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:06:41 by lde-taey          #+#    #+#             */
/*   Updated: 2024/03/18 11:53:23 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// these functions calculate the number of rotations needed
int	case_ra_rb_toa(t_stack **stack_a, t_stack **stack_b, int nbr)
{
	int	opnum;

	opnum = findplace_a(*stack_a, nbr);
	if (opnum < find_index(*stack_b, nbr))
		opnum = find_index(*stack_b, nbr);
	return (opnum);
}

int	case_ra_rrb_toa(t_stack **stack_a, t_stack **stack_b, int nbr)
{
	int	opnum;

	opnum = 0;
	if (find_index(*stack_b, nbr))
		opnum = stack_len(*stack_b) - find_index(*stack_b, nbr);
	opnum = opnum + findplace_a(*stack_a, nbr);
	return (opnum);
}

int	case_rra_rb_toa(t_stack **stack_a, t_stack **stack_b, int nbr)
{
	int	opnum;

	opnum = 0;
	if (findplace_a(*stack_a, nbr))
		opnum = stack_len(*stack_a) - findplace_a(*stack_a, nbr);
	opnum = opnum + find_index(*stack_b, nbr);
	return (opnum);
}

int	case_rra_rrb_toa(t_stack **stack_a, t_stack **stack_b, int nbr)
{
	int	opnum;

	opnum = 0;
	if (findplace_a(*stack_a, nbr))
		opnum = stack_len(*stack_a) - findplace_a(*stack_a, nbr);
	if ((opnum < (stack_len(*stack_b) - find_index(*stack_b, nbr))) \
		&& find_index(*stack_b, nbr))
		opnum = stack_len(*stack_b) - find_index(*stack_b, nbr);
	return (opnum);
}
