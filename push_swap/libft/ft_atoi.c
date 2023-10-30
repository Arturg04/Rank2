/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:05:45 by Arturg04          #+#    #+#             */
/*   Updated: 2023/10/28 15:50:06 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoi(const char *nptr)
{
	long long int	res;
	long long int	neg;

	res = 0;
	neg = 1;
	while (*nptr == ' ' || (*nptr > 8 && *nptr < 14))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr++ == '-')
			neg = -neg;
	}
	while (ft_isdigit(*nptr))
	{
		if (res > (FT_INT_MAX_PLUS / 10)
			|| (res == FT_INT_MAX_PLUS / 10 && *nptr > '7'))
		{
			if (neg > 0)
				return (FT_INT_MAX_PLUS);
			return (FT_INT_MIN_PLUS);
		}
		res = res * 10 + *(nptr++) - '0';
	}
	return (res * neg);
}
