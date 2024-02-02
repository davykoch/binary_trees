#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height of
 * Return: The height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return 0;
	size_t left_height = tree->left ? binary_tree_height(tree->left) + 1 : 0;
	size_t right_height = tree->right ? binary_tree_height(tree->right) + 1 : 0;
	return (left_height > right_height) ? left_height : right_height;
}

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if full, 0 if not or tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return 0;
	if (!tree->left && !tree->right)
		return 1;
	if (tree->left && tree->right)
		return binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right);
	return 0;
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 if not or tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return 0;

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	if (left_height == right_height && binary_tree_is_full(tree))
		return 1;

	return 0;
}
