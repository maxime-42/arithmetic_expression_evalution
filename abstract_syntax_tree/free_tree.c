# include "ft_btree.h"

void	free_btree(t_btree *root)
{
	if (root->left || root->right)
	{
		free_btree(root->left);
		free_btree(root->right);
	}
	if (root)
	{
		root->left = 0;
		root->right = 0;
		free(root);
		root = 0;
	}
	return ;
}
