#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value:value to put in the new node
 * Return: pointer to the new node, or NULL on failure
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	if (parent == NULL)
	{
		return (NULL);
	}

	binary_tree_t *newNode = binary_tree_node(NULL, value);

	if (newNode == NULL)
	{
		return (NULL);
	}

	if (parent->left != NULL)
	{
		newNode->left = parent->left;
		parent->left->parent = newNode;
	}

	parent->left = newNode;
	newNode->parent = parent;

	return (newNode);
}
