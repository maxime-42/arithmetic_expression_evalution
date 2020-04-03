# include "ft_btree.h"

int	main(int ac, char **av)
{
	t_btree	*result;
	t_btree	*root;

	if (ac != 2)
		exit(printf("missing argument\n"));
	root = E(&av[1]);
	result = Evaluate_Expression_tree(root);
	printf("result = %d\n", result->value);
	free_btree(root);
	(void) ac;
	(void) av;
	(void) result;
	(void) root;
	return (0);
}
