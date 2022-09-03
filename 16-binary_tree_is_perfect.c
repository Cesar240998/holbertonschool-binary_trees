#include "binary_trees.h"
/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if perfect, otherwise 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left && tree->right)
	{
		if (binary_tree_size(tree->left) == binary_tree_size(tree->right))
			return (1);
	}
	return (0);
}

/**
 * calc_size - measures the size of a binary tree
 * @tree: pointer to the root node
 * Return: size or 0
 */
size_t calc_size(const binary_tree_t *tree)
{
	size_t count_left = 0, count_right = 0;

	if (tree->left)
		count_left = 1 + calc_size(tree->left);

	if (tree->right)
		count_right = 1 + calc_size(tree->right);

	return (count_left + count_right);

}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node
 * Return: size or 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (!tree)
		return (0);

	size = calc_size(tree);
	return (size + 1);
}
