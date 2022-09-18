/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:04:08 by ergrigor          #+#    #+#             */
/*   Updated: 2022/09/18 15:46:10 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start(t_settings	*rules)
{
	t_philo			**philosophers;
	pthread_mutex_t	**mutexes;
	pthread_t		*thread;
	int				i;
	int				check;

	i = 0;
	philosophers = malloc(sizeof(t_philo *) * rules->philo);
	thread = malloc(rules->philo * sizeof(pthread_t));
	mutexes = malloc(rules->philo * sizeof(pthread_mutex_t *));
	if (!mutexes)
		put_msg("Malloc Error", 2, rules);
	mutex_maker(rules, mutexes);
	if (!mutexes)
		return -1;
	while (i < rules->philo)
	{
		philosophers[i] = create_philo(rules, mutexes, i, thread);
		i++;
	}
	i = 0;
	while (i < rules->philo)
	{
		pthread_detach(thread[i]);
		i++;
	}
	while (1)
	{ 
		if (check_if_all_eat(philosophers) == 1)
		{	
			pthread_mutex_lock(&rules->print);
			return -1;
		}
		check = check_last_eat_time(philosophers);
		if (check != -1)
		{
			pthread_mutex_lock(&rules->print);
			return check;
		}
	}
	destroy_mutexs(mutexes, i - 1);
}
