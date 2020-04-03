# ifndef  FT_BTREE_H
# define FT_BTREE_H

# define INTEGER 1
# define OPERATOR 0

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

# define FLAGS_INTERGER	(1U <<  0U)
# define FLAGS_PLUS	(1U <<  1U)
# define FLAGS_MINUS	(1U <<  2U)
# define FLAGS_MULTI	(1U <<  3U)
# define FLAGS_DIV	(1U <<  4U)
# define FLAGS_MOD	(1U <<  5U)

typedef struct		s_btree
{
	struct		s_btree *left;
	struct		s_btree *right;
	int		type;
	unsigned int	flags : 6;
	int		value;
}			t_btree;

int			ft_atoi(char **str);
t_btree			*create_node(int value, int type);
t_btree			*bin_op(t_btree *op, t_btree *left, t_btree *right);
t_btree			*E(char **exp);
void			advance(char **exp);
t_btree			*Evaluate_Expression_tree(t_btree *root);
unsigned int		put_flags(char c);
void			free_btree(t_btree *root);
#endif
