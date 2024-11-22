/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:47:03 by logkoege          #+#    #+#             */
/*   Updated: 2024/11/22 19:48:45 by logkoege         ###   ########.fr       */
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
	if (if_1_philo(config) == 1)
		return (1);
	return (0);
}

int	if_1_philo(t_config *config)
{
	if (config->num_philosophers == 1)
	{
		printf("0 1 is thinking\n");
		printf("0 1 as taken a fork\n");
		printf("%d 1 is dead\n", config->time_to_die);
		return (1);
	}
	return (0);
}

int	fork_muting(t_thread *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (printf_lock(philo, "has taken a fork\n") == 1)
		return (1);
	pthread_mutex_lock(philo->right_fork);
	if (printf_lock(philo, "has taken a fork\n") == 1)
		return (1);
	if (printf_lock(philo, "is eating\n") == 1)
		return (1);
	return (0);
}
