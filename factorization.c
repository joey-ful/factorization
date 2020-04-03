/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factorization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehong <jehong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 21:00:20 by jehong            #+#    #+#             */
/*   Updated: 2020/04/03 16:58:00 by jehong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		error(int num)
{
	if (num == 1)
		write(1, "ERROR: please enter one argument.", 33);
	if (num == 2)
		write(1, "ERROR: please enter a number from 2 to 4294967295.", 50);
	if (num == -1)
		write(1, "ERROR: please enter digits only.", 32);
	return (0);
}

void	ft_putnbr(long num)
{
	char	c;
	
	if (num >= 10)
		ft_putnbr(num / 10);
	c = num % 10 + 48;	
	write(1, &c, 1);
}

long	ft_atoi(char *str)
{
	long	num;
	int		i;

	num = 0;
	i = 0;
	if ((str[i] < '0') || ('9' < str[i]))
		return (-1);
	while (('0' <= str[i]) && (str[i] <= '9'))
	{
		num = num * 10 + str[i] - 48;
		i++;
	}
	if (str[i])
		return (-1);
	return (num);
}

int 	is_prime(long num)
{
	long	factor;
	
	factor = 2;
	if (num == 1)
		return (0);
	while ((factor <= (num / 2)) && (factor < 65536))
	{
		if ((num % factor) == 0)
			return (0);
		factor++;
	}
	ft_putnbr(num);
	write(1, " ", 1);
	return (1);
}

void	print_factor(long num, long limit)
{
	long	factor;
	int		flag;

	flag = 0;
	factor = 2;
	while (factor <= limit)
	{
		while ((num % factor) == 0)
		{
			num /= factor;
			flag = 1;
		}
		if (flag == 1)
		{
			ft_putnbr(factor);
			write(1, " ", 1);
			flag = 0;
		}
		if (is_prime(num) == 1)
			break ;
		factor++;
	}
}

int 	main(int argc, char *argv[])
{
	long	num;
	
	if (argc != 2)
		return (error(1));
	num = ft_atoi(argv[1]);
	if (num == -1)
		return (error(-1));
	if ((num < 2) || (num > 4294967295))
		return (error(2));
	if (is_prime(num) == 1)
		return (0);
	print_factor(num, num / 2);
}