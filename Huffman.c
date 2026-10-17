#include <stdio.h>
#include <stdlib.h>

struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
};

struct Node* createNode(char ch, int freq) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->ch = ch;
    n->freq = freq;
    n->left = n->right = NULL;
    return n;
}

void generateCodes(struct Node* root, int code[], int top) {
    if (root->left) {
        code[top] = 0;
        generateCodes(root->left, code, top + 1);
    }

    if (root->right) {
        code[top] = 1;
        generateCodes(root->right, code, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->ch);
        for (int i = 0; i < top; i++)
            printf("%d", code[i]);
        printf("\n");
    }
}

int main() {
    int n, size;
    char ch;
    int freq;
    struct Node* heap[100];

    printf("Enter number of characters: ");
    scanf("%d", &n);
    size = n;

    for (int i = 0; i < n; i++) {
        printf("Enter character and frequency: ");
        scanf(" %c %d", &ch, &freq);
        heap[i] = createNode(ch, freq);
    }

    while (size > 1) {
        int min1 = 0, min2 = 1;

        if (heap[min1]->freq > heap[min2]->freq) {
            int temp = min1;
            min1 = min2;
            min2 = temp;
        }

        for (int i = 2; i < size; i++) {
            if (heap[i]->freq < heap[min1]->freq) {
                min2 = min1;
                min1 = i;
            } else if (heap[i]->freq < heap[min2]->freq) {
                min2 = i;
            }
        }

        struct Node* left = heap[min1];
        struct Node* right = heap[min2];

        struct Node* parent =
            createNode('$', left->freq + right->freq);

        parent->left = left;
        parent->right = right;

        if (min1 > min2) {
            int temp = min1;
            min1 = min2;
            min2 = temp;
        }

        for (int i = min2; i < size - 1; i++)
            heap[i] = heap[i + 1];

        for (int i = min1; i < size - 2; i++)
            heap[i] = heap[i + 1];

        heap[size - 2] = parent;
        size--;
    }

    int code[100];

    printf("\nHuffman Codes:\n");
    generateCodes(heap[0], code, 0);

    return 0;
}
