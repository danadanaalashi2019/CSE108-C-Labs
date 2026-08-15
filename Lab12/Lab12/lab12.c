/*
 * Binary Search Tree File Insert/Search Statistics Program
 *
 * Program Description:
 * 1. Reads integers from a file one by one.
 * 2. Inserts each number directly into the binary search tree using recursive insertion.
 * 3. Counts how many numbers exist in the file.
 * 4. Searches each number in the binary search tree recursively.
 * 5. Records recursive call count for each search.
 * 6. Calculates average recursive calls for all searches.
 */


#include <stdio.h>
#include <stdlib.h>


/*
 * =========================
 * Node Definition
 * =========================
 */
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;


/*
 * =========================
 * Function Prototypes
 * =========================
 */
Node *create_node(int value);               /* Creates a new node. */

Node *bst_insert(Node *root, int value);    /* Recursively inserts a value into the binary search tree */

int bst_search(Node *root, int target, int *recursive_call_count);   /* Recursively searches for a target value in the binary search tree */

Node *build_bst_from_file(const char *filename, int *count);         /* Builds the binary search tree with the integer values inside the file */

Node *build_bst_helper(FILE *file, Node *root, int *count);          /* Recursively reads integers from the file, inserts them into the binary search tree */

void analyze_bst_search_performance(Node *root, const char *filename, int count);   /* Analyzes search performance of binary search tree */

void free_tree(Node *root);    /* Frees memory allocated for nodes */

int count_nodes(Node *root);   /* Recursively counts total number of nodes in the binary search tree */


/*
 * Creates a new node.
 */
Node *create_node(int value)
{

    /* Allocate memory for a new node */
    Node *new_node = (Node *)malloc(sizeof(Node));

    /* Stop program if memory allocation fails */
    if (new_node == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    /* Assign value to the new node's data */
    new_node->data = value;

    /* Assign NULL to the new node's left node and right node */
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}


/*
 * Recursively inserts a value into the binary search tree
 */
Node *bst_insert(Node *root, int value)
{
    
    /* ============================= TODO - 1 ============================= */

    /*
     * 1) Check if root is NULL or not.
     *    - If it is NULL, create and return a new node using create_node() function.
     * 
     * 2) Compare value with root->data.
     *    - If value is smaller than root->data, recursively insert value into left subtree. 
     *    - If value is greater than root->data, recursively insert value into right subtree. 
     * 
     * 3) Return root pointer.
     * 
     */

    /* ==================================================================== */
if (root == NULL)
{
return create_node(value);
}
 
if (value < root->data)
{
root->left = bst_insert(root->left, value);
}
 
if (value > root->data)
{
root->right = bst_insert(root->right, value);
}
 
return root;
}


/*
 * Recursively searches for a target value in the binary search tree and counts recursive calls done for a search
 */
int bst_search(Node *root, int target, int *recursive_call_count)
{

    /* ============================= TODO - 2 ============================= */

    /* 
     * 1) Increment recursive_call_count variable by one since we are keeping track of the number of recursive function calls made for bst_search() function.
     *    
     * 2) Check if root is NULL or not.
     *    - If it is NULL, target is not found. Return 0.
     * 
     * 3) If target equals root->data, target has been found. Return 1.
     * 
     * 4) If target is smaller than root->data, recursively search left subtree.
     * 
     * 5) Otherwise, recursively search right subtree.
     * 
     */

    /* ==================================================================== */
(*recursive_call_count)++;
 
if (root == NULL)
{
return 0;
}
 
if (target == root->data)
{
return 1;
}
 
if (target < root->data)
{
return bst_search(root->left, target, recursive_call_count);
}
 
if (target > root->data)
{
return bst_search(root->right, target, recursive_call_count);
}
 
return 0;
}


/*
 * Recursively reads integers from the file, inserts them into the binary search tree
 */
Node *build_bst_helper(FILE *file, Node *root, int *count)
{

    /* ============================= TODO - 3 ============================= */

    /*
     * This function recursively reads all integer numbers in the file. When an integer number is read, it must be inserted into the binary search tree. 
     * Follow the steps below.
     * 
     * 1) Read one integer number from file.
     *    - If reading fails, return root.
     * 
     * 2) Insert the newly read number into binary search tree using bst_insert() function.
     * 
     * 3) Increase count variable by one since count variable keeps the number of nodes inside binary search tree.
     * 
     * 4) Make a recursive function call to read the next number in the file.
     * 
     */

    /* ==================================================================== */
int value;
if (fscanf(file, "%d", &value) != 1)
{
return root;
}
 
root = bst_insert(root, value);
 
(*count)++;
 
return build_bst_helper(file, root, count);

}


/*
 * Builds the binary search tree with the integer values inside the file
 */
Node *build_bst_from_file(const char *filename, int *count)
{

    /* Open file for reading */
    FILE *file = fopen(filename, "r");

    /* Stop if file cannot be opened */
    if (file == NULL)
    {
        printf("File could not be opened: %s\n", filename);
        exit(1);
    }

    /* Initialize count to 0 */
    *count = 0;

    /* Binary search tree starts empty */
    Node *root = NULL;

    /* Build binary search tree recursively */
    root = build_bst_helper(file, root, count);

    /* Close file */
    fclose(file);

    return root;
}


/*
 * Analyzes search performance of binary search tree
 */
void analyze_bst_search_performance(Node *root, const char *filename, int count)
{
    int number;
    int total_recursive_calls = 0;  /* Stores the number of total recursive calls for all searches */

    /* ============================= TODO - 4 ============================= */

    /*
     * 1) Open file with given filename for reading.
     *    - If file cannot be opened, print an error message and stop program with exit(1).
     * 
     * 2) Read all integer numbers from the file using a loop.
     *    - For each number:
     *      - Define an integer variable named recursive_call_count. Set the variable to 0. It will keep the number of recursive calls done for bst_search function.
     *      - Call bst_search() function to search for the newly read number. Make sure you pass recursive_call_count variable as an argument to the function properly.
     *      - Add recursive_call_count variable to the total_recursive_calls variable.
     * 
     * 3) Close the file.
     * 
     */

    /* ==================================================================== */
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    exit(1);
 
    while (fscanf(file, "%d", &number) == 1)
    {
    int recurse_call_count = 0;
 
    bst_search(root, number, &recurse_call_count);
 
    total_recursive_calls += recurse_call_count;
    }
 
    fclose(file);


    /* Calculate average number of recursive calls */
    double average = (double)total_recursive_calls / count;

    /* Final statistical interpretation */
    printf("\n===== BINARY SEARCH TREE SEARCH STATISTICS =====\n\n");
    printf("For %d numbers, each search required an average of %.2f recursive call.\n\n", count, average);
}


/*
 * Frees memory allocated for nodes
 */
void free_tree(Node *root)
{

    /* Base case */
    if (root == NULL)
    {
        return;
    }

    /* Free left subtree */
    free_tree(root->left);

    /* Free right subtree */
    free_tree(root->right);

    /* Free current node */
    free(root);
}

/*
 * Recursively counts total nodes in the binary search tree
 */
int count_nodes(Node *root)
{
    /* Base case: empty subtree */
    if (root == NULL)
    {
        return 0;
    }

    /* Count current node + left subtree + right subtree */
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}


/*
 * Main function
 */
int main()
{

    /* Input file name */
    const char *filename = "numbers.txt";

    /* Root node of binary search tree */
    Node *root;

    /* Total number of integers in file */
    int count;

    /* Build binary search tree from file */
    root = build_bst_from_file(filename, &count);

    /* Print the number of nodes inside binary search tree */
    printf("\nThe number of nodes inside binary search tree: %d\n", count_nodes(root));

    /* Analyze binary search tree search performance */
    analyze_bst_search_performance(root, filename, count);

    /* Free allocated memory of binary search tree */
    free_tree(root);

    return 0;
}

