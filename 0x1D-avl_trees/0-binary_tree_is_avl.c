#include "binary_trees.h"

/**
 * binary_tree_is_avl - check if a binary tree is a valid AVL tree
 * @tree: pointer to root node of tree
 * Return: 1 if AVL tree, else 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int lheight, rheight;

	if (tree == NULL)
		return (0);

	lheight = custom_binary_tree_height(tree->left);
	rheight = custom_binary_tree_height(tree->right);

	if (abs(lheight - rheight) <= 1)
		return (binary_tree_is_bst(tree));
	return (0);
}

/**
 * custom_binary_tree_height - Measure the height
 * of a binary tree from a given node
 * @tree: pointer to node of tree to measure
 * Description: Edited to work with balance factor function
 * Return: height of tree or 0 if NULL
 */
int custom_binary_tree_height(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left = custom_binary_tree_height(tree->left) + 1;
	right = custom_binary_tree_height(tree->right) + 1;

	if (left > right)
		return (left);
	else
		return (right);
}

/**
 * helper - help function
 * @tree: - tree
 * @low: low node
 * @hig: hig node
 *
 * Return: 1 or 0
 */
int helper(const binary_tree_t *tree, int low, int hig)
{
	if (!tree)
		return (0);

	if (low > tree->n || hig < tree->n)
		return (0);

	return (helper(tree->left, low, tree->n - 1) &&
			helper(tree->right, tree->n + 1, hig));

	return (1);
}

/**
 * binary_tree_is_bst - function that checks if a binary tree
 * is a valid Binary Search Tree
 * @tree:  a pointer to the root node of the tree to check
 *
 * Return: value reurned by helper function
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int num = 1;

	if (!tree)
		return (0);

	return (helper(tree, num, num));
}
