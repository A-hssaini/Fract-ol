/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intial.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamr <mel-hamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:11:39 by mel-hamr          #+#    #+#             */
/*   Updated: 2021/07/09 15:02:49 by mel-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	check_arg(int ac, char **av)
{
	int	i;
	int	j;
	int err;

	j = 0;
	i = 1;
	err = 0;

	if (ac != 6 && ac != 5)
	{
		printf("check argument\n");
		return (1);
	}
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < 48 || av[i][j] > 57)
			{
				printf("check argument\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	if (ft_atoi(av[2, &err) == 1 || ft_atoi(av[3, &err) == 1 || ft_atoi(av[4, &err) == 1)
	return (0);
}

int	check_args(int	ac, char **av)
{
	int i;
	int err;
	int tmp;

	i = 2;
	err = 0;
	while (i < ac)
	{
		tmp = ft_atoi(av[i], &err);
		if (err == 1)
			return (0);
		i++;
	}
	return (1);
}

void	initial_philo(t_vars *vars, int i)
{
	vars->philo[i].vars = vars;
	vars->philo[i].index = i;
	vars->philo[i].right_fork = (i + 1) % vars->nbr_philo;
	vars->philo[i].meal_nbr = 0;
	vars->philo[i].is_full = 0;
}

t_vars	*vars_init(int ac, char **av)
{
	t_vars			*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	if (check_args(ac, av))
	{
		vars->nbr_philo = ft_atoi(av[1], 0);
		vars->time_to_die = ft_atoi(av[2], 0);
		vars->time_to_eat = ft_atoi(av[3], 0);
		vars->time_to_sleep = ft_atoi(av[4], 0);
		if (ac == 6)
			vars->nbr_must_eat = ft_atoi(av[5], 0);
		else
			vars->nbr_must_eat = -1;
		vars->philo_finished_eating = 0;
		vars->fork = (pthread_mutex_t *)malloc( sizeof(pthread_mutex_t) * vars->nbr_philo);
		vars->philo = (t_philo *)malloc(sizeof(t_philo) * vars->nbr_philo);
		pthread_mutex_init(&vars->mutex_print, NULL);
		pthread_mutex_init(&vars->main_mutex, NULL);
		pthread_mutex_lock(&vars->main_mutex);
		vars->start_time = get_time();
		}
		else
		{
			printf("check argument\n");
			return (1);
		}

	return (vars);
}
