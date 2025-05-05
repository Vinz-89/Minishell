/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeessen <vmeessen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 06:41:38 by vmeessen          #+#    #+#             */
/*   Updated: 2025/04/02 06:41:38 by vmeessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h> //	close(), read(), write()
# include <stdlib.h> //	malloc(), free(), exit()
# include <fcntl.h> //open()
# include <sys/wait.h> //	wait(), waitpid()
# include <stdio.h> //	perror()
# include "Lib/Libft/libft.h" //	ft_split(), ft_strjoin(), ft_strdup()..

int		error(void);
void	execute_command(char **cmd, char **envp);
void	free_list(char **list);

#endif
