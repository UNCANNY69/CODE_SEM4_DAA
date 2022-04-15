#include <stdio.h>
int seq(int * a,int k,int n){
    int i = 0;
     while (a[i] != k && i<n){
        i  = i + 1;
    }
    if(i<n)
    return i;
    else
    return -1;   
}
int main()
{
    int a[20],i,k,n;
    //int a[] = {1,2,3,4,5,6,7,8,9,10,11}
     printf("How many elements?");
    scanf("%d",&n);

    printf("Enter array elements(n)");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("nEnter element to search:");
    scanf("%d",&k);
    
    int in = seq(a,k,n);   
    if(in!=-1){
        printf("the value was found at %d",in);  
    }
    else{
        printf("the value was not found ");
    }
      
}
if(root->key == key){
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        else if(root->right == NULL && root->left != NULL){
            node_t*temp = root->left;
            free(root);
            return temp;
        } 
        else if(root->right != NULL && root->left == NULL){
            node_t*temp = root->right;
            free(root);
            return temp;
        }
        else{
            node_t*temp = root;
            root = root->right;
            while(root->left != NULL){
                root = root->left;
            }
            temp->key = root->key;
            delete_element(root->key, count_ptr);
        }
    }
    else if (key < root->key)
    {
        root->left = delete_element(ey,count_ptr);
    }
    else
    {
        root->right = delete_element(ey,count_ptr);
    }