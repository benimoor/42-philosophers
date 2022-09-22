/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:04:08 by ergrigor          #+#    #+#             */
/*   Updated: 2022/09/22 23:06:15 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	norm_fix(t_settings *rules, t_philo *philosophers, int check)
{
	while (1)
	{
		if (rules->eat_max_count != -1 && check_if_all_eat(philosophers) != -1)
		{	
			pthread_mutex_lock(rules->print);
			return (-1);
		}
		check = check_last_eat_time(philosophers);
		if (check != -1)
		{
			pthread_mutex_lock(rules->print);
			return (check);
		}
	}
	return (INT_MIN);
}

void	norm_fix2(t_settings *rules, t_philo *philosophers,
	pthread_mutex_t *print)
{
	int	i;

	i = -1;
	while (++i < rules->philo)
	{
		philosophers[i].index = i;
		philosophers[i].rules = rules;
		philosophers[i].rules->print = print;
	}
}

int	start(t_settings	*rules)
{
	t_philo			*philosophers;
	pthread_mutex_t	*mutexes;
	pthread_mutex_t	*print;
	int				check;

	check = 0;
	if (mutex_maker(rules, &mutexes, &philosophers, &print) == -1)
		return (destroy_mutexs(mutexes, rules->philo - 1), -15);
	pthread_mutex_init(print, NULL);
	norm_fix2(rules, philosophers, print);
	if (create_philo(philosophers, mutexes) == -1)
		return (destroy_mutexs(mutexes, rules->philo - 1), -15);
	while (1)
	{
		usleep(100);
		check = norm_fix(rules, philosophers, check);
		if (check != INT_MIN)
			return (check);
	}
	destroy_mutexs(mutexes, rules->philo - 1);
	return (0);
}
