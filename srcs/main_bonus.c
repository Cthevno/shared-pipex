/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:59:26 by ctheveno          #+#    #+#             */
/*   Updated: 2025/03/07 16:09:36 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_data(int ac, char **av, char **env, t_data *data)
{
	data->ac = ac;
	data->av = av;
	data->env = env;
	data->nb_cmds = ac - 3;
	data->pids = (int *)malloc(((data->nb_cmds) - 1) * sizeof(int));
	if (!data->pids)
	{
		error("Error: Memory allocation failed", NULL, data, 0);
		return (1);
	}
	data->fd_in = -1;
	data->fd_out = -1;
	data->fd[0] = -1;
	data->fd[1] = -1;
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	if (ac >= 5)
	{
		if (init_data(ac, av, env, &data) == 1)
			return (1);
		if (ft_strncmp(av[1], "here_doc", 9) == 0)
		{
			data.nb_cmds = ac -4;
			ft_here_doc(&data);
		}
		else
			pipex_standard(&data);
	}
	return (0);
}
