/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:57:02 by smikayel          #+#    #+#             */
/*   Updated: 2022/09/17 22:43:29 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	rfork(t_settings *rules, int index)
{
	if (index + 1 >= rules->philo)
		return (0);
	return (index + 1);
}

void	mutex_maker(t_settings *rules, pthread_mutex_t **mutexes)
{
	int				i;

	i = 0;
	while (i < rules->philo)
	{
		mutexes[i] = malloc(sizeof(pthread_mutex_t));
		if (pthread_mutex_init(mutexes[i], NULL) < 0)
			put_msg("Mutex Error", 2, rules);
		i++;
	}
}

long long int    current_timestamp(void)
{
    struct timeval    te;

    gettimeofday(&te, 0);
    return (te.tv_sec * 1000LL + te.tv_usec / 1000);
}

void	print_action(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->print);
	printf("%lld %d %s",current_timestamp(), philo->index + 1, str);
	pthread_mutex_unlock(&philo->rules->print);
}

void	destroy_mutexs(pthread_mutex_t **mutex, int i)
{

	int l = 0;
	pthread_mutex_t	*curr;

	curr = *mutex;
	while (i >= l)
	{
		pthread_mutex_destroy(&curr[l]);
		l++;
	}
}