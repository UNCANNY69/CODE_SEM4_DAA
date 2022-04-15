// Name:
// SRN:
#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

/*
 ** Do not use global variables.
 ** Mark any functions that you declare in this file that are not in the header as static
 ** Do not use static variables
 ** All occurences of count_ptr indicate that the number of comparison
 ** operations need to be stored in the location pointed by it
 ** The implementation can assume it is initialized to 0.
 */

// Initializes the root of the bst
void init_bst(bst_t *bst)
{
    bst->root = NULL;
}

static node_t *insertElement(node_t *root, int key, int *count_ptr)
{
    (*count_ptr)++;
    if (root == NULL)
    {
        root = (node_t *)malloc(sizeof(node_t));
        root->key = key;
        root->right = root->left = NULL;
    }
    else
    {
        (*count_ptr)++;
        if (key > root->key)
        {
            root->right = insertElement(root->right, key, count_ptr);
        }
        else
        {
            root->left = insertElement(root->left, key, count_ptr);
        }
    }
    return root;
}

static int searchElement(node_t *root, int key, int *count_ptr)
{
    (*count_ptr)++;
    if (root == NULL)
    {
        key = -1;
    }
    else
    {
        (*count_ptr) += 2;
        if (root->key == key)
        {
            key = key;
        }
        else if (root->key > key)
        {
            key = searchElement(root->left, key, count_ptr);
        }
        else
        {
            key = searchElement(root->right, key, count_ptr);
        }
    }
    return key;
}

static node_t *deleteElement(node_t *root, int key, int *count_ptr)
{
    (*count_ptr)++;
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        (*count_ptr)++;
        if (root->key == key)
        {
            (*count_ptr) += 3;
            node_t *temp;
            if (root->left == NULL && root->right == NULL)
            {
                free(root);
                return NULL;
            }
            else if (root->left == NULL)
            {
                temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL)
            {
                temp = root->left;
                free(root);
                return temp;
            }
            else
            {
                node_t *temp = root->right;
                while (temp->left != NULL)
                {
                    temp = temp->left; // inorder successor
                }
                root->key = temp->key; // swapping key with inorder successor
                root->right = deleteElement(root->right, temp->key, count_ptr);
                return root;
            }
        }
        else
        {
            *(count_ptr)++;
            if (key > root->key)
            {
                root->right = deleteElement(root->right, key, count_ptr);
            }
            else
            {
                root->left = deleteElement(root->left, key, count_ptr);
            }
        }
        return root;
    }
}

static int find_maxElement(node_t *root, int *count_ptr)
{
    (*count_ptr)++;
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        (*count_ptr)++;
        if (root->right == NULL)
        {
            return root->key;
        }
        else
        {
            return find_maxElement(root->right, count_ptr);
        }
    }
}

// Inserts element key into the Binary search tree
// Stores the number of comparisons at the location
// pointed by count_ptr
void insert(bst_t *tree, int key, int *count_ptr)
{
    tree->root = insertElement(tree->root, key, count_ptr);
}

// Delete key from the BST
// Replaces node with in-order successor
void delete_element(bst_t *tree, int key, int *count_ptr)
{
    tree->root = deleteElement(tree->root, key, count_ptr);
}

// Searches for the element key in the bst
// Returns the element if found, else -1
int search(const bst_t *tree, int key, int *count_ptr)
{
    return searchElement(tree->root, key, count_ptr);
}

// Returns the maximum element in the BST
int find_max(const bst_t *tree, int *count_ptr)
{
    return find_maxElement(tree->root, count_ptr);
}

static node_t *free_node(node_t *root)
{
    if (root != NULL)
    {
        free_node(root->left);
        free_node(root->right);
        free(root);
    }
    return root;
}

// Deletes all the elements of the bst
void free_bst(bst_t *bst)
{
    bst->root = free_node(bst->root);
}

// Deletes all the elements of the bst and ensures it can be used again
void clear_bst(bst_t *bst)
{
    free_bst(bst);
    bst->root = NULL;
}
