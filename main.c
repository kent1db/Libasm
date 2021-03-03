/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:56:16 by qurobert          #+#    #+#             */
/*   Updated: 2021/03/02 16:11:57 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libasm.h"

void	ft_test_strdup(void)
{
	char *str;
	
	str = "Test de strdup";
	dprintf(1, "\n---------ft_strdup---------\n\n");
	dprintf(1, "1_\n%s\n", strdup(str));
	dprintf(1, "2_\n%s\n", ft_strdup(str));
}

void	ft_test_strcmp(void)
{
	char *s1;
	char *s2;

	s1 = "\xff\xff";
	s2 = "\xff";
	dprintf(1, "\n---------ft_strcmp---------\n\n");
	dprintf(1, "1_\n\t%d\n", strcmp(s1, s2));
	dprintf(1, "2_\n\t%d\n", ft_strcmp(s1, s2));
}

void	ft_test_strcpy(void)
{
	char *src;
	char dst[11];
	char dst2[11];

	src = "abcdefghij";
	dprintf(1, "\n---------ft_strcpy---------\n\n");
	dprintf(1, "1_\n%s\n\n", strcpy(dst, src));
	dprintf(1, "2_\n%s\n\n", ft_strcpy(dst2, src));
}

void	ft_test_strlen(void)
{
	char 	*str;
	int 	len;
	int		len2;

	str = "Hello World\n";
	len = strlen(str);
	len2 = ft_strlen(str);

	dprintf(1, "\n---------ft_strlen---------\n\n");
	dprintf(1, "1_\nlen = %d\n\n", len);
	dprintf(1, "2_\nlen = %d\n\n", len2);
}

void	ft_test_read(void)
{
	int 	fd;
	int 	ret;
	int		ret2;
	int		x = 20;
	char 	buf[x];
	char 	buf2[x];

	dprintf(1, "\n----------ft_read----------\n\n");
	dprintf(1, "errno_init_value = %d\n\n", errno);
	
	/* read */
	fd = open("./test", O_RDONLY);
	ret = read(fd, buf, x);
	buf[ret] = 0;
	dprintf(1, "1_\nret = %d\nbuf = %s\n\n", ret, buf);
	close(fd);
	
	/* ft_read */
	fd = open("./test", O_RDONLY);
	ret2 = ft_read(fd, buf2, x);
	buf2[ret2] = 0;
	dprintf(1, "2_\nret = %d\nbuf = %s\n\n", ret2, buf2);
	fd = open("./test", O_RDONLY);
}

void	ft_test_write(void)
{
	char 	*str = NULL;
	char	*str2 = NULL;
	int 	ret;
	int 	ret2;
	int		tmp[2];
	size_t 	len;

	str = "1_\nBonjour, ceci est un test 1\n";
	str2 = "2_\nBonjour, ceci est un test 2\n";
	len = strlen(str);
	pipe(tmp);
	dprintf(1, "----------ft_write----------\n\n");
	dprintf(1, "errno_init_value = %d\n\n", errno);
	/* write */
	ret = write(tmp[1], NULL, 2);
	dprintf(1, "ret = %d\nerrno_value = %d %s\n\n", ret, errno, strerror(errno));
	/* ft_write */
	ret2 = ft_write(tmp[1], NULL, 2);
	dprintf(1, "ret = %d\nerrno_value = %d %s\n\n", ret2, errno, strerror(errno));
	close(tmp[0]);
	close(tmp[1]);
}

int		main(void)
{
	int rep;
	dprintf(1, "What do you want to test ?\n\n1 - ft_write\n2 - ft_read\n3 - ft_strlen\n4 - ft_strcpy\n5 - ft_strcmp\n6 - ft_strdup\n\n");
	scanf("%d", &rep);
	system("clear");
	if (rep == 1)
	{
		dprintf(1, "\n");
		ft_test_write();
	}
	else if (rep == 2)
	{
		dprintf(1, "\n");
		ft_test_read();
	}
	else if (rep == 3)
	{
		dprintf(1, "\n");
		ft_test_strlen();
	}
	else if (rep == 4)
	{
		dprintf(1, "\n");
		ft_test_strcpy();
	}
	else if (rep == 5)
	{
		dprintf(1, "\n");
		ft_test_strcmp();
	}
	else if (rep == 6)
	{
		dprintf(1, "\n");
		ft_test_strdup();
	}	
	return (0);
}
