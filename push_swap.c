/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:44:08 by lde-taey          #+#    #+#             */
/*   Updated: 2024/03/27 11:47:32 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2 || argv[1][0] == '\0')
		return (0);
	stack_a = init_stack(argc, argv);
	if (!stack_a || !ft_checkdups(stack_a))
	{
		ft_free(&stack_a);
		ft_error();
		return (0);
	}
	if (!checksorted(stack_a))
		sort_stack(&stack_a);
	ft_free(&stack_a);
	return (0);
}
