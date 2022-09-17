/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:39:41 by ergrigor          #+#    #+#             */
/*   Updated: 2022/09/17 19:24:48 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>


typedef struct s_settings
{
	int					philo;
	int					death_time;
	int					sleep_time;
	int					eat_time;
	int					eat_max_count;
	pthread_mutex_t		print;
}	t_settings;

typedef struct s_philo
{
	int					index;
	int					mode;
	t_settings			*rules;
	pthread_mutex_t		*lfork;
	pthread_mutex_t		*rfork;
	int					eat_count;
	long long int		last_eat_time;
}	t_philo;

size_t			ft_strlen(const char *str);
void			put_msg(char *str, int fd, t_settings *settings);
int				ft_atoi(const char *str, t_settings *settings);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				validation(char *av[], t_settings *settings);
int				rfork(t_settings *rules, int index);
void			mutex_maker(t_settings *rules, pthread_mutex_t **mutexes);
void			*life(void *gago);
t_philo			*create_philo(t_settings *rules, pthread_mutex_t **mutex, int i, pthread_t *thread);
int				start(t_settings	*rules);
long long int	current_timestamp(void);
int				rfork(t_settings *rules, int index);
void			mutex_maker(t_settings *rules, pthread_mutex_t **mutexes);
long long int	current_timestamp(void);
void			print_action(char *str, t_philo *philo);
void			destroy_mutexs(pthread_mutex_t **mutex, int i);
int				check_if_all_eat(t_philo	**philosophers);
int				check_last_eat_time(t_philo	**philosophers);
void			get_philo_forks(t_philo	*philo);
void			eat(t_philo	*philo);
void			put_philo_forks(t_philo	*philo);
void			sleeping(t_philo	*philo);
void			thinking(t_philo	*philo);

#endif