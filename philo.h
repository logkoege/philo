/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:10:53 by logkoege          #+#    #+#             */
/*   Updated: 2024/11/19 17:55:03 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

// Structure de configuration de la simulation
typedef struct s_config
{
	int dead;
	int	p;					// = 1 so philo est malloc, 0 si non
	int	f;					// = 1 so forks est malloc, 0 si non
	int	num_philosophers;	// Nombre de philosophes
	int	time_to_die;		// Temps avant de mourir
	int	time_to_eat;		// Temps pour manger
	int	time_to_sleep;		// Temps pour dormir
	long long	last_meal;			// Dernier repas mange (temps)
	pthread_mutex_t status;
	pthread_mutex_t printf;
	int	num_meals;			// Nombre de repas
	long long start_time;
}	t_config;

// Structure représentant un philosophe
typedef struct s_thread
{
	int					id;				// Identifiant du philosophe
	pthread_t			thread;			// Thread du philosophe
	pthread_mutex_t		*left_fork;		// Pointeur vers la fourchette gauche
	pthread_mutex_t		*right_fork;	// Pointeur vers la fourchette droite
	int					meals_eaten;	// Nombre de repas mangés
	t_config			*config;		// Pointeur vers la configuration
}	t_thread;

// philo_utils.c
int			ft_atoi(char *str);
int			alloc(t_thread **philo, pthread_mutex_t **forks, t_config *config);
void		free_fp(t_thread *philo, pthread_mutex_t *forks, t_config *config);
void		init_thread(t_thread **philo, pthread_mutex_t *forks,
				t_config *config);
void		*philo_routine(void *arg);

// philo_parsing.c
int			pars_arg(int argc, char **argv, t_config *config);

// init.c
int			init_philo(t_thread *philo, t_config *config,
				pthread_mutex_t *forks);
int			init_mutex(pthread_mutex_t *forks, int num_philosophers);
void		init_config(t_config *config);
int			init(t_thread *philo, t_config *config, pthread_mutex_t *forks);

//philo_utils2.c
long long	get_time(void);
int			ft_usleep(long int time);

// philo_things.c
int			philo_eating(t_thread *philo);
int			philo_sleeping(t_thread *philo);
int			philo_thinking(t_thread *philo);
int			philo_is_alive(t_thread **philo);
void		printf_lock(t_thread *philo, char *msg);


#endif
