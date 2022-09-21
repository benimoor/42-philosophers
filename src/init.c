/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:57:02 by smikayel          #+#    #+#             */
/*   Updated: 2022/09/21 18:10:53 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	rfork(t_settings *rules, int index)
{
	if (index + 1 >= rules->philo)
		return (0);
	return (index + 1);
}

void	mutex_maker(t_settings *rules, pthread_mutex_t **mutexes, t_philo **philosophers, pthread_mutex_t **print)
{
	int				i;
	
	
	*mutexes = malloc(sizeof(pthread_mutex_t) * rules->philo);
	for(int i = 0; i < rules->philo; i++)
		printf("%p\n", &(*mutexes)[i]);
	*print = malloc(sizeof(pthread_mutex_t));
	*philosophers = malloc(sizeof(t_philo) * rules->philo);
	
	if (!*mutexes || !*philosophers || !*print)
		put_msg("Malloc Error", 2, rules);
}

long long int    current_timestamp(void)
{
    struct timeval    te;

    gettimeofday(&te, 0);
    return (te.tv_sec * 1000 + te.tv_usec / 1000);
}

void	print_action(char *str, t_philo *philo)
{
	pthread_mutex_lock(philo->rules->print);
	printf("%lld %d %s",current_timestamp() - philo->rules->start_time, philo->index + 1, str);
	pthread_mutex_unlock(philo->rules->print);
}

void	destroy_mutexs(pthread_mutex_t *mutex, int i)
{
	int l = 0;
	
	while (i >= l)
	{
		pthread_mutex_destroy(&mutex[l]);
		l++;
	}
}