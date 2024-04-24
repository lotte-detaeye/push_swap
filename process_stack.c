/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:20:28 by lde-taey          #+#    #+#             */
/*   Updated: 2024/03/19 17:13:42 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (count_numbers(*stack_a) == 2)
		sa(stack_a);
	else if (count_numbers(*stack_a) == 3)
		sort_three(stack_a);
	else
		sort_bigstack(stack_a, &stack_b);
}
