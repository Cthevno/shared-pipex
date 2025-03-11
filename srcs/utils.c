/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:03:15 by ctheveno          #+#    #+#             */
/*   Updated: 2025/03/11 13:49:13 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_all_fds(t_data *data)
{
	if (data->fd_in >= 0)
	{
		close(data->fd_in);
		data->fd_in = -1;
	}
	if (data->fd_out >= 0)
	{
		close(data->fd_out);
		data->fd_out = -1;
	}
	if (data->fd[0] >= 0)
	{
		close(data->fd[0]);
		data->fd[0] = -1;
	}
	if (data->fd[1] >= 0)
	{
		close(data->fd[1]);
		data->fd[1] = -1;
	}
}

void	error(const char *msg, const char *cmd, t_data *data, int exit_status)
{
	if (cmd)
		ft_printf_error("\033[31m%s : %s\n\033[0m", msg, cmd);
	else
		ft_printf_error("\033[31m%s\n\033[0m", msg);
	close_all_fds(data);
	free(data->pids);
	if (exit_status != 0)
		exit(exit_status);
	else
		exit(EXIT_FAILURE);
}

void	clean_all(t_data *data)
{
	close_all_fds(data);
	free(data->pids);
}

void	waitpids(t_data *data)
{
	// (void)data;
	int	i;

	i = -1;
	while (++i < ((data->nb_cmds) - 1))
	{
		waitpid(-1, NULL, 0);
		// waitpid(data->pids[i], NULL, 0);
		// ft_printf("pid=%d and i=%d\n", data->pids[i], data->nb_cmds);
	}
	// wait(NULL);
}

// void waitpids(t_data *data)
// {
//     pid_t pid;
//     int status;

//     while ((pid = wait(&status)) > 0)
//     {
//         if (WIFEXITED(status))
//         {
//             if (WEXITSTATUS(status) != 0)
//             {
//                 clean_all(data);
//                 exit(WEXITSTATUS(status));
//             }
//         }
//         else
//         {
//             clean_all(data);
//             exit(EXIT_FAILURE);
//         }
//     }
// }
