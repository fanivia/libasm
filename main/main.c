/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanivia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 14:07:22 by fanivia           #+#    #+#             */
/*   Updated: 2020/11/15 14:07:24 by fanivia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

static void _check_ft_strlen(void)
{
	char	*str;

	printf("=== ft_strlen ===\n");

	str = "Hello World!";
	printf("str = \"%s\"\n", str);
	printf("strlen   : %zu\n", strlen(str));
	printf("ft_strlen: %zu\n", ft_strlen(str));
	printf("\n");

	printf("Empty str\n");
	str = "";
	printf("strlen   : %zu\n", strlen(str));
	printf("ft_strlen: %zu\n", ft_strlen(str));
	printf("\n");

	printf("Big str\n");
	str = "qwertyuiopasdfghjkl\n\tzxcvbnm12\n\n34567890QWERTYUI:::OPpasdfghjkl\n\tzxcvbnm12\n\n34567890QWERTYUI:::OPpasdfghjkl\n\tzxcvbnm12\n\n34567890QWERTYUI:::OPpasdfghjkl\n\tzxcvbnm12\n\n34567890QWERTYUI:::OPpasdfghjkl\n\tzxcvbnm12\n\n34567890QWERTYUI:::OPpasdfghjkl\n\tzxcvbnm12\n\n34567890QWERTYUI:::OPpasdfghjkl\n\tzxcvbnm12\n\n34567890QWERTYUI:::OPpasdfghjkl\n\tzxcvbnm12\n\n34567890QWERTYUI:::OPASD\\FGHJK{}LZXCVBNM0987654321mnbvcxzlkjhgfdsapoiuytrewq";
	printf("strlen   : %zu\n", strlen(str));
	printf("ft_strlen: %zu\n", ft_strlen(str));
	printf("\n");
}

static void	_check_ft_strcpy(void)
{
	char	*str;
	char	*dst;

	printf("=== ft_strcpy ===\n");

	str = "Hello World!";
	dst = calloc(strlen(str) + 1, 1);
	printf("str = \"%s\"\n", str);
	printf("strcpy   : \"%s\"\n", strcpy(dst, str));
	memset(dst, 0, strlen(str) + 1);
	printf("ft_strcpy: \"%s\"\n", ft_strcpy(dst, str));
	free(dst);
	printf("\n");

	printf("Empty str\n");
	str = "";
	dst = calloc(strlen(str) + 1, 1);
	printf("str = \"%s\"\n", str);
	printf("strcpy   : \"%s\"\n", strcpy(dst, str));
	memset(dst, 0, strlen(str) + 1);
	printf("ft_strcpy: \"%s\"\n", ft_strcpy(dst, str));
	free(dst);
	printf("\n");

	printf("Big str\n");
	str = "qwertyuiopasdfghjkl\n\tzxcvbnm12\n\n34567890QWERTYUI:::OPASD\\FGHJK{}LZXCVBNM0987654321mnbvcxzlkjhgfdsapoiuytrewq";
	dst = calloc(strlen(str) + 1, 1);
	printf("str = \"%s\"\n", str);
	printf("strcpy   : \"%s\"\n", strcpy(dst, str));
	memset(dst, 0, strlen(str) + 1);
	printf("ft_strcpy: \"%s\"\n", ft_strcpy(dst, str));
	free(dst);
	printf("\n");
}

static void	_check_ft_strcmp(void)
{
	char	*str;
	char	*dst;

	printf("=== ft_strcmp ===\n");

	str = "Hello World!";
	dst = str;
	printf("Equal str\n");
	printf("str1 = \"%s\"\n", str);
	printf("str2 = \"%s\"\n", dst);
	printf("strcmp   : %d\n", strcmp(str, dst));
	printf("ft_strcmp: %d\n", ft_strcmp(str, dst));
	printf("\n");

	str = "Hello World!";
	dst = "He1Lo";
	printf("Not equal\n");
	printf("str1 = \"%s\"\n", str);
	printf("str2 = \"%s\"\n", dst);
	printf("strcmp   : %d\n", strcmp(str, dst));
	printf("ft_strcmp: %d\n", ft_strcmp(str, dst));
	printf("\n");

	str = "Hello World!";
	dst = "1ello";
	printf("Not equal\n");
	printf("str1 = \"%s\"\n", str);
	printf("str2 = \"%s\"\n", dst);
	printf("strcmp   : %d\n", strcmp(str, dst));
	printf("ft_strcmp: %d\n", ft_strcmp(str, dst));
	printf("\n");

	str = "";
	dst = "";
	printf("Empty\n");
	printf("str1 = \"%s\"\n", str);
	printf("str2 = \"%s\"\n", dst);
	printf("strcmp   : %d\n", strcmp(str, dst));
	printf("ft_strcmp: %d\n", ft_strcmp(str, dst));
	printf("\n");

	str = "a";
	dst = "";
	printf("Empty only one\n");
	printf("str1 = \"%s\"\n", str);
	printf("str2 = \"%s\"\n", dst);
	printf("strcmp   : %d\n", strcmp(str, dst));
	printf("ft_strcmp: %d\n", ft_strcmp(str, dst));
	printf("\n");
}

static void	_check_ft_write(void)
{
	char	*str;
	int		res1;
	int		res2;
	int		fd;
	printf("=== ft_write ===\n");

	str = "Hello World!";
	printf("STDOUT: str = \"%s\"\n", str);
	res1 = write(STDOUT_FILENO, str, strlen(str));
	printf("\n");
	res2 = ft_write(STDOUT_FILENO, str, strlen(str));
	printf("\n");
	printf("write   : %d\n", res1);
	printf("ft_write: %d\n", res2);
	printf("\n");

	str = "Hello World!";
	printf("FILE: str = \"%s\"\n", str);
	fd = open("output_file_std.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	res1 = write(fd, str, strlen(str));
	printf("write   : res = %d\n", res1);
	close(fd);
	printf("write:\n");
	system("cat output_file_std.txt");
	printf("\n");
	fd = open("output_file_ft.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	res2 = ft_write(fd, str, strlen(str));
	printf("ft_write: res = %d\n", res2);
	close(fd);
	printf("ft_write:\n");
	system("cat output_file_ft.txt");
	printf("\n\n");

	printf("BAD FD\n");
	str = "Hello World!";
	errno = 0;
	res1 = write(11111, str, strlen(str));
	printf("write   : %d | errno = %d\n", res1, errno);
	errno = 0;
	res2 = ft_write(11111, str, strlen(str));
	printf("ft_write: %d | errno = %d\n", res2, errno);
	errno = 0;
	res1 = write(-1, str, strlen(str));
	printf("write   : %d | errno = %d\n", res1, errno);
	errno = 0;
	res2 = ft_write(-1, str, strlen(str));
	printf("ft_write: %d | errno = %d\n", res2, errno);
	printf("\n");
}

static void	_check_ft_read(void)
{
	char	buffer[1024];
	int		res1;
	int		res2;
	int		fd;

	printf("=== ft_read ===\n");

	printf("STDIN\n");
	printf("input: \n");
	res1 = read(STDIN_FILENO, buffer, 1024);
	buffer[res1] = '\0';
	printf("\n");
	printf("read   : \n%s\n", buffer);
	printf("read   : res = %d\n", res1);
	printf("\n");
	printf("input: \n");
	res2 = ft_read(STDIN_FILENO, buffer, 1024);
	buffer[res2] = '\0';
	printf("\n");
	printf("ft_read: \n%s\n", buffer);
	printf("ft_read: res = %d\n", res2);
	printf("\n");

	printf("FILE\n");
	fd = open("input_file.txt", O_RDONLY);
	res1 = read(fd, buffer, 1024);
	buffer[res1] = '\0';
	printf("read   : \n%s\n", buffer);
	printf("read   : res = %d\n", res1);
	printf("\n");
	lseek(fd, 0, SEEK_SET);
	res2 = ft_read(fd, buffer, 1024);
	buffer[res2] = '\0';
	printf("ft_read: \n%s\n", buffer);
	printf("ft_read: res = %d\n", res2);
	close(fd);
	printf("\n");

	printf("BAD FD\n");
	errno = 0;
	res1 = read(11111, buffer, 1024);
	printf("read   : %d | errno = %d\n", res1, errno);
	errno = 0;
	res2 = ft_read(11111, buffer, 1024);
	printf("ft_read: %d | errno = %d\n", res2, errno);
	errno = 0;
	res1 = read(-1, buffer, 1024);
	printf("read   : %d | errno = %d\n", res1, errno);
	errno = 0;
	res2 = ft_read(-1, buffer, 1024);
	printf("ft_read: %d | errno = %d\n", res2, errno);
	printf("\n");
}

static void	_check_ft_strdup(void)
{
	char	*str;
	char	*dst;

	printf("=== ft_strdup ===\n");
	str = "Hello World!";
	printf("str = \"%s\"\n", str);
	dst = strdup(str);
	printf("strdup   : \"%s\"\n", dst);
	free(dst);
	dst = ft_strdup(str);
	printf("ft_strdup: \"%s\"\n", dst);
	free(dst);
	printf("\n");

	printf("Empty str\n");
	str = "";
	printf("str = \"%s\"\n", str);
	dst = strdup(str);
	printf("strdup   : \"%s\"\n", dst);
	free(dst);
	dst = ft_strdup(str);
	printf("ft_strdup: \"%s\"\n", dst);
	free(dst);
	printf("\n");

	printf("Big str\n");
	str = "qwertyuiopasdfghjkl\n\tzxcvbnm12\n\n34567890QWERTYUI:::OPASD\\FGHJK{}LZXCVBNM0987654321mnbvcxzlkjhgfdsapoiuytrewq";
	printf("str = \"%s\"\n", str);
	dst = strdup(str);
	printf("strdup   : \"%s\"\n", dst);
	free(dst);
	dst = ft_strdup(str);
	printf("ft_strdup: \"%s\"\n", dst);
	free(dst);
	printf("\n");
}

int			main(void)
{
	_check_ft_strlen();
	_check_ft_strcpy();
	_check_ft_strcmp();
	_check_ft_write();
	_check_ft_read();
	_check_ft_strdup();
	return (0);
}
