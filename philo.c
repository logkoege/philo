/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:18:42 by logkoege          #+#    #+#             */
/*   Updated: 2024/11/23 17:09:54 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_config		config;
	t_thread		*philo;
	pthread_mutex_t	*forks;

	init_config(&config);
	if (pars_arg(argc, argv, &config) || alloc(&philo, &forks, &config))
		return (1);
	if (init(philo, &config, forks))
	{
		free_fp(philo, forks, &config);
		return (1);
	}
	init_thread(&philo, forks, &config);
	while_dead_0(philo, &config);
	while (++config.i < config.num_philosophers)
		pthread_join(philo[config.i].thread, NULL);
	free_fp(philo, forks, &config);
	return (0);
}
