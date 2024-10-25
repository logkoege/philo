/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:47:03 by logkoege          #+#    #+#             */
/*   Updated: 2024/10/25 18:05:00 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pars_arg(int argc, char **argv, t_config *config)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error -> invalid number of arguments (must be 4 or 5)\n");
		return (1);
	}
	config->num_philosophers = ft_atoi(argv[1]);
	config->time_to_die = ft_atoi(argv[2]);
	config->time_to_eat = ft_atoi(argv[3]);
	config->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		config->num_meals = ft_atoi(argv[5]);
	if (config->num_philosophers <= 0 || config->time_to_die <= 0
		||config->time_to_eat <= 0 || config->time_to_sleep <= 0
		|| (argc == 6 && config->num_meals <= 0))
	{
		printf("Error -> invalid argument value (must be > 0)\n");
		return (1);
	}
	return (0);
}
