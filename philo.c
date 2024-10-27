/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:18:42 by logkoege          #+#    #+#             */
/*   Updated: 2024/10/28 00:10:43 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	printf("1\n");

	t_config		config;
	t_thread		*philo;
	pthread_mutex_t	*forks;

	printf("0\n");
	init_config(&config);
	if (pars_arg(argc, argv, &config))
		return (1);
	printf("1\n");
	if (alloc(&philo, &forks, &config) == 1)
		return (1);
	printf("2\n");

	if (init_mutex(forks, config.num_philosophers))
	{
		free(philo);
		free(forks);
		return (1);
	}
	printf("3\n");
	if (init_philo(philo, &config, forks))
	{
		free(philo);
		free(forks);
		return (1);
	}
	free(philo);
	free(forks);
	return (0);
}
