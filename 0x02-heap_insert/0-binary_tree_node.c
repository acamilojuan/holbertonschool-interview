#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_node - Fx to create a binary tree node
 * @value: value to put in the new node
 * @parent: pointer to the parent node of the node to create
 * Return: pointer to new node
 **/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newn;

	newn = malloc(sizeof(binary_tree_t));

	if (newn == NULL)
		return (NULL);
	newn->n = value;
	newn->left = NULL;
	newn->right = NULL;
	newn->parent = parent;
	return (newn);
}
