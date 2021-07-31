#include "../../includes/minishell.h"
#include <sys/wait.h>
#include <unistd.h>

extern t_conf	g_sh;

void			dup_close(int fd, int fd_std)
{
	dup2(fd, fd_std);
	/*
		*close(fd);
		*/
}

void			pipe_intro(int cnt)
{
	int			i;
	int			status;
	int			fd_prev;
	int			fd_backup[2];
	t_process	*proc_lst;
	t_cmd		*proc;

	g_sh.pipe.pid = malloc(sizeof(pid_t) * cnt);
	if (!(g_sh.pipe.pid))
		return ;
	fd_backup[0] = dup(0);
	fd_backup[1] = dup(1);
	i = -1;
	proc_lst = g_sh.process->head;
	while (++i < cnt)
	{
		proc = proc_lst->cmd;
		if (i != (cnt - 1))
			pipe(g_sh.pipe.fd);
		g_sh.pipe.pid[i] = fork();
		if (g_sh.pipe.pid[i] > 0)
		{
			wait(&status);
			g_sh.exit_status = WEXITSTATUS(status);
			if (g_sh.exit_status && (is_blt(proc->cmd) || (g_sh.exit_status == 127)))
				print_status(WEXITSTATUS(status), proc);
			if (!(WIFEXITED(status)))
				return ;
			if (i > 0)
				close(fd_prev);
			fd_prev = g_sh.pipe.fd[0];
			if (i == (cnt - 1))
				close(g_sh.pipe.fd[0]);
			close(g_sh.pipe.fd[1]);
		}
		else if (g_sh.pipe.pid[i] == 0)
		{
			if (i > 0)
			{
				dup_close(fd_prev, STDIN);
				close(g_sh.pipe.fd[0]);
			}
			if (i < (cnt - 1))
				dup_close(g_sh.pipe.fd[1], STDOUT);
			else
				dup_close(fd_backup[1], STDOUT);
			blt_intro(proc_lst);
			exit(0);
		}
		else
			return ;
		proc_lst = proc_lst->next;
	}
	dup2(fd_backup[0], 0);
	ft_free_single((void *)g_sh.pipe.pid);
}
