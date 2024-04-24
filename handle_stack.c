/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:24:34 by lde-taey          #+#    #+#             */
/*   Updated: 2024/04/17 18:57:44 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_numbers(t_stack *stack_a)
{
	int	counter;

	if (!stack_a)
		return (0);
	counter = 1;
	while (stack_a->next)
	{
		stack_a = stack_a->next;
		counter++;
	}
	return (counter);
}

void	display_list(t_stack *stack)
{
	printf("Stack elements: ");
	while (stack != NULL) 
	{
		printf("%ld ", stack->nbr);
		stack = stack->next;
	}
	printf("\n");
}

t_stack	*create_node(int data)
{
	t_stack	*new_node;

	new_node = malloc(sizeof (t_stack));
	if (!new_node)
		return (NULL);
	new_node->nbr = data;
	new_node->next = NULL;
	return (new_node);
}

void	addtobackstack(t_stack **stack, t_stack *node)
{
	t_stack	*tmp;

	if (!stack || !node)
		return ;
	if (!*stack)
		*stack = node;
	else
	{
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = node;
	}
}
