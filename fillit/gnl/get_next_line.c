/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 16:30:16 by astanciu          #+#    #+#             */
/*   Updated: 2016/12/29 16:40:40 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		read_buffer(int const fd, char **text)
{
	char	*buff;
	int		result;
	char	*new;

	buff = (char*)malloc(sizeof(*buff) * (BUFF_SIZE + 1));
	if (!(buff))
		return (-1);
	result = read(fd, buff, BUFF_SIZE);
	if (result > 0)
	{
		buff[result] = '\0';
		new = ft_strjoin(*text, buff);
		free(*text);
		*text = new;
	}
	free(buff);
	return (result);
}

int				get_next_line(int const fd, char **line)
{
	static char	*text = NULL;
	int			result;
	char		*pozitie;

	if ((!(text) && (text = (char*)malloc(sizeof(*text) + 1)) == NULL)
			|| !(line) || BUFF_SIZE < 0 || fd < 0)
		return (-1);
	pozitie = ft_strchr(text, '\n');
	while (pozitie == NULL)
	{
		result = read_buffer(fd, &text);
		if (result == 0)
		{
			if (ft_strlen(text) == 0)
				return (0);
			text = ft_strjoin(text, "\n");
		}
		if (result < 0)
			return (-1);
		else
			pozitie = ft_strchr(text, '\n');
	}
	*line = ft_strsub(text, 0, ft_strlen(text) - ft_strlen(pozitie));
	text = ft_strdup(pozitie + 1);
	return (1);
}
