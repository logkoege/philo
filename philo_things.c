/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:01:07 by logkoege          #+#    #+#             */
/*   Updated: 2024/12/10 18:03:00 by logkoege         ###   ########.fr       */
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
	if (fork_muting(philo) == 1)
		return (1);
	pthread_mutex_lock(&philo->config->status);
	printf("time alive value of philo %i checked == get_time %lli - start time %lli - last meal %lli == %lli\n", philo->id, get_time(), philo->config->start_time , philo->config->last_meal, get_time() - philo->config->start_time - philo->config->last_meal);
	//printf("last meal   -> %lld\n", philo->config->last_meal);
	philo->config->last_meal = (get_time() - philo->config->start_time);
	ft_usleep(philo->config->time_to_eat);
	printf("last meal = %lld\n", philo->config->last_meal);
	//printf("time alive value checked == get_time %lli - start time %lli - last meal %lli == %lli\n", get_time(), philo->config->start_time , philo->config->last_meal, get_time() - philo->config->start_time - philo->config->last_meal);
	//printf("last meal   -> %lld\n", philo->config->last_meal);
	//printf("time to die -> %lld\n", get_time() - philo->config->start_time + philo->config->time_to_die);
	pthread_mutex_unlock(&philo->config->status);
	//if (nb_of_meal(philo) == 1)
	//	return (1);
	
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
	if (printf_lock(philo, "is sleeping\n") == 1)
		return (1);
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
	if (printf_lock(philo, "is thinking\n") == 1)
		return (1);
	return (0);
}

int	philo_is_alive(t_thread *philo)
{
	
	if ((get_time() - philo->config->start_time) - philo->config->last_meal >= (philo)->config->time_to_die)
	{
		printf("DEAD Philo = %d\n", philo->id);
		exit(0);
		return (1);
	}
	return (0);
}

int	printf_lock(t_thread *philo, char *msg)
{
	if (philo->config->dead == 1)
		return (1);
	pthread_mutex_lock(&philo->config->printf);
	if (philo->config->dead == 1)
		return (1);
	printf("%lld %d %s", get_time()
		- philo->config->start_time, philo->id, msg);
	pthread_mutex_unlock(&philo->config->printf);
	return (0);
}
