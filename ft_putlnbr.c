/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojoubout <ojoubout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:15:30 by ojoubout          #+#    #+#             */
/*   Updated: 2019/10/31 11:36:28 by ojoubout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_special_cases()
{
	char	*str;

	str = malloc(2);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char			*ft_ltoa(long n)
{
	int		count;
	char	*num;

	if (n == 0)
		return (ft_special_cases());
	count = ft_countdigits(n);
	if (!(num = malloc(count + 1)))
		return (NULL);
	num[count] = '\0';
	while (n)
	{
		num[--count] = n % 10 + 48;
		n /= 10;
	}
	return (num);
}

ssize_t ft_putlnbr(long n)
{
	char *s;

	s = ft_ltoa(n);
	s = ft_strprs(s);
	s = ft_strzero(s);
	return (ft_putstr(s));
}