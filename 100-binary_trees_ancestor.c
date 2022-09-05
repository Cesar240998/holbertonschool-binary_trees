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
	size_t i = 0, deph_first = 0, deph_second = 0, max = 0;
	binary_tree_t *temp1, *temp2;

	deph_first = binary_tree_depth(first);
	deph_second = binary_tree_depth(second);

	if (second->n == first->parent->n)
		return ((binary_tree_t *)second);
	if (first->n == second->parent->n)
		return ((binary_tree_t *)first);

	if (deph_first > deph_second)
	{
		max = deph_first;
		temp1 = second->parent;
		temp2 = first->parent;
	}
	else
	{
		max = deph_second;
		temp1 = first->parent;
		temp2 = second->parent;
	}

	for (i = 0; i < max; i++)
	{
		if (temp1->n == temp2->n)
			return (temp1);
		temp2 = temp2->parent;
	}
	return (NULL);
}
/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the root node
 * Return: depth or 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		count = count + 1;
		tree = tree->parent;
	}

	return (count);
}
