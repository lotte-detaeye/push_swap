/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:35:03 by lde-taey          #+#    #+#             */
/*   Updated: 2024/04/19 12:16:12 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_parsetwoargs(char *argv1)
{
	t_stack	*stack_a;
	char	**arrayofarrays;
	int		i;
	int		data;
	char	**temp;

	if (argv1 == NULL)
		return (NULL);
	stack_a = NULL;
	data = 0;
	if (!check_digits(argv1))
		return (NULL);
	arrayofarrays = ft_split(argv1, ' ');
	i = 0;
	temp = arrayofarrays;
	while (arrayofarrays[i] != NULL)
	{
		data = ft_atoi_new_2(arrayofarrays[i], &stack_a, &temp);
		addtobackstack(&stack_a, create_node(data));
		i++;
	}
	ft_free_arrays(temp);
	return (stack_a);
}

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	int		data;

	i = 1;
	stack_a = NULL;
	if (argc < 2)
		return (0);
	else if (argc == 2)
		return (ft_parsetwoargs(argv[1]));
	else
	{
		while (argv[i])
		{
			if (!check_digits(argv[i]))
			{
				ft_free(&stack_a);
				return (NULL);
			}
			data = ft_atoi_new(argv[i], stack_a);
			addtobackstack(&stack_a, create_node(data));
			i++;
		}
		return (stack_a);
	}
}
