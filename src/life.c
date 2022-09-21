/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:21:30 by smikayel          #+#    #+#             */
/*   Updated: 2022/09/21 18:28:55 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void	my_usleep(int ms)
{
	double start_sleep = current_timestamp();

	while (current_timestamp() - start_sleep < ms)
	;
	// struct timeval start;
	// struct timeval now;
	// gettimeofday(&start, 0);
	// gettimeofday(&now, 0);
	// while((now.tv_sec - start.tv_sec) * 1000 + (now.tv_usec - start.tv_usec) / 1000 <= ms)
	// {
	// 	usleep(10);
	// 	gettimeofday(&now,0);
	// }
}

void	create_philo(t_philo *philo, pthread_mutex_t *mutexes)
{
	int i;
	pthread_t thread;

	i = 0;
	while (i < philo->rules->philo)
	{
		pthread_mutex_init(&mutexes[i], NULL);
		philo[i].lfork = &mutexes[i];
		philo[i].rfork = &mutexes[rfork(philo->rules, i)];
		philo[i].last_eat_time = current_timestamp();
		if (pthread_create(&thread, NULL, life, (void *)&(philo[i])) < 0)
			put_msg("Philo create error", 2, philo->rules);
		pthread_detach(thread);
		i++;
	}
}

void	*life(void *philo)
{
	if (((t_philo*)philo)->index % 2 == 0)
		usleep(100);
	
	((t_philo*)philo)->rules->start_time = current_timestamp();
	while (1)
	{
		eat(philo);
	}
	return 0;
}