#include<stdio.h>
#include<stdlib.h>

struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
};

struct stack {
    struct tree_node *data;
    struct stack *next;
};

void push(struct stack** top, struct tree_node* n) {
    struct stack* new_n = (struct stack*)malloc(sizeof(struct stack));
    if (new_n == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_n->data = n;
    new_n->next = (*top);
    (*top) = new_n;
}

int isEmpty(struct stack* top) {
    return top == NULL;
}

struct tree_node* pop(struct stack** top_n) {
    struct tree_node* item;
    struct stack* top = *top_n;
    item = top->data;
    *top_n = top->next;
    free(top);
    return item;
}

struct tree_node* create_node(int data) {
    struct tree_node* new_n = (struct tree_node*)malloc(sizeof(struct tree_node));
    if (new_n == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_n->data = data;
    new_n->left = NULL;
    new_n->right = NULL;
    return new_n;
}

void Inorder(struct tree_node* root) {
    if (root == NULL)
        return;
    struct tree_node* temp = root;
    struct stack* s_temp = NULL;
    while (temp || !isEmpty(s_temp)) {
        if (temp) {
            push(&s_temp, temp);
            temp = temp->left;
        }
        else {
            temp = pop(&s_temp);
            printf("%d ", temp->data);
            temp = temp->right;
        }
    }
}

void Preorder(struct tree_node* root) {
    if (root == NULL)
        return;
    struct tree_node* temp = root;
    struct stack* s_temp = NULL;
    if (temp)
        push(&s_temp, temp);
    while (!isEmpty(s_temp)) {
        temp = pop(&s_temp);
        printf("%d ", temp->data);
        if (temp->right)
            push(&s_temp, temp->right);
        if (temp->left)
            push(&s_temp, temp->left);
    }
}

void Postorder(struct tree_node* root) {
    if (root == NULL)
        return;
    struct tree_node* temp = root;
    struct stack* s1 = NULL;
    struct stack* s2 = NULL;
    push(&s1, temp);
    while (!isEmpty(s1)) {
        temp = pop(&s1);
        push(&s2, temp);
        if (temp->left)
            push(&s1, temp->left);
        if (temp->right)
            push(&s1, temp->right);
    }
    while (!isEmpty(s2)) {
        temp = pop(&s2);
        printf("%d ", temp->data);
    }
}

struct tree_node *newNode(int data) {
    struct tree_node *newNode = (struct tree_node *)malloc(sizeof(struct tree_node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printInorder(struct tree_node *node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}



void printPreorder(struct tree_node *node) {
    if (node == NULL)
        return;
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(struct tree_node *node) {
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}




//
struct tree_node *search(struct tree_node *root, int item) {
    if (root == NULL || root->data == item)
        return root;
    if (root->data > item)
        return search(root->left, item);
    return search(root->right, item);
}




struct tree_node *findMin(struct tree_node *root) {
    if (root == NULL)
        return NULL;
    else if (root->left != NULL)
        return findMin(root->left);
    return root;
}

struct tree_node *insert(int item, struct tree_node *root) {
    if (root == NULL)
        return newNode(item);
    if (item < root->data)
        root->left = insert(item, root->left);
    else if (item > root->data)
        root->right = insert(item, root->right);
    return root;
}

struct tree_node *deleteNode(struct tree_node *root, int x) {
    if (root == NULL)
        return NULL;
    if (x > root->data)
        root->right = deleteNode(root->right, x);
    else if (x < root->data)
        root->left = deleteNode(root->left, x);
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if (root->left == NULL || root->right == NULL) {
            struct tree_node *temp;
            if (root->left == NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            return temp;
        }
        else {
            struct tree_node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}



//to calculate total nodes
int totalnodes(struct tree_node *node) {
    if (node == NULL)
        return 0;
        return 1+totalnodes(node->left)+totalnodes(node->right);

}

  int treeHeight(struct tree_node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);

        
        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}


struct tree_node* mirrorImage(struct tree_node* root) {
    if (root == NULL) {
        return NULL;
    } else {
        
        struct tree_node* temp = root->left;
        root->left = mirrorImage(root->right);
        root->right = mirrorImage(temp);
        return root;
    }

}




int main() {
    int choice, item;
    struct tree_node *root = NULL;
    int count;
    int height;
    struct tree_node* mirror=NULL;

    do {
        printf("\n1)Traversal with recursion\n2)Traversal without recursion \n3) Insertion \n4)Delete\n5)count nodes\n6)count height\n7)mirror tree image\n8)mirror image traversal\n9)EXIT");
        printf("Choose one from Above:\n\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nPrinting Inorder.....\n");
            printInorder(root);
            printf("\nPrinting Preorder.....\n");
            printPreorder(root);
            printf("\nPrinting Postorder.....\n");
            printPostorder(root);
            break;

        case 2:
            printf("\nPrinting Inorder.....\n");
            Inorder(root);
            printf("\nPrinting Preorder.....\n");
            Preorder(root);
            printf("\nPrinting Postorder.....\n");
            Postorder(root);
            break;

        case 3:
            printf("Enter data to insert: ");
            scanf("%d", &item);
            root = insert(item, root);
            break;

        case 4:
            printf("Enter data to delete: ");
            scanf("%d", &item);
            root = deleteNode(root, item);
            break;

        case 5:
            count=totalnodes(root);
            printf("total nodes = %d",count);
            break;

            
        case 6:
           height= treeHeight(root);
           printf("%d \n",height);
           break;
        case 7:
           mirror=mirrorImage(root);
           break;

        case 8:
            printf("\nPrinting mirror Inorder.....\n");
            Inorder(mirror);
            printf("\nPrinting mirror Preorder.....\n");
            Preorder(mirror);
            printf("\nPrinting mirror Postorder.....\n");
            Postorder(mirror);
            break;
        case 9:
            exit(EXIT_SUCCESS);
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (1);

    return 0;
}



































































































































































