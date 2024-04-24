/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:53:04 by lde-taey          #+#    #+#             */
/*   Updated: 2024/04/19 12:14:18 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	ft_atoi_new(const char *nptr, t_stack *stack_a)
{
	long long	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	sign = sign_check(nptr[i]);
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] != '\0' && nptr[i] >= 48 && nptr[i] <= 57)
		result = result * 10 + nptr[i++] - 48;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if ((sign * result) > 2147483647 || (sign * result) < -2147483648 || \
		(nptr[i] != '\0'))
	{
		ft_free(&stack_a);
		ft_error();
	}
	return (sign * result);
}

int	ft_atoi_new_2(char *nptr, t_stack **stack_a, char ***arrayofarrays)
{
	long long	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	sign = sign_check(nptr[i]);
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] != '\0' && nptr[i] >= 48 && nptr[i] <= 57)
		result = result * 10 + nptr[i++] - 48;
	if ((sign * result) > 2147483647 || (sign * result) < -2147483648)
	{
		ft_free(stack_a);
		*stack_a = NULL;
		ft_free_arrays(*arrayofarrays);
		ft_error();
	}
	return (sign * result);
}

int	sign_check(char c)
{
	int	sign;

	sign = 1;
	if (c == '-')
		sign = sign * -1;
	return (sign);
}
/*
void display_array(char **arrayofarrays)
{
	int	i;
	
	i = 0;
	while(arrayofarrays[i] != NULL)
	{
		printf("%s\n", arrayofarrays[i]);
		i++;
	}
}*/