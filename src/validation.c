/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:29:47 by ergrigor          #+#    #+#             */
/*   Updated: 2022/08/26 21:03:08 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	validation(char *av[], t_settings *settings)
{
	int	i;

	i = 1;
	while (av[i] && i <= 5)
	{
		if (av[i] == 0 || ft_atoi(av[i], settings) == 0)
			put_msg("Enter a valid arguments\n", 2, settings);
		i++;
	}
	settings->philo = ft_atoi(av[1], settings);
	settings->death_time = ft_atoi(av[2], settings);
	settings->eat_time = ft_atoi(av[3], settings);
	settings->sleep_time = ft_atoi(av[4], settings);
	if (av[5])
		settings->eat_max_count = ft_atoi(av[5], settings);
}
