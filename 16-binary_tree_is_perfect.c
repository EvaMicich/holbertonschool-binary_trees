#include "binary_trees.h"

/**
 * binary_tree_height - finds height of binary tree
 * @tree: a pointer to the root node of the tree
 *
 * Return: success returns height of tree, failure 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
	{
		return (0);
	}
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
	{
		left_height = left_height + 1;
		return (left_height);
	}
	else
	{
		right_height = right_height + 1;
		return (right_height);
	}

}
/**
 * binary_tree_is_leaf - check is the node is a leaf
 * @node: the check
 *
 * Return: 1 for leaf, 0 for not a leaf
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
	{
		return (0);
	}

	if (node->left == NULL && node->right == NULL)
	{
		return (1);
	}

	return (0);
}

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: a pointer to the root node of the tree
 *
 * Return: success returns number of leaves of tree, failure 0
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count = 0;
	size_t left_count = 0;
	size_t right_count = 0;

	if (tree == NULL)
	{
		return (0);
	}
	if (binary_tree_is_leaf(tree) == 1)
	{
		return (1);
	}
	left_count = binary_tree_leaves(tree->left);
	right_count = binary_tree_leaves(tree->right);

	count = left_count + right_count;
	return (count);
}

/**
 * _pow_recursion - calculates x to the power y
 * @x: the base number
 * @y: th epowers number
 * Return: the vulue of the power x to y, -1 is error
 */
size_t _pow_recursion(size_t x, size_t y)
{
	if (y == 0)
		return (1);

	else if (y > 0)
		return (x * _pow_recursion(x, y - 1));

	else
		return (-1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree
 *
 * Return: 1 on success, 0 on failure
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t leaves;
	size_t height;
	size_t two = 2;

	if (tree == NULL)
	{
		return (0);
	}
	leaves = binary_tree_leaves(tree);
	height = binary_tree_height(tree) - 1;
	printf("leaves [%zu], height[%zu]\n", leaves, height);
	if (leaves == _pow_recursion(two, height))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
