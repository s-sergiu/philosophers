/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:06:48 by ssergiu           #+#    #+#             */
/*   Updated: 2023/01/04 15:51:30 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 1


typedef struct s_data t_data;
typedef struct s_philosophers t_philosophers;

struct	s_data
{
	int						number_of_philosophers;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						is_dead;
	struct s_philosophers	**philosophers;
};

struct	s_philosophers
{
	int				id;
	int				*time_to_die;
	int				*time_to_eat;
	int				*time_to_sleep;
	int				*dead_flag;
	int				*number;
	pthread_t		*thread;
};

void		initialize_data(struct s_data **data, char **argv);
void		initialize_philosophers(struct s_data **data);
void		*routine(void *);

#endif
