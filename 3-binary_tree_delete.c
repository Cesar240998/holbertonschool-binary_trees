#include "binary_trees.h"
/**
 * binary_tree_delete - function that deletes an entire binary
 * treefunction that inserts a node as
 * @tree: tree's root
 * Return: nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
