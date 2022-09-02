#include "binary_trees.h"
/**
 * binary_tree_nodes - function that counts the nodes with at least 1 child.
 * @tree: node to check.
 * Return: number of nodes or 0 if tree is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{

	if (!tree)
		return (0);

	if (tree->left || tree->right)
		return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right) + 1);
	else
		return (0);

}
