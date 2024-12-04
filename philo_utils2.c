/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:26:42 by logkoege          #+#    #+#             */
/*   Updated: 2024/12/04 16:54:32 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("Error -> gettimeofday()\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(long int time)
{
	long int	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < time)
		usleep(150);
	return (150);
}

int	is_alive(t_thread *philo)
{
	if (philo_is_alive(philo) == 1)
	{
		printf_lock(philo, "is dead\n");
		pthread_mutex_lock(&(philo->config->dead_mutex));
		philo->config->dead = 1;
		pthread_mutex_unlock(&(philo->config->dead_mutex));
		return (1);
	}
	return (0);
}

void	while_dead_0(t_thread **philo, t_config *config)
{
	while (config->dead == 0)
	{
		config->j = -1;
		while (++config->j < config->num_philosophers)
		{
			if (is_alive(&(*philo)[config->j]))
				break ;
		}
	}
}

/*int nb_of_meal(t_thread *philo)
{
	pthread_mutex_lock(&philo->config->meal);
	if (philo->config->check_meals / philo->config->num_philosophers
		!= philo->config->num_meals)
	{
		philo->config->check_meals++;
		printf("%d\n", philo->config->check_meals
			/ philo->config->num_philosophers);
		pthread_mutex_unlock(&philo->config->meal);
		return (0);
	}
	printf("fin\n");
	philo->config->check_meals = 1;
	pthread_mutex_unlock(&philo->config->meal);
	return (1);
}
*/