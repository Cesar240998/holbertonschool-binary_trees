#include "binary_trees.h"

/**
 * binary_trees_ancestor - function that finds the
 * lowest common ancestor of two nodes
 * @first: is a pointer to the first node.
 * @second:is a pointer to the second node
 * Return: pointer to the lowest common ancestor node.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *temp1, *temp2;

	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	temp1 = first->parent;
	temp2 = second->parent;

	if (temp1 == NULL || first == temp2 || (!temp1->parent && temp2))
	{
		return (binary_trees_ancestor(first, temp2));
	}
	else if (temp2 == NULL || temp1 == second || (!temp2->parent && temp1))
	{
		return (binary_trees_ancestor(temp1, second));
	}

	return (binary_trees_ancestor(temp1, temp2));
}
