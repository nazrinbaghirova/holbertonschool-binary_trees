#include "binary_trees.h"

/**
 * height - measures height of a tree
 * @tree: pointer to node
 *
 * Return: height
 */
int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (-1);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	if (height(tree->left) > height(tree->right))
		return (height(tree->left) + 1);

	return (height(tree->right) + 1);
}

/**
 * binary_tree_balance - measures balance factor
 * @tree: pointer to root
 *
 * Return: balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (height(tree->left) - height(tree->right));
}
