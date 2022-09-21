/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:04:08 by ergrigor          #+#    #+#             */
/*   Updated: 2022/09/21 20:27:40 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start(t_settings	*rules)
{
	t_philo			*philosophers;
	pthread_mutex_t	*mutexes;
	pthread_mutex_t	*print;
	int				i;
	int check;
	
	i = 0;
	mutex_maker(rules, &mutexes, &philosophers, &print);
	pthread_mutex_init(print, NULL);
	while (i < rules->philo)
	{
		philosophers[i].index = i;
		philosophers[i].mode = 1;
		philosophers[i].rules = rules;
		philosophers[i].rules->print = print;
		i++;
	}
	create_philo(philosophers, mutexes);
	while (1)
	{ 
		if (rules->eat_max_count != -1 && check_if_all_eat(philosophers) != -1)
		{	
			pthread_mutex_lock(rules->print);
			return -1;
		}
		check = check_last_eat_time(philosophers);
		if (check != -1)
		{
			pthread_mutex_lock(rules->print);
			return check;
		}
	}
	destroy_mutexs(mutexes, i - 1);
}
