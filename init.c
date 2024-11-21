/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:42:02 by logkoege          #+#    #+#             */
/*   Updated: 2024/11/21 14:40:14 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_config(t_config *config)
{
	config->check_meals = 0;
	config->i = -1;
	config->j = -1;
	config->p = 0;
	config->f = 0;
	config->num_philosophers = 0;
	config->time_to_die = 0;
	config->time_to_eat = 0;
	config->time_to_sleep = 0;
	config->num_meals = 0;
	config->last_meal = 0;
	pthread_mutex_init(&config->printf, NULL);
	pthread_mutex_init(&config->status, NULL);
	pthread_mutex_init(&config->dead_mutex, NULL);
	pthread_mutex_init(&config->meal, NULL);
	config->dead = 0;
}

int	init_mutex(pthread_mutex_t *forks, int num_philosophers)
{
	int	i;

	i = 0;
	while (i < num_philosophers)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			printf("Error -> mutex init failed\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_philo(t_thread *philo, t_config *config, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < config->num_philosophers)
	{
		philo[i].id = i + 1;
		philo[i].left_fork = &forks[i];
		if (i < config->num_philosophers - 1)
			philo[i].right_fork = &forks[(i + 1)];
		else
			philo[i].right_fork = &forks[0];
		philo[i].config = config;
		philo[i].meals_eaten = 0;
		i++;
	}
	return (0);
}

int	init(t_thread *philo, t_config *config, pthread_mutex_t *forks)
{
	if (init_mutex(forks, config->num_philosophers))
		return (1);
	if (init_philo(philo, config, forks))
		return (1);
	return (0);
}
