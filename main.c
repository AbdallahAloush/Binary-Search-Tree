#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef struct Node{
    char* word;
    struct Node* left;
    struct Node* right;
}Node;

int size = 0;

Node* newNode (char* input){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->word = (char*)malloc(strlen(input) + 1);
    strcpy(newNode->word, input);
    newNode->left  = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert (Node* root, char* input) {
    Node *addedNode = newNode(input);
    if (root == NULL)
        root = addedNode;

    else if(strcasecmp(input, root->word) < 0)
        root->left = insert(root->left, input);

    else if(strcasecmp(input, root->word) > 0)
        root->right = insert(root->right, input);

    return root;
}

Node* loadAndCreateTree (Node* root){
    char temp[260];
    FILE* dictionary;
    dictionary = fopen("EN-US-Dictionary.txt", "r");
    if (dictionary == NULL)
        printf("The file is not found!!");
    else {
        while (!feof(dictionary)) {
            fscanf(dictionary, "%[^\n]\n", temp);
            root = insert(root, temp);
            size++;
        }
    }
    fclose(dictionary);
    return root;
}

Node* getMinimum (Node* root) {
    if(root == NULL)
        return NULL;
    while(root->left != NULL)
        root = root->left;
    return root;
}

Node* getMaximum (Node* root){
    if(root == NULL)
        return NULL;
    while(root->right != NULL)
        root = root->right;
    return root;
}

Node* getSuccessor (Node* root, Node* current){
    if (current == NULL) {
        printf("An error occurred!!");
        return NULL;
    }
    else if (current->right != NULL){
        printf("%s  ", getMinimum(current->right)->word);
        return getMinimum(current->right);
    }
    else {
        Node* successor = NULL;
        Node* ancestor = root;
        while (ancestor != current){
            if(strcasecmp(current->word,ancestor->word) < 0) {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        printf("%s  ", successor->word);
        return successor;
    }
}

Node* getPredecessor (Node* root, Node* current){
    if (current == NULL) {
        printf("An error occurred!!");
        return NULL;
    }
    else if (current->left != NULL){
        printf("%s  \n", getMaximum(current->left)->word);
        return getMaximum(current->left);
    }
    else {
        Node* predecessor = NULL;
        Node* ancestor = root;
        while (ancestor != current){
            if(strcasecmp(current->word,ancestor->word) > 0) {
                predecessor = ancestor;
                ancestor = ancestor->right;
            }
            else
                ancestor = ancestor->left;
        }
        printf("%s  \n", predecessor->word);
        return predecessor;
    }
}

Node* search(Node* root, char* input, Node* tempRoot){
    if ( (root->right == NULL && strcasecmp(input, root->word) > 0) || (root->left == NULL && strcasecmp(input, root->word) < 0) ) {
        printf("%s - Incorrect, Suggestions: %s  ", input, root->word);
        getSuccessor(tempRoot,root);
        getPredecessor(tempRoot,root);
        return root;
    }

    else if (strcasecmp(input, root->word) == 0) {
        printf("%s - CORRECT\n", input);
        return root;
    }

    else if (strcasecmp(input, root->word) > 0)
        return search(root->right, input, tempRoot);

    else if (strcasecmp(input, root->word) < 0)
        return search(root->left, input, tempRoot);
}



int max(int x, int y){
    if (x>y)
        return x;
    else
        return y;
}

int findHeight(Node* root){
    if (root == NULL)
        return -1;
    return max(findHeight(root->left), findHeight(root->right)) + 1;
}

void sentenceSearch (Node* root, char* sentence){

    char *input = (char*) malloc(strlen(sentence)+1) ;
    strcpy(input, sentence);

    char* token = strtok(input, " ");

    while( token != NULL ) {
        search(root, token, root);
        token = strtok(NULL, " ");
    }
}

int main() {
    // creating the BST
    Node* root = NULL;
    root = loadAndCreateTree(root);
    printf("..................................\n");
    printf("Dictionary Loaded Successfully...!\n");
    printf("..................................\n");
    printf("Size = %d\n", size);
    printf("..................................\n");
    printf("Height = %d\n", findHeight(root));
    printf("..................................\n");
    printf("Enter a sentence:\n");
    char* input = malloc(sizeof(char) * 100);
    scanf("%[^\n]%*c",input);
    sentenceSearch(root, input);
    return 0;
}
