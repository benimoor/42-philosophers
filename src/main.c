/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:47:27 by ergrigor          #+#    #+#             */
/*   Updated: 2022/09/16 21:37:53 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_settings	*settings;

	settings = malloc(sizeof(t_settings));
	if ((ac == 6 || ac == 5) && validation(av, settings) == 0)
		start(settings);
	else
		put_msg("Enter a valid arguments\n", 2, settings);
	return (0);
}
