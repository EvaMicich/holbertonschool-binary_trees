#include "binary_trees.h"

/**
 * recursion_height - finds height + 1
 * @tree: a pointer to the root node of the tree
 *
 * Return: success returns height of tree + 1, failure 0
 */

size_t recursion_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
	{
		return (0);
	}
	left_height = recursion_height(tree->left);
	right_height = recursion_height(tree->right);

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
 * binary_tree_height - finds height of binary tree
 * @tree: a pointer to the root node of the tree
 *
 * Return: success returns height of tree, failure 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int height = 0;

	if (tree == NULL)
	{
		return (0);
	}
	height = recursion_height(tree);
	return (height);
}
/**
 * binary_tree_balance - gives balance factor for binary tree
 * @tree: tree to find factor
 *
 * Return: on success, balance factor. NULL on failure
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_factor;
	int left_height;
	int right_height;

	if (tree == NULL)
	{
		return (0);
	}
	left_height =  binary_tree_height(tree->left);
	right_height =	binary_tree_height(tree->right);
	balance_factor = left_height - right_height;
	return (balance_factor);
}



/**
 * is_only_child - check if the node only has one child
 * @node: the node that need to be checked
 *
 * Return: 1 for the node only has one child , 0 for
 * the node has two children or has no child
 */

int is_only_child(const binary_tree_t *node)
{
	if (node == NULL)
	{
		return (0);
	}

	if (node->left == NULL && node->right != NULL)
	{
		return (1);
	}
	else if (node->left != NULL && node->right == NULL)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * recursion_full - count if there is any node with only one child
 * @tree: a pointer to the root node of the tree
 *
 * Return: 1 for full tree, failure 0
 */
int recursion_full(const binary_tree_t *tree)
{
	size_t count = 0;
	size_t left_count = 0;
	size_t right_count = 0;

	if (tree == NULL)
	{
		return (0);
	}
	if (is_only_child(tree) == 1)
	{
		return (1);
	}

	left_count = recursion_full(tree->left);
	right_count = recursion_full(tree->right);
	count = left_count + right_count;

	return (count);
}

/**
 * binary_tree_is_full - check if binary tree is full or not
 * @tree: a pointer to the root node of the tree
 *
 * Return: 1 for full tree, failure 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int count = 0;

	if (tree == NULL)
	{
		return (0);
	}

	count = recursion_full(tree);

	if (count > 0)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}






/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree
 *
 * Return: 1 on success, 0 on failure
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	if ((binary_tree_balance(tree) == 0 || binary_tree_balance(tree) == 1 || binary_tree_balance(tree) == -1) && (binary_tree_is_full(tree) == 1))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
