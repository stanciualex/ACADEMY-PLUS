#include "get_next_line.h"

int     check_line(char *aux)
{
    char    *tmp = NULL; 
    tmp = ft_strchr(aux, '\n');
    if (tmp)
        return (1);
    return (0);
}

char    *stock_data(char *line, char **aux)
{
    char    *tmp;

    tmp = ft_strchr(*aux, '\n');
    line = ft_strsub(line, 0, ft_strlen(*aux) - ft_strlen(tmp) + 1);
    *aux = ft_strdup(tmp + 1);
    return (line);
}

int     get_next_line(int const fd, char **line)
{
    static char     *aux = NULL;
    char    *buf;
    int     a;

    if (fd < 0 || !line)
        return (-1);
    if (aux == NULL)
    {
        aux = (char*)malloc(sizeof(aux) * (BUFF_SIZE + 1));
        a = read(fd, aux, BUFF_SIZE);
        if (a < 0)
            return (-1);
        //aux = ft_strjoin("", buf);
    }
    if (check_line(aux))
    {
        *line = stock_data(*line, &aux);
        return (1);
    }
    return (0);
}
