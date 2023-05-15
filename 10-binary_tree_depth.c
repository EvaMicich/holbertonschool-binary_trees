#include "binary_trees.h"

/**
 * recursion_depth - finds depth + 1
 * @tree: a pointer to the root node of the tree
 *
 * Return: success returns depth of tree + 1, failure 0
 */
size_t recursion_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	if (tree == NULL)
	{
		return (0);
	}
	depth = recursion_depth(tree->parent);
	depth = depth + 1;
	return (depth);
}


/**
 * binary_tree_depth - finds depth of binary tree
 * @tree: a pointer to the root node of the tree
 *
 * Return: success returns depth of tree, failure 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	
	if (tree == NULL)
	{
		return (0);
	}
	depth = recursion_depth(tree) - 1;
	return (depth);
}
