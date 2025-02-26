/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:47:55 by ctheveno          #+#    #+#             */
/*   Updated: 2025/02/25 14:54:11 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

void	first_child_process(char **av, char **env, int *fd)
{
	int	fd_in;

	fd_in = open(av[1], O_RDONLY);
	if (fd_in == -1)
		error();
	if (dup2(fd_in, STDIN_FILENO) == -1)
	{
		close(fd_in);
		error();
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		close(fd_in);
		close(fd[1]);
		error();
	}
	close(fd[1]);
	close(fd[0]);
	close(fd_in);
	if (ft_exec_cmd(av[2], env) == 1)
	{
		close(fd[1]);
		error();
	}
}

void	last_child_process(char **av, char **env, int *fd)
{
	int		fileout;

	fileout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fileout == -1)
		error();
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		close(fd[0]);
		error();
	}
	if (dup2(fileout, STDOUT_FILENO) == -1)
	{
		close(fd[0]);
		close(fileout);
		error();
	}
	close(fd[1]);
	close(fd[0]);
	close(fileout);
	if (ft_exec_cmd(av[3], env) == 1)
	{
		close(fd[0]);
		error();
	}
}

int	main(int ac, char **av, char **env)
{
	int	pid1;
	int	pid2;
	int	fd[2];

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid1 = fork();
		if (pid1 == -1)
			error();
		if (pid1 == 0)
			first_child_process(av, env, fd);
		pid2 = fork();
		if (pid2 == -1)
			error();
		if (pid2 == 0)
			last_child_process(av, env, fd);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid2, NULL, 0);
	}
	else
		ft_printf("Error with args, ex of args : infile cmd1 cmd2 outfile\n");
	return (0);
}
