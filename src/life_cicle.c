/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cicle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:22:37 by smikayel          #+#    #+#             */
/*   Updated: 2022/09/17 19:32:17 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_philo_forks(t_philo	*philo)
{
	if (philo->index + 1 == philo->rules->philo)
	{
		pthread_mutex_lock(philo->lfork);
		print_action(" has taken a fork\n", philo);
		pthread_mutex_lock(philo->rfork);
		print_action(" has taken a fork\n", philo);
	}
	else
	{
		pthread_mutex_lock(philo->rfork);
		print_action(" has taken a fork\n", philo);
		pthread_mutex_lock(philo->lfork);
		print_action(" has taken a fork\n", philo);
	}
}

void eat(t_philo	*philo)
{
	print_action(" is eating\n", philo);
	philo->eat_count += 1;
	philo->mode = 2;
	philo->last_eat_time = -1;
	usleep(philo->rules->eat_time);
	philo->last_eat_time = current_timestamp();
}

void	put_philo_forks(t_philo	*philo)
{
	if (philo->index + 1 == philo->rules->philo)
	{
		pthread_mutex_unlock(philo->rfork);
		pthread_mutex_unlock(philo->lfork);
	}
	else
	{
		pthread_mutex_unlock(philo->lfork);
		pthread_mutex_unlock(philo->rfork);
	}
}

void	sleeping(t_philo	*philo)
{
	print_action(" is sleeping\n", philo);
	philo->mode = 3;
	usleep(philo->rules->sleep_time);
}

void	thinking(t_philo	*philo)
{
	print_action(" is thinking\n", philo);
	philo->mode = 1;
}