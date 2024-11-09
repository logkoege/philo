/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:18:42 by logkoege          #+#    #+#             */
/*   Updated: 2024/11/09 17:43:11 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_config		config;
	t_thread		*philo;
	pthread_mutex_t	*forks;

	init_config(&config);
	if (pars_arg(argc, argv, &config))
		return (1);
	if (alloc(&philo, &forks, &config))
		return (1);
	if (init(philo, &config, forks))
	{
		free_fp(philo, forks, &config);
		return (1);
	}
	free_fp(philo, forks, &config);
	printf("tout bon\n");
	return (0);
}
