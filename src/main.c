/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:51:31 by ssergiu           #+#    #+#             */
/*   Updated: 2023/01/02 11:52:34 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	is_invalid_input(struct s_data *data)
{
}

int	input_error(void)
{
	write(1, "Usage:\n", 7);
	return (0);
}

int main(int argc, char **argv)
{
	struct s_data	*data;

	if (argc > 6 || argc < 5)
		return (input_error());
	else
	{
		printf("Argc is %d with argv[1] as %s\n", argc, argv[1]);
		initialize_data(&data, argv);
		initialize_philosophers(&data);
	}
	return (1);
}
