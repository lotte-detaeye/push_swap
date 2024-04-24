/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:53:04 by lde-taey          #+#    #+#             */
/*   Updated: 2024/03/27 15:28:38 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

int	ft_atoi(const char *nptr)
{
	long long	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] != '\0' && nptr[i] >= 48 && nptr[i] <= 57)
	{
		result = result * 10 + nptr[i] - 48;
		i++;
	}
	if ((sign * result) > 2147483647 || (sign * result) < -2147483648)
		ft_error();
	return (sign * result);
}
