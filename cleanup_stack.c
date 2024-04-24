/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:26:11 by lde-taey          #+#    #+#             */
/*   Updated: 2024/04/19 12:16:27 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack != NULL)
	{
		tmp = (*stack)->next;
		(*stack)->nbr = 0;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	ft_free_arrays(char **arrayofarrays)
{
	int		i;

	i = 0;
	while (arrayofarrays[i] != NULL)
	{
		free(arrayofarrays[i]);
		arrayofarrays[i] = NULL;
		i++;
	}
	free(arrayofarrays); 
	arrayofarrays = NULL;
}
