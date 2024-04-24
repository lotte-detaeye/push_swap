/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:06:07 by lde-taey          #+#    #+#             */
/*   Updated: 2024/03/19 17:13:21 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	sa(t_stack **stack_a)
{
	int	temp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp = (*stack_a)->nbr;
	(*stack_a)->nbr = (*stack_a)->next->nbr;
	(*stack_a)->next->nbr = temp;
	write(1, "sa\n", 3);
}

// Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	sb(t_stack *stack_b)
{
	int	temp;

	if (!stack_b || !stack_b->next)
		return ;
	temp = stack_b->nbr;
	stack_b->nbr = stack_b->next->nbr;
	stack_b->next->nbr = temp;
	write(1, "sb\n", 3);
}

// sa and sb at the same time
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	if (!stack_a && !stack_b)
		return ;
	if (stack_a && stack_a->next)
	{
		temp = stack_a->nbr;
		stack_a->nbr = stack_a->next->nbr;
		stack_a->next->nbr = temp;
	}
	if (stack_b && stack_b->next)
	{
		temp = stack_b->nbr;
		stack_b->nbr = stack_b->next->nbr;
		stack_b->next->nbr = temp;
	}
	write(1, "ss\n", 3);
}

// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!*stack_b)
		return ;
	tmp = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = tmp;
	write(1, "pa\n", 3);
}

// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = tmp;
	write(1, "pb\n", 3);
}
