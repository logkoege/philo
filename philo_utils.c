/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:18:48 by logkoege          #+#    #+#             */
/*   Updated: 2024/10/27 23:19:25 by logkoege         ###   ########.fr       */
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
	philo = malloc(sizeof(t_thread) * config->num_philosophers);
	if (!philo)
	{
		printf("Error -> malloc failed\n");
		return (1);
	}
	forks = malloc(sizeof(pthread_mutex_t) * config->num_philosophers);
	if (!forks)
	{
		printf("Error -> malloc failed\n");
		free(philo);
		return (1);
	}
	return (0);
}
