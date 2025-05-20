/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwautier <vwautier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:19:14 by vwautier          #+#    #+#             */
/*   Updated: 2025/05/20 15:25:44 by vwautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell2.h"

/*
static char *read_line_shell(void)
{
	char    *line;
	size_t  linelen;
	char    cwd[1024];

	line = NULL;
	mgetcwd(cwd, sizeof(cwd));
	printf("%s$>",cwd);
	if(isatty(fileno(stdin)))
	//linelen = 0;
	if(getline(&line, &linelen, stdin) == -1)
	{
		free(line);
		line = NULL;
		if(feof(stdin))
			write(1,"[EOF]\n",6);
		else
			perror("Getline failed");
	}
	printf("Linelen : %ld\n",linelen);
	return (line);
}
*/
 char	*readlineprompt(void)
{
	char *line;
	char cwd[256];

	mgetcwd(cwd,sizeof(cwd));
	line = NULL;
	printf("%s",cwd);
	line = readline("$>");
	return(line);
}
/*
int main(int argc, char **argv)
{
	char *line;
	//int	status;
	(void)argc;
	(void)argv;
	printshell();
	
	if(fork() == 0)
		execvp(argv[1], argv + 1);
	wait(&status);
	
	//read_line_shell();
	// REPL READ->EVALUATE->PRINT/EXECUTE->LOOP
	line = readline("Vasy : ");
	
	free(line);
	exit(1);
	line = readlineprompt();
	free(line);
	line = NULL;

	exit(1);
	while(line)
	{
		printf("Line est : %s\n", line);
		//line = read_line_shell();
		free(line);
		line = NULL;
		line = readlineprompt();
	}
	
	return(EXIT_SUCCESS);
}
*/

void clean_readline(void)
{
	 // Nettoyer l'historique juste clear 
	 clear_history();
    
	 // Nettoyer les ressources internes de readline
	 rl_clear_history();
	 rl_free_line_state();
	 
	 // Fonctions supplémentaires pour un nettoyage complet
	 rl_cleanup_after_signal();
	 rl_deprep_terminal();
	 printf("\r");
}


/*
void fill_tokens(int )
{
	char *token;

	if()
	

	
}


void fill_token(t_list **lst, char *tokens)
{
	
}
*/


void exec_token(char **split)
{
	int token;
	char *arg;
	char pwd[PATH_MAX];

	token = str_token(*split);
	arg = split[1];
	if(!token)
		return;
	if(token == t_echo)
	{
		printf("%s\n",arg);
	}
	else if(token == t_cd)
	{
		if (!strncmp("..",arg,2))
		{
			chdir("..");
		}
		else
		{
			if(getcwd(pwd,sizeof(PATH_MAX)))
				ft_strlcpy(pwd,arg,0);
			chdir(pwd);
		}
		
	}

}

static void	handler(int sig)
{
	printf("Dedan");
	if (sig == SIGINT)
	{
		printf("SIGINT\n");
		exit(EXIT_SUCCESS);
	}
}

static void	signalsetup(struct sigaction *sa)
{
	sa->sa_handler = handler;
	/*
	sa->sa_flags = 0;
	sigemptyset(&sa->sa_mask);
	sigaddset(&sa->sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, sa, NULL) == -1)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	*/
}

void add_prompt_pwd(char *pwd, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(pwd[i])
		i++;
	while(str[j])
		pwd[i++] = str[j++];
	pwd[i] = '\0';			
}

int join_prompt_pwd(t_shell *shell, char *str)
{
	char *tmp;

	tmp = NULL;
	if(shell->pwd)
	{
		free(shell->pwd);
		shell->pwd = NULL;
	}
	shell->pwd = getcwd(NULL,0);
	if(!shell->pwd)
	{
		perror("(pwd error)$> ");
		return(0);
	}
	tmp = ft_strjoin(shell->pwd, str);
	free(shell->pwd);
	shell->pwd = tmp;
	return (1);
}

int main(void)
{
	t_shell *shell;
	struct sigaction sa;
	char **argv;
	int	status;
	//t_list **tokens;
	char pwd[PATH_MAX];

	signalsetup(&sa);

	//t_list **tokens = NULL;
	using_history();

	shell = malloc(sizeof(t_shell));
	if(!shell)
		exit(EXIT_SUCCESS);
	memset(shell, 0 , sizeof(t_shell));
	
	//free(shell);
	//return(EXIT_SUCCESS);
	/*

	if(getcwd(shell->pwd,0))
			join_prompt_pwd(pwd, "$> ");
	pwd = getcwd(NULL,0);
	printf("%s",pwd);
	free(pwd);
	pwd = NULL;

	line = readline("$>");

	if (!line)
		write(1,"exit\n",5);
	
		if(line && *line)
		add_history(line);

	//rl_clear_line();
	if(line)
		free(line);
	line = NULL;
	
	*/
	//printf("%d",echo);
	printshell();
	printf("Pid : %d\n",getpid());
	while(1)
	{

		if(!join_prompt_pwd(shell, "$> "))
			break;
		//free(pwd);
		//pwd = NULL;
		//join_prompt_pwd(shell, "$> ");
		shell->line = readline(shell->pwd);
		/*
		if(!ft_strncmp("cd",line,ft_strlen("cd")))
		{
			chdir("/home/vwautier/minishell/libft");
			//printf("%d\n",str_token(line));
		}
		*/
		if(!shell->line)
		{
			write(1,"exit\n",5);
			if(shell->pwd)
			{
				free(shell->pwd);
				shell->pwd = NULL;
			}
			if(shell->env)
			{
				free(shell->line);
				shell->line = NULL;
			}
			if(shell->env)
			{
				free_split(shell->env);
				shell->env = NULL;
			}
			if(shell->argv)
			{
				free_split(shell->argv);
				shell->argv = NULL;
			}
			if(shell)
				free(shell);
			shell = NULL;
			break;
		}

		if(shell->line && *shell->line)
			add_history(shell->line);
		shell->argv = ft_split(shell->line,' ');
		//view_split(argv);
		builtin_handler(shell,shell->argv);		
		free_split(shell->argv);
		shell->argv = NULL;
		free(shell->line);
		shell->line = NULL;
	}
	clean_readline();
	return(EXIT_SUCCESS);
}