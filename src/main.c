/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:47:27 by ergrigor          #+#    #+#             */
/*   Updated: 2022/09/20 20:50:21 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_settings	*settings;
	int res;

	settings = malloc(sizeof(t_settings));
	if ((ac == 6 || ac == 5) && validation(av, settings) == 0)
	{
		res = start(settings);
		if (res != -1)
			printf("%lld %d  is dead\n", current_timestamp() - settings->start_time, res + 1);
	}
	else
		put_msg("Enter a valid arguments\n", 2, settings);
	pthread_mutex_destroy(settings->print);
	return (0);
}
