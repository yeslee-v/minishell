#ifndef VARIABLE_H
# define VARIABLE_H

# define TRUE 1
# define FALSE 0
# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define QUOTE 81
# define D_QUOTE 68
# define BUF_SIZE 1

# define PIPE "|"
# define O_REDIR ">"
# define I_REDIR "<"
# define A_REDIR ">>"
# define HEREDOC "<<"

# define S_CMD 0
# define S_ARG 1
# define S_HDOC 2
# define S_AREDIR 3
# define S_IREDIR 4
# define S_OREDIR 5
# define S_FD 6

# define B_ECHO 1
# define B_CD 2
# define B_PWD 3
# define B_EXPORT 4
# define B_UNSET 5
# define B_ENV 6

# define PROMPT "\033[1;32mBraveShell\033[0;31m$\033[0m "
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define RESET "\033[0m"

# define ERR_TOKEN "BraveShell: syntax error near unexpected token"
#endif