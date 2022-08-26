/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:39:41 by ergrigor          #+#    #+#             */
/*   Updated: 2022/08/26 20:43:41 by ergrigor         ###   ########.fr       */
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
	int	philo;
	int	death_time;
	int	sleep_time;
	int	eat_time;
	int	eat_max_count;
}	t_settings;

size_t	ft_strlen(const char *str);
void	put_msg(char *str, int fd, t_settings *settings);
int		ft_atoi(const char *str, t_settings *settings);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	validation(char *av[], t_settings *settings);

#endif