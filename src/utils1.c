/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:43:00 by ergrigor          #+#    #+#             */
/*   Updated: 2022/09/16 20:30:20 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (*str++)
		i++;
	return (i);
}

void	put_msg(char *str, int fd, t_settings *settings)
{
	write(fd, str, (int)(ft_strlen(str)));
	if (fd == 2)
	{
		free(settings);
		exit(0);
	}
}

int	ft_atoi(const char *str, t_settings *settings)
{
	int			is_negative;
	long int	res;

	res = 0;
	is_negative = 1;
	if (ft_strncmp(str, "-0", 2) == 0 || ft_strncmp(str, "+0", 2) == 0)
		put_msg("Number is incorrect", 2, settings);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		put_msg("Number is incorrect", 2, settings);
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		if ((res > INT_MAX && is_negative == 1)
			|| ((res * -1) < INT_MIN && is_negative == -1))
			put_msg("Number is incorrect", 2, settings);
		str++;
	}
	if (*str != '\0')
		put_msg("Number is incorrect", 2, settings);
	return (res * is_negative);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && i < n - 1 && str1[i])
		i++;
	return (str1[i] - str2[i]);
}
