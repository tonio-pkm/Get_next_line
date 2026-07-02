/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgarci <antgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:39:12 by antgarci          #+#    #+#             */
/*   Updated: 2026/07/02 19:26:43 by antgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

int    main(void)
{
    char *buffer;
    int fd;
    int bytes;

    /*fd = open ("quijote.txt", O_RDONLY);
    if (fd == -1)
    {
        //error
        return (1);
    }*/
    buffer = malloc(BUFFER_SIZE + 1);
    while ((bytes = read(0, buffer, BUFFER_SIZE)) > 0)
        write(1, buffer, bytes);
    if (bytes == -1)
    {
        free(buffer);
        close(fd);
        return (1);
    }
    //buffer[bytes] = '\0';
    free(buffer);
    close (fd); 
}