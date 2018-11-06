/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 11:50:46 by agoulas           #+#    #+#             */
/*   Updated: 2018/08/06 14:23:42 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../libft/includes/ft_printf.h"
#include "../includes/ft_filler.h"

int main(void)
{
	/*char *line;
	  int i;

	  i = 1;
	  line = NULL;
	  int fd = open("srcs/test.c",O_RDONLY);
	  while (i == 1)
	  {
	  if (get_next_line(fd , &line) != 1)
	  break ;
	  ft_printf("%s\n",line);
	  }
	  return (0);*/

	char  *line;
	int  out;
	int  p[2];
	int  fd;

		fd = 1;
		out = dup(fd);
		pipe(p);

		dup2(p[1], fd);
		write(fd, "aaa\nbbb\nccc\nddd\n", 16);
		dup2(out, fd);
		close(p[1]);
		get_next_line(p[0], &line);
		if(ft_strcmp(line, "aaa") == 0)
			ft_printf("aaa = ok\n");
		get_next_line(p[0], &line);
		if(ft_strcmp(line, "bbb") == 0)
			ft_printf("bbb = ok\n");
		get_next_line(p[0], &line);
		if(ft_strcmp(line, "ccc") == 0)
			ft_printf("ccc = ok\n");
		get_next_line(p[0], &line);
		if(ft_strcmp(line, "ddd") == 0)
			ft_printf("ddd = ok\n");
return (0);
}
