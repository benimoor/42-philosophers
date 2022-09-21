/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cicle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:22:37 by smikayel          #+#    #+#             */
/*   Updated: 2022/09/21 20:58:10 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo	*philo)
{
	pthread_mutex_lock(philo->lfork);
	print_action(" has taken a fork\n", philo);
	pthread_mutex_lock(philo->rfork);
	print_action(" has taken a fork\n", philo);
	philo->eat_count += 1;
	philo->last_eat_time = current_timestamp();
	print_action(" is eating\n", philo);
	my_usleep((int)(philo->rules->eat_time));
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(philo->lfork);
	sleeping(philo);
}

void	sleeping(t_philo	*philo)
{
	print_action(" is sleeping\n", philo);
	my_usleep((int)(philo->rules->sleep_time));
	thinking(philo);
}

void	thinking(t_philo	*philo)
{
	print_action(" is thinking\n", philo);
	eat(philo);
}
