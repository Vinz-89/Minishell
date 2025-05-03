#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>	// close(), read(), write(), access(), fork(), getcwd(), chdir(), dup(), dup2(), pipe(), isatty(), unlink(), execve()
# include <stdio.h>		// printf(), perror(), readline()
# include <stdlib.h>	// malloc(), free(), exit(), getenv()
# include <string.h>	// strerror()
# include <fcntl.h>		// open()
# include <sys/wait.h>	// wait(), waitpid(), wait3(), wait4()
# include <signal.h>	// signal(), sigaction(), sigemptyset(), sigaddset(), kill()
# include <sys/stat.h>	// stat(), lstat(), fstat()
# include <dirent.h>	// Directory : opendir(), readdir(), closedir()
# include <term.h>      // ttyname(), ttyslot()
# include <sys/ioctl.h> // ioctl()
# include <termios.h>	// tcsetattr(), tcgetattr()
# include <curses.h>	// tgetent(), tgetflag(), tgetnum(), tgetstr(), tgoto(), tputs
# include <readline/readline.h> // readline(), rl_clear_history(), rl_on_new_line(), rl_replace_line(), rl_redisplay(), add_history()

// # include <errno.h>	// (used with perror(), strerror())
// # include <term.h>	// (used with curses.h)


# include "../Lib/Libft/libft.h" //	ft_split(), ft_strjoin(), ft_strdup()..

#endif
