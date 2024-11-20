/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:01:07 by logkoege          #+#    #+#             */
/*   Updated: 2024/11/20 16:52:41 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eating(t_thread *philo)
{
	if (is_alive(philo) == 1)
	{
		philo->config->dead = 1;
		return (1);
	}
	pthread_mutex_lock(philo->left_fork);
	printf_lock(philo, "has taken a fork\n");
	pthread_mutex_lock(philo->right_fork);
	printf_lock(philo, "has taken a fork\n");
	printf_lock(philo, "is eating\n");
	ft_usleep(philo->config->time_to_eat);
	pthread_mutex_lock(&philo->config->status);
	philo->config->last_meal = get_time() - philo->config->start_time;
	pthread_mutex_unlock(&philo->config->status);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

int	philo_sleeping(t_thread *philo)
{
	if (is_alive(philo) == 1)
	{
		philo->config->dead = 1;
		return (1);
	}
	printf_lock(philo, "is sleeping\n");
	ft_usleep(philo->config->time_to_sleep);
	return (0);
}

int	philo_thinking(t_thread *philo)
{
	if (is_alive(philo) == 1)
	{
		philo->config->dead = 1;
		return (1);
	}
	printf_lock(philo, "is thinking\n");
	return (0);
}

int	philo_is_alive(t_thread **philo)
{
	//printf("last meal -> %lld\n", (*philo)->config->last_meal);
	//printf("actual time -> %lld\n", get_time() - (*philo)->config->start_time);
	//printf("time to die -> %d\n", (*philo)->config->time_to_die);
	if (get_time() - (*philo)->config->start_time - (*philo)->config->last_meal >= (*philo)->config->time_to_die)
		return (1);
	return (0);
}

void	printf_lock(t_thread *philo, char *msg)
{
	if (philo->config->dead == 1)
	{
		printf("%lld %d %s", get_time() - philo->config->start_time, philo->id, msg);
		return;
	}
	pthread_mutex_lock(&philo->config->printf);
	printf("%lld %d %s", get_time() - philo->config->start_time, philo->id, msg);
	pthread_mutex_unlock(&philo->config->printf);
}