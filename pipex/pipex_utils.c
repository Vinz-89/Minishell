/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeessen <vmeessen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 06:35:10 by vmeessen          #+#    #+#             */
/*   Updated: 2025/04/02 06:35:10 by vmeessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error(void)
{
	perror("error");
	exit(EXIT_FAILURE);
}

void	free_list(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

static char	*find_command_path(char *cmd, char **envp)
{
	char	**paths;
	char	*full_path;
	char	*res;
	int		i;

	if (ft_strchr(cmd, '/') || !ft_strncmp(cmd, "./", 2))
		return (ft_strdup(cmd));
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		full_path = ft_strjoin(paths[i++], "/");
		res = ft_strjoin(full_path, cmd);
		free(full_path);
		if (access(res, F_OK) == 0)
			return (free_list(paths), res);
		free(res);
	}
	free_list(paths);
	return (NULL);
}

/*
execve permet de remplacer le processus actuel par un nouveau processus
pour faire la commande. (Le processus est donc stopé et remplacé par le nouveau)
*/
void	execute_command(char **cmd, char **envp)
{
	char	*path;

	if (cmd == NULL || cmd[0] == NULL || cmd[0][0] == '\0')
	{
		perror("Error: Command is empty");
		free_list(cmd);
		exit(127);
	}
	path = find_command_path(cmd[0], envp);
	if (path == NULL)
	{
		perror("Error: finding command path");
		free(path);
		free_list(cmd);
		exit(127);
	}
	if (execve(path, cmd, envp) == -1)
	{
		perror("execve error");
		free(path);
		free_list(cmd);
		exit(EXIT_FAILURE);
	}
	free(path);
}
