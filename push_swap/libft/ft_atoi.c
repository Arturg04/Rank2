/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <artur.13.goncalves@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:05:45 by Arturg04          #+#    #+#             */
/*   Updated: 2023/11/06 22:00:22 by ade-pinh         ###   ########.fr       */
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
		if (res > FT_INT_MAX)
			return (FT_INT_MAX_PLUS);
		if (res < FT_INT_MIN)
			return (FT_INT_MIN_PLUS);
		res = res * 10 + *(nptr++) - '0';
	}
	return (res * neg);
}
