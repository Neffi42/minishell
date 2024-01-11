/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:06:06 by abasdere          #+#    #+#             */
/*   Updated: 2024/01/11 12:03:15 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

typedef struct s_token
{
	int		val;
	char	*id;
	t_token	*next;
	t_token	*prev;
}	t_token;

void	t_token_clear(t_token **lst);
void	t_token_delone(t_token *lst);
t_token	*t_token_last(t_token *lst);
size_t	t_token_size(t_token *lst);

t_bool	parse_line(t_cmd *cmd, char *line);

#endif
