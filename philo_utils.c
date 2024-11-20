/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:18:48 by logkoege          #+#    #+#             */
/*   Updated: 2024/11/20 16:49:02 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	nombre;
	int	signe;

	signe = 1;
	nombre = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	while (str[i] && (str[i] <= '9' && str[i] >= '0'))
	{
		nombre = nombre * 10 + (str[i] - '0');
		i++;
	}
	return (nombre * signe);
}

int	alloc(t_thread **philo, pthread_mutex_t **forks, t_config *config)
{
	(*philo) = malloc(sizeof(t_thread) * config->num_philosophers);
	if (!philo)
	{
		printf("Error -> malloc failed\n");
		return (1);
	}
	config->p = 1;
	(*forks) = malloc(sizeof(pthread_mutex_t) * config->num_philosophers);
	if (!forks)
	{
		printf("Error -> malloc failed\n");
		free_fp(*philo, *forks, config);
		return (1);
	}
	config->f = 1;
	return (0);
}

void	free_fp(t_thread *philo, pthread_mutex_t *forks, t_config *config)
{
	if (config->p)
		free(philo);
	if (config->f)
		free(forks);
}

void	init_thread(t_thread **philo, pthread_mutex_t *forks, t_config *config)
{
	int	i;

	i = 0;
	config->start_time = get_time();
	while (i < config->num_philosophers)
	{
		if (pthread_create(&(*philo)[i].thread, NULL, &philo_routine,
			&(*philo)[i]) != 0)
		{
			printf("Error -> thread creation failed for philosopher %d\n", i);
			free_fp(*philo, forks, config);
		}
		i++;
	}
}

void	*philo_routine(void *arg)
{
	t_thread	*philo;

	philo = (t_thread *) arg;
	if (philo->id % 2 == 0)
		usleep((philo->config->time_to_eat * 1000) / 2);
	while (1)
	{
		if (philo_thinking(philo) == 1)
			return (NULL);
		if (philo_eating(philo) == 1)
			return (NULL);
		if (philo_sleeping(philo) == 1)
			return (NULL);
	}
	return (NULL);
}
