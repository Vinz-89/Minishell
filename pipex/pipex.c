/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeessen <vmeessen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 06:38:29 by vmeessen          #+#    #+#             */
/*   Updated: 2025/04/02 06:38:29 by vmeessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	display_error_argument(void)
{
	ft_putstr_fd("Error: Bad arguments\n", 2);
	ft_putstr_fd("Usage: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	return (EXIT_FAILURE);
}

/*
Prend le fichier d'entré et utilise la command1
stdin => f1(fichier d'entré)
stdout => fd[1](pipe)
La sortie(stdout) est envoyé dans le pipe
*/
int	child_process(char *input_file, char *cmd1[], char *envp[], int *fd)
{
	int	f1;

	f1 = open(input_file, O_RDONLY);
	if (f1 < 0)
	{
		free_list(cmd1);
		return (error());
	}
	dup2(f1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(f1);
	close(fd[0]);
	close(fd[1]);
	execute_command(cmd1, envp);
	free_list(cmd1);
	return (1);
}

/*
Prend le fichier de sortie et utilise la command2 ainsi que le pipe
stdin => fd[0](pipe)
stdout => f2(fichier de sortie)
*/
int	parent_process(char *output_file, char *cmd2[], char *envp[], int *fd)
{
	int	f2;

	f2 = open(output_file, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (f2 < 0)
	{
		free_list(cmd2);
		return (error());
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(f2, STDOUT_FILENO);
	close(f2);
	close(fd[1]);
	close(fd[0]);
	execute_command(cmd2, envp);
	free_list(cmd2);
	return (1);
}

/*
Sépration en deux processus enfant et parent
l'enfant vas commencer pour fichier1 + cmd1 => pipe
le parent vas finir pour pipe + cmd2 => fichier2
(Le parent vas devoir attendre la fin de l'enfant)
*/
int	main(int argc, char *argv[], char *envp[])
{
	pid_t	parent;
	int		pipefd[2];

	if (argc != 5)
		return (display_error_argument());
	if (pipe(pipefd) == -1)
	{
		perror("Pipe creation failed");
		exit(EXIT_FAILURE);
	}
	parent = fork();
	if (parent == -1)
	{
		return (error());
	}
	if (parent == 0)
	{
		child_process(argv[1], ft_split(argv[2], ' '), envp, pipefd);
	}
	waitpid(0, NULL, 0);
	parent_process(argv[4], ft_split(argv[3], ' '), envp, pipefd);
	return (0);
}
