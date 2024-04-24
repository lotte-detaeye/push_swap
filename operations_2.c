/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:51:47 by lde-taey          #+#    #+#             */
/*   Updated: 2024/03/19 17:13:31 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	ra(t_stack **stack_a)
{
	t_stack	*tmp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = find_last(*stack_a);
	(*stack_a)->next = tmp;
	*stack_a = tmp->next;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rb(t_stack **stack_b)
{
	t_stack	*tmp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	*stack_b = find_last(*stack_b);
	(*stack_b)->next = tmp;
	*stack_b = tmp->next;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

// rr : ra and rb at the same time.
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!*stack_a || !(*stack_a)->next || !*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_a;
	*stack_a = find_last(*stack_a);
	(*stack_a)->next = tmp;
	*stack_a = tmp->next;
	tmp->next = NULL;
	tmp = *stack_b;
	*stack_b = find_last(*stack_b);
	(*stack_b)->next = tmp;
	*stack_b = tmp->next;
	tmp->next = NULL;
	write(1, "rr\n", 3);
}
