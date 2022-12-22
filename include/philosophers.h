/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:06:48 by ssergiu           #+#    #+#             */
/*   Updated: 2022/12/20 16:40:58 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

struct s_philo
{
	pthread_mutex_t *fork;
	pthread_t		*thread;
	int				id;
};

struct s_data
{
	struct s_philo	**philos;
	pthread_mutex_t	*mutex;
	pthread_t		*threads;
	int				number;
	int				counter;
	int				philosophers;
	int				ttd;
	int				tte;
	int				tts;
	int				times_eat;
};

void	init_threads(struct s_data **data, char **argv);
int		ft_atoi(const char *str);
void	*routine(void *arg);
void	eating(struct s_data *data);
void	thinking(struct s_data *data);
void	sleeping(struct s_data *data);
void	*philo_routine(void *arg);

#endif
