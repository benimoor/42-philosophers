/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:21:30 by smikayel          #+#    #+#             */
/*   Updated: 2022/09/17 18:22:26 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*create_philo(t_settings *rules, pthread_mutex_t **mutexes, int i, pthread_t *thread)
{
	t_philo	*philo;
	pthread_mutex_t *mutex;

	mutex = *mutexes;
	philo = malloc(sizeof(t_philo));
	if (!philo)
		put_msg("Philo create error", 2, rules);
	philo->index = i;
	philo->mode = 1;
	philo->lfork = &mutex[i];
	philo->rfork = &mutex[rfork(rules, i)];
	philo->rules = rules;
	philo->last_eat_time = -1;
	i = 0;
	if (pthread_create(&thread[i], NULL, life, (void *)philo) < 0)
		put_msg("Philo create error", 2, rules);
	return (philo);
}

void	*life(void *gago)
{
	t_philo	*philo;

	philo = (t_philo *)gago;
	if (philo->index % 2 == 0)
		usleep(10);
	while (1)
	{
		if (philo->mode == 1)
		{
			get_philo_forks(philo);
			eat(philo);
			put_philo_forks(philo);
		}
		if (philo->mode == 2)
			sleeping(philo);
		if (philo->mode == 3)
			thinking(philo);
	}
	return 0;
}