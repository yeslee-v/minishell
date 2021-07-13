/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42seoul.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:15:00 by jaekpark          #+#    #+#             */
/*   Updated: 2021/07/13 18:56:17 by parkjaekw        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_conf g_sh;

void	init_parse(t_parse *flag, int pipe)
{
	flag->start = 0;
	flag->pipe = 0;
	flag->cmd = NULL;
	flag->arg = NULL;
	if (flag->syntax == NULL || pipe == 1)
	{
		flag->syntax = malloc(sizeof(t_lst));
		init_lst(flag->syntax);
	}
}

void	init_tool(t_tool *tool)
{
	tool->i = -1;
	tool->is_quote = 0;
	tool->st = -1;
	tool->ed = -1;
	tool->token = malloc(sizeof(t_lst));
	init_lst(tool->token);
}

void	init_lexer(t_lexer *lexer)
{
	lexer->lex = ft_strdup(g_sh.cmd);
	ft_memset(lexer->lex, 0, ft_strlen(lexer->lex));
	lexer->is_quote = 0;
	lexer->s_quote = 0;
	lexer->e_quote = 0;
	lexer->err = 0;
	g_sh.lexer = lexer;
}

void	init_lst(t_lst *lst)
{
	lst->head = NULL;
	lst->tail = NULL;
}
