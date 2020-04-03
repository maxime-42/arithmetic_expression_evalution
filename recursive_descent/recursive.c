#include <stdio.h>
#include <stdlib.h>

int	E(char **exp);

int	ft_atoi(char **str)
{
	int	n;
	int	signe;

	n = 0;
	signe = 1;
	while ((**str && **str >= 9 && **str <= 13) || **str == 32)
		(*str)++;
	while ((**str && **str == '-') || **str == '+')
	{
		if (**str == '-')
			signe *= -1;
		else
			signe *= 1;
		(*str)++;
	}
	while (**str >= '0' && **str <= '9')
	{
		n = (n * 10) + **str - 48;
		(*str)++;
	}
	return (n * signe);
}

void	advance(char **exp)
{
	while ((**exp && **exp == ' ') || **exp == '\t')
		(*exp)++;
}

int	F(char **exp)
{
	int	id;

	advance(exp);
	if (**exp == '(')
	{
		(*exp)++;
		advance(exp);
		id = E(exp);
		if (**exp != ')')
		{
			printf("Error:\nmissing right parenthese\n");
			exit(1);
		}
		(*exp)++;
	}
	else if ((**exp > '0' && **exp < '9') || (**exp == '+' || **exp == '-'))
		id = ft_atoi(exp);
	else
		 exit(printf("Error:\nnot is not a arithmetique character"));
	advance(exp);
	return (id);
}

int	T(char **exp)
{
	int	id_1;
	int	id_2;

	id_1 = F(exp);
	while (**exp == '*' || **exp == '/')
	{
		if (**exp == '*')
		{
			(*exp)++;
			advance(exp);
			id_2 = F(exp);
			id_1 = id_1 * id_2;

		}
		else if (**exp == '/')
		{
			(*exp)++;
			advance(exp);
			id_2 = F(exp);
			id_1 = id_1 / id_2;
		}

	}
	return (id_1);
}

int	E(char **exp)
{
	int	id_1;
	int	id_2;

	id_1 = T(exp);
	while (**exp == '+' || **exp == '-')
	{
		if (**exp == '+')
		{
			(*exp)++;
			advance(exp);
			id_2 =  T(exp);
			id_1 = id_1 + id_2;

		}
		else if (**exp == '-')
		{
			(*exp)++;
			advance(exp);
			id_2 = T(exp);
			id_1 = id_1 - id_2;
		}
	}
	return (id_1);
}

int	main(int ac, char **av)
{
	 int	result;
	if (ac != 2)
		return (printf("Error: bad number argument"));
	result = E(&av[1]);
	printf("result = %d\n", result);
	(void)ac;
	(void)av;
	return (0);
}
