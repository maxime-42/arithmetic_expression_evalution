# include "ft_btree.h"

/*
	in this file we creat AST (abstract syntaxtic )
*/

t_btree	*F(char **exp)
{
	t_btree	*node;

	node = 0;
	advance(exp);
	if (**exp == '(')
	{
		(*exp)++;
		advance(exp);
		node = E(exp);
		if (**exp != ')')
			exit(printf("Error:\nmissing right parenthese\n"));
		(*exp)++;
	}
	else if ((**exp > '0' && **exp < '9') || (**exp == '+' || **exp == '-'))
	{
		if (!(node = create_node(ft_atoi(exp), FLAGS_INTERGER)))
			exit(printf("ERROr malloc\n"));
	}
	else
		 exit(printf("Error:\nnot is not a arithmetique character"));
	advance(exp);
	return (node);
}

t_btree	*T(char **exp)
{
	t_btree	*left;
	t_btree	*right;
	t_btree	*op;

	left = F(exp);
	if (**exp != '*' && **exp != '/' && **exp != '%')
		return (left);
	while (**exp == '*' || **exp == '/'  || **exp == '%')
	{
		if (**exp == '*' || **exp == '/' || **exp == '%')
		{
			if (!(op = create_node((int)**exp, put_flags(**exp))))
				exit(printf("ERROr malloc\n"));
			(*exp)++;
			advance(exp);
			right = F(exp);
			op = bin_op(op, left, right);
		}
		left = op;
	}
	return (op);
}

t_btree	*E(char **exp)
{
	t_btree	*left;
	t_btree	*right;
	t_btree	*op;

	left = T(exp);
	if (**exp != '+' && **exp != '-')
		return (left);
	while (**exp == '+' || **exp == '-')
	{
		if (**exp == '+' || **exp == '-')
		{
			if (!(op = create_node((int)**exp, put_flags(**exp))))
				exit(printf("ERROr malloc\n"));
			(*exp)++;
			advance(exp);
			right = T(exp);
			op = bin_op(op, left, right);
		}
		left = op;
	}
	return (op);
}
