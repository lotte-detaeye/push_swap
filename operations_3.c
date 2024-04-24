/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:45:43 by lde-taey          #+#    #+#             */
/*   Updated: 2024/03/19 16:46:08 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rra(t_stack **stack_a)
{
	t_stack	*temp;
	int		i;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	i = 0;
	while ((*stack_a)->next)
	{
		*stack_a = (*stack_a)->next;
		i++;
	}
	(*stack_a)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	write(1, "rra\n", 4);
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	rrb(t_stack **stack_b)
{
	t_stack	*temp;
	int		i;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	temp = *stack_b;
	i = 0;
	while ((*stack_b)->next)
	{
		*stack_b = (*stack_b)->next;
		i++;
	}
	(*stack_b)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	write(1, "rrb\n", 4);
}

//rrr : rra and rrb at the same time
static void	rrr_for_a(t_stack **stack_a)
{
	int		i;
	t_stack	*temp;

	temp = *stack_a;
	i = 0;
	while ((*stack_a)->next)
	{
		*stack_a = (*stack_a)->next;
		i++;
	}
	(*stack_a)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
}

void	rrr(t_stack	**stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		i;

	if (!*stack_a || !(*stack_a)->next || !*stack_b || !(*stack_b)->next)
		return ;
	temp = *stack_b;
	i = 0;
	while ((*stack_b)->next)
	{
		*stack_b = (*stack_b)->next;
		i++;
	}
	(*stack_b)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	rrr_for_a(stack_a);
	write(1, "rrr\n", 4);
}
