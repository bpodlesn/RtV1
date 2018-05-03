/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:32:52 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/04/17 17:07:40 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atoi1(char *str, int *k)
{
	int	s;
	int	r;

	r = 0;
	s = 1;
	while (str[*k] >= 0 && str[*k] <= 32)
		(*k)++;
	if (str[*k] <= '0' && str[*k] >= '9')
	{
		while (str[*k] != '\0' || str[*k] != '\n' || str[*k] != ' ')
			(*k)++;
		return (0);
	}
	if (str[*k] == '-')
		s = -1;
	if (str[*k] == '+' || str[*k] == '-')
		(*k)++;
	while (str[*k] && str[*k] >= '0' && str[*k] <= '9')
	{
		if (str[*k] == '\0')
			return (s * r);
		r = r * 10 + str[*k] - '0';
		(*k)++;
	}
	return (s * r);
}
