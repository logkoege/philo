/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:42:02 by logkoege          #+#    #+#             */
/*   Updated: 2024/10/28 00:03:05 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_config(t_config *config)
{
	config->num_philosophers = 0;
	config->time_to_die = 0;
	config->time_to_eat = 0;
	config->time_to_sleep = 0;
	config->num_meals = 0;
}

int	init_mutex(pthread_mutex_t *forks, int num_philosophers)
{
	int	i;

	i = 0;
	while (i < num_philosophers)
	{
		printf("%d\n" , num_philosophers);
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			printf("Error -> mutex init failed\n");
			return (1);
		}
		printf("lal\n");
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
		philo[i].right_fork = &forks[(i + 1) % config->num_philosophers];
		philo[i].start_time = 0;
		philo[i].meals_eaten = 0;
		i++;
	}
	return (0);
}

void	*philo_routine(void *arg)
{
	t_thread	*philo;

	philo = (t_thread *)arg;
	while (1)
	{
		printf("philo %d is thinking\n", philo->id);
		usleep(philo->config->time_to_sleep * 1000);
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		printf("philo %d is eating\n", philo->id);
		usleep(philo->config->time_to_eat * 1000);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		printf("philo %d is sleeping\n", philo->id);
		usleep(philo->config->time_to_sleep * 1000);
	}
	return (NULL);
}
