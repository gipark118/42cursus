/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 08:26:54 by gipark            #+#    #+#             */
/*   Updated: 2021/04/23 10:15:47 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int				semaphore_init(t_semaphore *semaphore, t_info *info)
{
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("eat");
	if ((semaphore->fork_s =
				sem_open("fork", O_CREAT, 0644, info->number_of_philo / 2)) ==
			SEM_FAILED)
		return (FAILURE);
	if ((semaphore->print_s =
				sem_open("print", O_CREAT, 0644, 1)) == SEM_FAILED)
		return (FAILURE);
	if ((semaphore->eat_s = sem_open("eat", O_CREAT, 0644, 1)) == SEM_FAILED)
		return (FAILURE);
	return (SUCCESS);
}

t_philosopher	*pthread_init(t_info *info, t_semaphore *semaphore)
{
	t_philosopher	*philo;
	int				i;

	i = 0;
	if (!(philo = (t_philosopher *)malloc(sizeof(t_philosopher) *
					info->number_of_philo)))
		return (NULL);
	while (i < info->number_of_philo)
	{
		philo[i].philo_num = i + 1;
		philo[i].info = info;
		philo[i].semaphore = semaphore;
		philo[i].start_time = get_time();
		philo[i].last_philo = get_time();
		i++;
	}
	return (philo);
}

static int		check_args(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int		check_philo(int number_of_philo)
{
	if (number_of_philo == 1 || number_of_philo == 0)
	{
		printf("Test at least two philosophers.\n");
		return (1);
	}
	return (0);
}

int				info_init(t_info *info, const char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (!check_args(argv[i]))
		{
			print_error(NUMERIC_ARG);
			return (FAILURE);
		}
		i++;
	}
	info->num_of_eat = 0;
	info->state = ACTIVITY;
	info->number_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]) * 1000;
	info->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (argv[5])
		info->must_eat = ft_atoi(argv[5]);
	else
		info->must_eat = -1;
	if (check_philo(info->number_of_philo))
		return (FAILURE);
	return (SUCCESS);
}
