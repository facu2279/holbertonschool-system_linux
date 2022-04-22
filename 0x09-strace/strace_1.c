#include "strace.h"

/**
 * tra_ce - entry to trace
 * Desc: tra_ce function that traces a child process
 * @av: argument
 * @en: environ for execve
 * Return: void function
 */
void tra_ce(char **av, char **en)
{
	ptrace(PTRACE_TRACEME, 0, 0, 0);
	kill(getpid(), SIGSTOP);
	if (execve(av[1], av + 1, en) == -1)
	{
		dprintf(STDERR_FILENO, "Fork failed: %d\n", errno);
		exit(-1);
	}
}

/**
* main - entry to main function
* Desc: main function that executes and traces a given command
* using ptrace to get the syscall and prints name
* @ac: number of arguments
* @av: list of arguments
* @en: list of environ variables
* Return: 0 on success, 1 otherwise
*/
int main(int ac, char **av, char **en)
{
	pid_t child = 0;
	int status = 0, flag = 0;
	struct user_regs_struct regs;

	if (ac < 2)
	{
		printf("Usage: %s command [args...]\n", av[0]);
		return (1);
	}
	setbuf(stdout, NULL);
	child = fork();
	if (child == 0)
	{
		tra_ce(av, en);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			return (0);
		ptrace(PTRACE_SYSCALL, child, NULL, NULL);
		while (wait(&status) && !WIFEXITED(status))
		{
			if (flag)
				(printf("\n"), flag = 0);
			memset(&regs, 0, sizeof(regs));
			ptrace(PTRACE_GETREGS, child, NULL, &regs);
			if (WSTOPSIG(status) == SIGTRAP && (long) regs.rax == -38)
			{
				flag = 1;
				printf("%s", syscalls_64_g[regs.orig_rax].name);
			}
			ptrace(PTRACE_SYSCALL, child, NULL, NULL);
		}
		printf("\n");
	}
	return (0);
}
