// Name: JAYENDRA GANESH DEVISETTI
// SRN: PES2UG20CS511
#include "bst.h"
#include <stdlib.h>

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

// Inserts element key into the Binary search tree
// Stores the number of comparisons at the location
// pointed by count_ptr
node_t *insert_help(node_t *root, int key, int *count_ptr)
{
    // node_t *start = tree->root;
    ;
    if (root == NULL)
    {
        *count_ptr = *count_ptr + 1;
        node_t *temp = malloc(sizeof(node_t));
        temp->key = key;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    else if (root->key > key)
    {
        *count_ptr = *count_ptr + 2;
        root->left = insert_help(root->left, key, count_ptr);
    }
    else
    {
        *count_ptr = *count_ptr + 2;
        root->right = insert_help(root->right, key, count_ptr);
    }
}
void insert(bst_t *tree, int key, int *count_ptr)
{
    node_t *temp = tree->root;
    tree->root = insert_help(temp, key, count_ptr);
}
// Delete key from the BST
// Replaces node with in-order successor
node_t *delete_element_help(node_t *root, int key, int *count_ptr)
{
    if (root)
    {
        if (root->key == key)
        {
            *count_ptr = *count_ptr + 1;
            if (root->left == NULL && root->right == NULL)
            {
                *count_ptr = *count_ptr + 2;
                free(root);
                return NULL;
            }
            else if (root->right == NULL && root->left != NULL)
            {
                *count_ptr = *count_ptr + 4;
                node_t *temp = root->left;
                free(root);
                return temp;
            }
            else if (root->right != NULL && root->left == NULL)
            {
                *count_ptr = *count_ptr + 6;
                node_t *temp = root->right;
                free(root);
                return temp;
            }
            else
            {
                *count_ptr = *count_ptr + 6;
                node_t *temp = root->right;
                // root = root->right;
                while (temp->left != NULL)
                {
                    temp = temp->left;
                }
                root->key = temp->key;
                root->right = delete_element_help(root->right, temp->key, count_ptr);
            }
        }
        else if (key < root->key)
        {
            *count_ptr = *count_ptr + 2;
            root->left = delete_element_help(root->left, key, count_ptr);
        }
        else
        {
            *count_ptr = *count_ptr + 2;
            root->right = delete_element_help(root->right, key, count_ptr);
        }
    }
    else
    {
        return NULL;
    }
}
void delete_element(bst_t *tree, int key, int *count_ptr)
{
    node_t *temp = tree->root;
    tree->root = delete_element_help(temp, key, count_ptr);
}
// Searches for the element key in the bst
// Returns the element if found, else -1
int search_help(node_t *root, int key, int *a, int *count_ptr)
{
    if (root != NULL)
    {
        *count_ptr = *count_ptr + 1;
        if (root->key == key)
        {
            *count_ptr = *count_ptr + 1;
            return key;
        }
        else
        {
            *count_ptr = *count_ptr + 2;
            if (root->key > key)
            {
                search_help(root->left, key, a, count_ptr);
            }
            else
            {
                search_help(root->right, key, a, count_ptr);
            }
        }
    }
    else
    {
        *count_ptr = *count_ptr + 1;
        return -1;
    }
}
int search(const bst_t *tree, int key, int *count_ptr)
{
    node_t *temp = tree->root;
    int a;
    a = search_help(temp, key, &a, count_ptr);
    return a;
}
int find_max_helper(node_t *root, int *max,int *count_ptr)
{
    if (root == NULL)
    {
        *count_ptr = *count_ptr + 1;
        return (*max);
    }
    else if (root->key > *max)
    {
        *count_ptr = *count_ptr + 2;
        *max = root->key;
        find_max_helper(root->right, max,count_ptr);
    }
    else
    {
        *count_ptr = *count_ptr + 2;
        find_max_helper(root->right, max,count_ptr);
    }
}
// Returns the maximum element in the BST
int find_max(const bst_t *tree, int *count_ptr)
{
    if (tree->root != NULL)
    {
        int max = 0;
        node_t *temp = tree->root;
        find_max_helper(temp, &max,count_ptr);
        return max;
    }
    else
    {
        return -1;
    }
}

// Deletes all the elements if the bst and ensures it can be used again
node_t *clear_bst_help(node_t *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        root->left = clear_bst_help(root->left);
        root->right = clear_bst_help(root->right);
        free(root);
        return NULL;
    }
}

void clear_bst(bst_t *bst)
{
    bst->root = clear_bst_help(bst->root);
}

// Deletes all the elements of the bst
void free_bst(bst_t *bst)
{
    clear_bst(bst);
}
