/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:04:08 by ergrigor          #+#    #+#             */
/*   Updated: 2022/09/16 22:11:46 by ergrigor         ###   ########.fr       */
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
	pthread_mutex_t	*mutex;
	int				i;

	i = 0;
	mutex = *mutexes;
	// mutex = malloc(sizeof(pthread_mutex_t) * rules->philo);
	if (!mutex)
		put_msg("Malloc Error", 2, rules);
	while (i < rules->philo)
	{
		if (pthread_mutex_init(&mutex[i], NULL) < 0)
		{
			free(mutex);
			put_msg("Mutex Error", 2, rules);
		}
		i++;
	}
	// while(i > 0)
		// printf("%p\n", &mutex[--i]);
	// return (mutex);
}

long long int    current_timestamp(void)
{
    struct timeval    te;

    gettimeofday(&te, 0);
    return (te.tv_sec * 1000LL + te.tv_usec / 1000);
}


void	print_action(char *str, t_philo *philo)
{
	pthread_mutex_lock(philo->rules->print);
	printf("%lld %d %s\n",current_timestamp(), philo->index, str);
	pthread_mutex_unlock(philo->rules->print);
}

void	get_philo_forks(t_philo	*philo)
{
			printf("%d\n", philo->index);
	pthread_mutex_lock(philo->lfork);
	print_action("has taken a fork\n", philo);
	// printf("%d\n", philo->index);
	pthread_mutex_lock(philo->rfork);
	// print_action("has taken a fork\n", philo);
}


void	*life(void *gago)
{
	t_philo	*philo;
	
	philo = (t_philo *)gago;
	if (philo->index % 2 == 0)
		usleep(10);
	printf("asdasdasd\n");
	while (1)
	{
		get_philo_forks(philo);
		// put fork
		//sleep
		//think
	}


	//pthread_mutex_unlock(philo->rules->print);
	return 0;
}

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
		printf("left -> %d\t|\trigth ->%d\n", i, rfork(rules, i));
	i = 0;
	if (pthread_create(&thread[i], NULL, life, (void *)philo) < 0)
		put_msg("Philo create error", 2, rules);
	return (philo);
}

void	destroy_mutexs(pthread_mutex_t **mutex, int i)
{

	int l = 0;
	pthread_mutex_t	*curr;

	curr = *mutex;
	pthread_mutex_destroy(curr);
	// pthread_mutex_destroy(mutex[2]);
	// pthread_mutex_destroy(mutex[3]);
	// pthread_mutex_destroy(mutex[2]);
	while (i >= l)
	{
	// 	printf("Ayo Gago-----%d\n", i);
		pthread_mutex_destroy(&curr[l]);
	// 	l++;
	// 	printf("Ayo Gago---L--%d\n", l);
		l++;
	}
	//free(mutex);
}

// int is_dead
void	start(t_settings	*rules)
{
	t_philo			**philosophers;
	pthread_mutex_t	*mutexes;
	pthread_t		*thread;
	int				i;

	i = 0;
	philosophers = malloc(sizeof(t_philo *) * rules->philo);
	thread = malloc(rules->philo * sizeof(pthread_t));
	mutexes = malloc(rules->philo * sizeof(pthread_mutex_t));
	if (!mutexes)
		put_msg("Malloc Error", 2, rules);
	mutex_maker(rules, &mutexes);
	if (!mutexes)
		return ;
	while (i < rules->philo)
	{
		philosophers[i] = create_philo(rules, &mutexes, i, thread);
		i++;
	}
	destroy_mutexs(&mutexes, i - 1);
	while (1)
	{ 
		// if(is_dead(philosophers) < 0)//|| time is out
		// 	detach_all_threads(thread); // need to write
	}
}
