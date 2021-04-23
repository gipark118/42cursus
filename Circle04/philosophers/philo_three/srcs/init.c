/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 09:46:17 by gipark            #+#    #+#             */
/*   Updated: 2021/04/23 10:18:21 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int			semaphore_init(t_semaphore *semaphore, t_info *info)
{
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("eat");
	sem_unlink("main");
	sem_unlink("philo");
	if ((semaphore->fork_s =
				sem_open("fork", O_CREAT, 0644, info->number_of_philo / 2)) ==
			SEM_FAILED)
		return (FAILURE);
	if ((semaphore->print_s =
				sem_open("print", O_CREAT, 0644, 1)) == SEM_FAILED)
		return (FAILURE);
	if ((semaphore->eat_s =
				sem_open("eat", O_CREAT, 0644, 0)) == SEM_FAILED)
		return (FAILURE);
	if ((semaphore->main_s =
				sem_open("main", O_CREAT, 0644, 0)) == SEM_FAILED)
		return (FAILURE);
	if ((semaphore->philo_s =
				sem_open("philo", O_CREAT, 0644, 0)) == SEM_FAILED)
		return (FAILURE);
	return (SUCCESS);
}

void		philosopher_init(t_philosopher *philo, t_info *info,
		t_semaphore *semaphore)
{
	if (!(philo->pid = (pid_t *)malloc(sizeof(pid_t) * info->number_of_philo)))
		return ;
	philo->info = info;
	philo->semaphore = semaphore;
	philo->start_time = get_time();
	philo->last_philo = get_time();
}

static int	check_args(const char *str)
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

static int	check_philo(int number_of_philo)
{
	if (number_of_philo == 1 || number_of_philo == 0)
	{
		printf("Test at least two philosophers.\n");
		return (1);
	}
	return (0);
}

int			info_init(t_info *info, const char **argv)
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
	info->state = ACTIVITY;
	info->num_of_eat = 0;
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
