/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:50:14 by averin            #+#    #+#             */
/*   Updated: 2024/02/08 10:46:32 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "colors.h"

static void	handle_sigint(int signal)
{
	(void)signal;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

/**
 * Send a prompt to the user
 * @param data pointer on where the data is stored
 * @return user's input or NULL if EOT
*/
char	*prompt(t_data *data)
{
	struct sigaction	old;
	struct sigaction	saction;
	sigset_t			set;

	sigemptyset(&set);
	saction.sa_handler = handle_sigint;
	saction.sa_mask = set;
	saction.sa_flags = 0;
	if (sigaction(SIGINT, &saction, &old) == -1)
		return (perror("sigaction"), NULL);
	if (data->line)
		free(data->line);
	data->line = readline(PROMPT_HEAD" "WHITE"❯ "DEFAULT);
	if (ft_strncmp(data->line, "", 1) != 0)
		add_history(data->line);
	if (sigaction(SIGINT, &old, NULL) == -1)
		return (perror("sigaction"), free(line), NULL);
	return (data->line);
}
