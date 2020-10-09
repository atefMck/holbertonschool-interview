#include "binary_trees.h"

/**
 * heap_insert - inserts a value into a Max Binary Heap
 *
 * @root: pointer to the root of the binary tree
 * @value: is a double pointer to the root node of the Heap
 * Return: a pointer to the new node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	binary_tree_t *test;
	test = insert_into_first_place(root, value);
	return test;
}


binary_tree_t *insert_into_first_place(heap_t **root, int value) {
	binary_tree_t *new_node, *tmp;
	tmp = *root;
	if (tmp)
	printf("%d", tmp->n);
	if (tmp == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		*root = new_node;
		return new_node;
	}
	else if (tmp->left == NULL) 
    {
		new_node = binary_tree_insert_left(tmp, value);
		return new_node;
	} 
	else if (tmp->right == NULL) 
	{
		new_node = binary_tree_insert_right(tmp, value);
		return new_node;
	}
    else
    { 
        insert_into_first_place(&tmp->left, value); 
        insert_into_first_place(&tmp->right, value); 
    }
	return NULL;
}


/**
* binary_tree_insert_left - Entry point
* @parent : The parent.
* @value : The value of the node.
* Return: Always 0 (Success)
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
binary_tree_t *new;
if (!parent)
return (NULL);
new = malloc(sizeof(binary_tree_t));
if (!new)
return (NULL);
new->n = value;
new->parent = parent;
new->left = parent->left;
new->right = NULL;
parent->left = new;
if (new->left)
new->left->parent = new;
return (new);
}

/**
* binary_tree_insert_right - Entry point
* @parent : The parent.
* @value : The value of the node.
* Return: Always 0 (Success)
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
binary_tree_t *new;
if (!parent)
return (NULL);
new = malloc(sizeof(binary_tree_t));
if (!new)
return (NULL);
new->n = value;
new->parent = parent;
new->right = parent->right;
new->left = NULL;
parent->right = new;
if (new->right)
new->right->parent = new;
return (new);
}