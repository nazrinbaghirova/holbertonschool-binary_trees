#include "binary_trees.h"

/**
 * tree_height - measures height of a binary tree
 * @tree: pointer to root node
 *
 * Return: height, or -1 if tree is NULL
 */
int tree_height(const binary_tree_t *tree)
{
	int left_height;
	int right_height;

	if (tree == NULL)
		return (-1);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);

	return (right_height + 1);
}

/**
 * is_perfect - checks if a binary tree is perfect
 * @tree: pointer to root node
 * @height: expected height
 * @level: current level
 *
 * Return: 1 if perfect, 0 otherwise
 */
int is_perfect(const binary_tree_t *tree, int height, int level)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (height == level);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect(tree->left, height, level + 1) &&
		is_perfect(tree->right, height, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to root node
 *
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height;

	if (tree == NULL)
		return (0);

	height = tree_height(tree);

	return (is_perfect(tree, height, 0));
}
