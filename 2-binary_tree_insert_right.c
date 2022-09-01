#include "binary_trees.h"
/**
 * binary_tree_insert_right - function that inserts a node as
 * the right-child of another nodefunction that inserts a node
 * @parent: pointer to created parent node
 * @value: value to put in new node
 * Return: pointer to new node or NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;

	if (!parent)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));

	if (!new)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;

	if (parent->right == NULL)
	{
		new->right = NULL;
		parent->right = new;
	}
	else
	{
		parent->right->parent = new;
		new->right = parent->right;
		parent->right = new;
	}	
	return (new);
}
