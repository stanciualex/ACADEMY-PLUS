#include "get_next_line.h"


int     stock_data(char **str, char *buf, char **line)
{
    char    *aux;

    aux = ft_strchr(str, '\n');
    if (aux)
    {
        ft_memmove(*line, str, ft_strlen((const char)str) - ft_strlen((const char)aux));
        free(*str);
        *str = ft_strdup(aux + 1);
        aux = NULL;
        return (1);
    }
    return (0);
}


int     get_next_line(int const fd, char **line)
{
    static char *str = NULL;
    char    *buf;
    int     a;

    if (fd < 0 || !line)
        return (-1);
    if (str != NULL)
        if (stock_data(&str, buf, line))
            return (1);
    buf = ft_strnew(BUFF_SIZE);
    a = read(fd, buf, BUFF_SIZE);
    if (a < 0)
        return (-1);
    if (stock_data(&str, buf, line))
        return (1);
    /*else
    {
        ft_memmove(*line, buf, ft_strlen(buf));
        return (1);
    }*/
    return (0);
}
