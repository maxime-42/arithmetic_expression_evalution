# include "ft_btree.h"

void	advance(char **exp)
{
	if (**exp)
	{
		while (**exp == ' ' || **exp == '\t')
			(*exp)++;
	}
}

t_btree	*create_node(int value, int flags)
{
	t_btree	*node;

	if (!(node = malloc(sizeof(t_btree))))
		return (0);
	node->left = 0;
	node->right = 0;
	node->value = value;
	node->flags = 0;
	node->flags = flags;
	return (node);
}

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

t_btree	*bin_op(t_btree *op, t_btree *left, t_btree *right)
{
	op->left = left;
	op->right = right;
	return (op);
}

unsigned int	put_flags(char c)
{
	if (c == '+')
		return (FLAGS_PLUS);
	else if (c == '-')
		return (FLAGS_MINUS);
	else if (c == '*')
		return (FLAGS_MULTI);
	else if (c == '/')
		return (FLAGS_DIV);
	else if (c == '%')
		return (FLAGS_MOD);
	return (FLAGS_INTERGER);
}
