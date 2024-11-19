/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:01:07 by logkoege          #+#    #+#             */
/*   Updated: 2024/11/19 14:35:55 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eating(t_thread *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	printf("%lld %d has taken a fork\n",
		get_time() - philo->config->start_time, philo->id);
	printf("%lld %d has taken a fork\n",
		get_time() - philo->config->start_time, philo->id);
	printf("%lld %d is eating\n", get_time() - philo->config->start_time, philo->id);
	ft_usleep(philo->config->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

int	philo_sleeping(t_thread *philo)
{
	printf("%lld %d is sleeping\n", get_time() - philo->config->start_time, philo->id);
	ft_usleep(philo->config->time_to_sleep);
	return (0);
}

int	philo_thinking(t_thread *philo)
{
	printf("%lld %d is thinking\n", get_time() - philo->config->start_time, philo->id);
	return (0);
}
