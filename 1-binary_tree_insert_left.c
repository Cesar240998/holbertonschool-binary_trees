#include "binary_trees.h"
/**
 * binary_tree_insert_left - function that inserts a node
 * as the left-child of another node.
 * @parent: pointer to created parent node
 * @value: value to put in new node
 * Return: pointer to new node or NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;

	new = malloc(sizeof(binary_tree_t));

	if (!new)
		return (NULL);

	if (!parent)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->right = NULL;
	/*parent->left = new;*/

	if (parent->left == NULL)
	{
		new->left = NULL;
		parent->left = new;
	}
	else
	{
		parent->left->parent = new;
		new->left = parent->left;
		parent->left = new;
	}

	return (new);

}
