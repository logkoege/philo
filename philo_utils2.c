/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:26:42 by logkoege          #+#    #+#             */
/*   Updated: 2024/11/20 16:51:34 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(long int time)
{
	long int	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < time)
		usleep(150);
	return (1);
}

int	is_alive(t_thread *philo)
{
		if (philo_is_alive(&philo) == 1)
	{
		printf_lock(philo, "is dead\n");
		pthread_mutex_lock(&(philo->config->dead_mutex));
		philo->config->dead = 1;
		pthread_mutex_unlock(&(philo->config->dead_mutex));
		return (1);
	}
	
	return (0);
}

void	while_dead_0(t_thread *philo, t_config *config)
{
	while (config->dead == 0)
	{
		config->j = -1;
		while (++config->j < config->num_philosophers)
		{
			if (is_alive(&philo[config->j]))
				break ;
		}
	}
}