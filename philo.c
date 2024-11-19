/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:18:42 by logkoege          #+#    #+#             */
/*   Updated: 2024/11/19 18:05:37 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_config		config;
	t_thread		*philo;
	pthread_mutex_t	*forks;
	int				i;

	i = -1;
	init_config(&config);
	if (pars_arg(argc, argv, &config) || alloc(&philo, &forks, &config))
		return (1);
	if (init(philo, &config, forks))
	{
		free_fp(philo, forks, &config);
		return (1);
	}
	init_thread(&philo, forks, &config);
	if (philo_is_alive(&philo) == 1)
	{
		printf_lock(philo, "is dead\n");
		config.dead = 1;
		return (1);
	}
	while (i++ < config.num_philosophers)
		pthread_join(philo[i].thread, NULL);
	free_fp(philo, forks, &config);
	return (0);
}
