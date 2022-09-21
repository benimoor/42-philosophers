/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cicle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:22:37 by smikayel          #+#    #+#             */
/*   Updated: 2022/09/21 18:20:06 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void eat(t_philo	*philo)
{
	pthread_mutex_lock(philo->lfork);
	print_action(" has taken a fork\n", philo);
	pthread_mutex_lock(philo->rfork);
	print_action(" has taken a fork\n", philo);
	philo->eat_count += 1;
	// philo->mode = 2;
	philo->last_eat_time = current_timestamp();
	printf("\n%lld\n", philo->last_eat_time);
	print_action(" is eating\n", philo);
	my_usleep((int)(philo->rules->eat_time));
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(philo->lfork);
	printf("\nUnlock -> %d  %lld\n", philo->index, current_timestamp());
	sleeping(philo);
}

void	sleeping(t_philo	*philo)
{
	print_action(" is sleeping\n", philo);
	// philo->mode = 3;
	my_usleep((int)(philo->rules->sleep_time));
	thinking(philo);
}

void	thinking(t_philo	*philo)
{
	print_action(" is thinking\n", philo);
	// philo->mode = 1;
	eat(philo);
}