/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:28:13 by ctheveno          #+#    #+#             */
/*   Updated: 2025/03/07 13:56:55 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_here_doc(t_data *d, int fd_temp_file)
{
	int	i;

	d->fd_out = open(d->av[d->nb_cmds +3], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (d->fd_out == -1)
		error("Error fd failed to open", NULL, d, 0);
	i = -1;
	{
		if (i == 0)
		{
			d->pids[i] = first_child_process(d->av[i +3], d);
			close(fd_temp_file);
			if (unlink("./srcs/temp_file") == -1)
				error("Error unlink failed", NULL, d, 0);
		}
		else if (i == (d->nb_cmds -1))
			last_child_process(d->av[i +3], d);
		else
			d->pids[i] = middle_child_process(d->av[i +3], d);
	}
}

void	ft_here_doc_loop(t_data *data, char *line, int fd_temp_file)
{
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			error("Error, get next line failed", NULL, data, 0);
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (ft_strcmp(line, data->av[2]) == 0)
			break ;
		if (write(fd_temp_file, line, ft_strlen(line)) == -1)
			error("Error, write failed", NULL, data, 0);
		if (write(fd_temp_file, "\n", 1) == -1)
			error("Error, write failed", NULL, data, 0);
		ft_free(&line);
	}
	ft_free(&line);
}

void	ft_here_doc(t_data *d)
{
	char	*line;

	line = NULL;
	if (d->ac < 6)
		error("Error invalid number of args", 0, 0, 0);
	d->fd_in = open("./srcs/temp_file", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (d->fd_in == -1)
		error("Error, temp_file failed to open", NULL, d, 0);
	ft_here_doc_loop(d, line, d->fd_in);
	close(d->fd_in);
	d->fd_in = open("./srcs/temp_file", O_CREAT | O_RDWR, 0644);
	pipex_here_doc(d, d->fd_in);
}

void	pipex_standard(t_data *d)
{
	int	i;

	d->fd_in = open(d->av[1], O_RDONLY);
	d->fd_out = open(d->av[d->nb_cmds +2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (d->fd_out == -1)
		error("Error, fd_out failed to open", NULL, d, 0);
	i = -1;
	while (++i < d->nb_cmds)
	{
		if (i == 0)
			d->pids[i] = first_child_process(d->av[i +2], d);
		else if (i == (d->nb_cmds -1))
			last_child_process(d->av[i +2], d);
		else
			d->pids[i] = middle_child_process(d->av[i +2], d);
	}
}
