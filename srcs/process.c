/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:26:55 by ctheveno          #+#    #+#             */
/*   Updated: 2025/03/11 13:57:37 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_multiple_fd(int fd[2], int fd_in, int fd_out)
{
	if (fd[0] >= 0)
	{
		close(fd[0]);
		// fd[0] = -1;
	}
	if (fd[1] >= 0)
	{
		close(fd[1]);
		// fd[1] = -1;
	}
	if (fd_in >= 0)
	{
		close(fd_in);
		// fd_in = -1;
	}
	if (fd_out >= 0)
	{
		close(fd_out);
		// fd_out = -1;
	}
}

pid_t	first_child_process(char *av, t_data *data)
{
	pid_t	pid;

	if (pipe(data->fd) == -1)
		error("Error Pipe failed to open", NULL, data, 0);
	pid = fork();
	if (pid == -1)
		error("Error fork failed", NULL, data, 0);
	if (pid == 0)
	{
		if (dup2(data->fd_in, STDIN_FILENO) == -1)
			error("Error dup2 failed", NULL, data, 0);
		if (dup2(data->fd[1], STDOUT_FILENO) == -1)
			error("Error dup2 failed", NULL, data, 0);
		close_multiple_fd(data->fd, data->fd_in, data->fd_out);
		if (ft_exec_cmd(av, data->env) == 1)
			error("Error command not found", av, data, 127);
	}
	else
	{
		if (dup2(data->fd[0], STDIN_FILENO) == -1)
			error("Error dup2 failed", NULL, data, 0);
		close_multiple_fd(data->fd, data->fd_in, -1);
	}
	return (pid);
}

pid_t	middle_child_process(char *av, t_data *data)
{
	pid_t	pid;

	if (pipe(data->fd) == -1)
		error("Error Pipe failed to open", NULL, data, 0);
	pid = fork();
	if (pid == -1)
		error("Error fork failed", NULL, data, 0);
	if (pid == 0)
	{
		close(data->fd_out);
		close (data->fd[0]);
		if (dup2(data->fd[1], STDOUT_FILENO) == -1)
			error("Error dup2 failed", NULL, data, 0);
		close(data->fd[1]);
		if (ft_exec_cmd(av, data->env) == 1)
			error("Error command not found", av, data, 127);
	}
	else
	{
		close(data->fd[1]);
		if (dup2(data->fd[0], STDIN_FILENO) == -1)
			error("Error dup2 failed", NULL, data, 0);
		close(data->fd[0]);
	}
	return (pid);
}

void	last_child_process(char *av, t_data *data)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		error("Error fork failed", NULL, data, 0);
	if (pid == 0)
	{
		close(data->fd[0]);
		if (dup2(data->fd_out, STDOUT_FILENO) == -1)
			error("Error dup2 failed", NULL, data, 0);
		close(data->fd_out);
		if (ft_exec_cmd(av, data->env) == 1)
			error("Error command not found", av, data, 127);
	}
	else
	{
		close(data->fd[0]);
		close(data->fd_out);
		// close(data->fd[1]);
		waitpids(data);
		clean_all(data);
		waitpid(pid, &status, 0);
		exit (WEXITSTATUS(status));
	}
}
