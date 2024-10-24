/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:10:53 by logkoege          #+#    #+#             */
/*   Updated: 2024/10/25 18:04:57 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

// Structure représentant un philosophe
typedef struct s_thread
{
	int					id;				// Identifiant du philosophe
	pthread_t			thread;			// Thread du philosophe
	pthread_mutex_t		*left_fork;		// Pointeur vers la fourchette gauche
	pthread_mutex_t		*right_fork;	// Pointeur vers la fourchette droite
	long long			start_time;		// Temps de début
	int					meals_eaten;	// Nombre de repas mangés
	t_config			*config;		// Pointeur vers la configuration
}	t_thread;

// Structure de configuration de la simulation
typedef struct s_config
{
	int	num_philosophers;	// Nombre de philosophes
	int	time_to_die;		// Temps avant de mourir
	int	time_to_eat;		// Temps pour manger
	int	time_to_sleep;		// Temps pour dormir
	int	num_meals;			// Nombre de repas
}	t_config;

// philo_utils.c
int		ft_atoi(char *str);
void	alloc(t_thread **philo, pthread_mutex_t **forks, t_config *config);

// philo_parsing.c
int		pars_arg(int argc, char **argv, t_config *config);

// init.c
int		init_philo(t_thread *philo, t_config *config, pthread_mutex_t *forks);
int		init_mutex(pthread_mutex_t *forks, int num_philosophers);
int		init_config(t_config *config);
void	*philo_routine(void *arg);

#endif