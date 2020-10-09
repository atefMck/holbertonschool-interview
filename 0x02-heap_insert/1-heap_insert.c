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
	binary_tree_t *test, *tmp;
	tmp = *root;
	test = insert_into_first_place(tmp, value);
	return test;
}


binary_tree_t *insert_into_first_place(binary_tree_t *root, int value) {
	binary_tree_t *new_node;
	if (root == NULL)
	{
		printf("yooo");
		new_node = binary_tree_node(NULL, value);
		root = new_node;
		return new_node;
	}
	else if (root->left == NULL || root->right == NULL) 
    {
		printf("yooo");
		new_node = binary_tree_node(root, value);
		return new_node;
	} 
    else
    { 
		printf("yeeee");
        insert_into_first_place(root->left, value); 
        insert_into_first_place(root->right, value); 
    }
	return NULL;
}
