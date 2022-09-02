#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 * Return: balance factor or 0
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (0);

	if (!tree->left)
		return (-1 - binary_tree_height(tree->right));

	if (!tree->right)
		return (binary_tree_height(tree->left) - (-1));

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node
 * Return: height or 0
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t count_left = 0, count_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		count_left = 1 + binary_tree_height(tree->left);

	if (tree->right)
		count_right = 1 + binary_tree_height(tree->right);

	return (count_left > count_right ? count_left : count_right);
}

