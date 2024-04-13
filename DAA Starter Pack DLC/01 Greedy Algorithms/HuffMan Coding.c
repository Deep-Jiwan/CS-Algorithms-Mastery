#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    int frequency;
    struct Node* left;
    struct Node* right;
    struct Node* next; // For linked list
};

// Priority Queue functions
struct Node* createNode(char data, int frequency);
struct Node* createQueue();
void enqueue(struct Node** head_ref, struct Node* new_node);
struct Node* dequeue(struct Node** head_ref);
int isQueueEmpty(struct Node* head);

// Huffman Coding functions
struct Node* buildHuffmanTree(struct Node* head);
void printCodes(struct Node* root, int arr[], int top);
void huffmanCodes(char data[], int frequency[], int size);

int main() {
    // Create arrays for the data
    char data[] = {'a', 'b', 'r', 'c', 'd'};
    int frequency[] = {5, 2, 2, 1, 1};
    int size = sizeof(data) / sizeof(data[0]);

    huffmanCodes(data, frequency, size);

    return 0;
}

//  create a new node for priority queue
struct Node* createNode(char data, int frequency) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->frequency = frequency;
    new_node->left = new_node->right = new_node->next = NULL;
    return new_node;
}

//  create an empty priority queue (linked list)
struct Node* createQueue() {
    return NULL;
}

//  enqueue a node into the priority queue
void enqueue(struct Node** head_ref, struct Node* new_node) {
    if ((*head_ref == NULL) || ((*head_ref)->frequency) >= (new_node->frequency)) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        struct Node* current = *head_ref;
        while ((current->next != NULL) && (current->next->frequency) < (new_node->frequency)) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

//  dequeue a node from the priority queue
struct Node* dequeue(struct Node** head_ref) {
    if (isQueueEmpty(*head_ref)) {
        return NULL;
    }

    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    temp->next = NULL;
    return temp;
}

//  check if the priority queue is empty
int isQueueEmpty(struct Node* head) {
    return (head == NULL);
}

//  build the Huffman Tree and return the root
struct Node* buildHuffmanTree(struct Node* head) {
    while (!isQueueEmpty(head) && head->next != NULL) {
        struct Node* left = dequeue(&head);
        struct Node* right = dequeue(&head);

        struct Node* new_node = createNode('$', left->frequency + right->frequency);
        new_node->left = left;
        new_node->right = right;

        enqueue(&head, new_node);
    }

    return head;
}

// print Huffman codes from the Huffman Tree
void printCodesHelper(struct Node* root, int arr[], int top) {
    if (root->left != NULL) {
        // assign left side as 0
        arr[top] = 0;
        printCodesHelper(root->left, arr, top + 1);
    }

    if (root->right != NULL) {
        // assign right side as 1
        arr[top] = 1;
        printCodesHelper(root->right, arr, top + 1);
    }
    // if we reach the leaf node
    if (root->left == NULL && root->right == NULL) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// print the codes
void printCodes(struct Node* root, int arr[], int top) {
    printf("Huffman Codes:\n");
    printCodesHelper(root, arr, top);
}

//  perform Huffman coding
void huffmanCodes(char data[], int frequency[], int size) {
    struct Node* head = createQueue();

    // Create nodes for each character and enqueue them into the priority queue
    for (int i = 0; i < size; i++) {
        struct Node* new_node = createNode(data[i], frequency[i]);
        enqueue(&head, new_node);
    }

    // Build the Huffman Tree
    struct Node* root = buildHuffmanTree(head);

    // Print Huffman codes
    int arr[100]; // Assuming a maximum of 100 bits for Huffman codes
    int top = 0;
    printCodes(root, arr, top);
}



