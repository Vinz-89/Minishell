/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:17:29 by vwautier          #+#    #+#             */
/*   Updated: 2025/05/16 22:46:08 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <limits.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"


typedef enum e_tokens
{
    t_echo, //Built-in
    t_cd, //----
    t_pwd,//----
    t_export,
    t_env,
    t_exit
}t_tokens;

typedef struct s_shell
{
    char **argv;
    char **env;
    char *line;
    char *pwd;
    //char *cwd[PATH_MAX];
} t_shell;

int str_token(char *token);
void builtin_handler(t_shell *shell, char **argv);
void free_split(char **argv);
void	mgetcwd(char *buffer, size_t size);
void	printshell();

void view_split(char **argv);

#endif