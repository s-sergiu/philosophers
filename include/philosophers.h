#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_data t_data;

struct s_data
{
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

#endif
