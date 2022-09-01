#include "binary_trees.h"
/**
 * binary_tree_inorder - function that goes through a binary
 * tree using pre-order traversal
 * @tree : root
 * @func : function print_num
 * Return: nothing.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
