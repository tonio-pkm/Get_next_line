/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgarci <antgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 19:39:49 by antgarci          #+#    #+#             */
/*   Updated: 2026/07/07 21:28:35 by antgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//main lectura desde archivo
/*
int main(void)
{
    int fd;
    char *line;
    
    fd = open("quijote.txt", O_RDONLY);
    if (fd == -1)
    return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
*/


//main lectura desde stdin
/*
int main(void)
{
    char *line;
    
    while ((line = get_next_line(0)) != NULL)
    {
        printf("-->%s", line);
        free(line);
    }
    return (0);
}
*/

//main bonus

int main(void)
{
    int fd;
    int fd2;
    char *line;
    
    fd = open("biblia.txt", O_RDONLY);
    if (fd == -1)
    return (1);
    fd2 = open("quijote.txt", O_RDONLY);
    if (fd == -1)
    return (1);
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd2));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd2));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd2));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd2));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd2));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd2));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd2));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd2));
    
    close(fd);
    close(fd2);
    return (0);
}
