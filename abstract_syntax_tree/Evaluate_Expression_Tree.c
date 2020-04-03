# include "ft_btree.h"

t_btree	*calculation(t_btree *operant1, t_btree *operant2, t_btree *operator)
{
	if (operator->flags & FLAGS_PLUS)
		operant1->value += operant2->value;
	else if (operator->flags & FLAGS_MINUS)
		operant1->value -= operant2->value;
	else if (operator->flags & FLAGS_MULTI)
		operant1->value *= operant2->value;
	else if (operator->flags & FLAGS_DIV)
		operant1->value /= operant2->value;
	else if (operator->flags & FLAGS_MOD)
		operant1->value %= operant2->value;
	return (operant1);
}

t_btree	*Evaluate_Expression_tree(t_btree *root)
{
	t_btree *operant1;
	t_btree *operant2;
	t_btree *operator;

	if (root->left || root->right)
	{
		operant1 = Evaluate_Expression_tree(root->left);
		operant2 = Evaluate_Expression_tree(root->right);
		operator = root;
		return (calculation(operant1, operant2, operator));
	}
	(void) operator;
	return (root);
}
