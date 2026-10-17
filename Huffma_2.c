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

struct Node* extractMin(struct Node* heap[], int *size) {
    int min = 0;

    for (int i = 1; i < *size; i++)
        if (heap[i]->freq < heap[min]->freq)
            min = i;

    struct Node* result = heap[min];

    for (int i = min; i < *size - 1; i++)
        heap[i] = heap[i + 1];

    (*size)--;
    return result;
}

void printCodes(struct Node* root, int code[], int top,
                long long *totalBits) {
    if (root->left) {
        code[top] = 0;
        printCodes(root->left, code, top + 1, totalBits);
    }

    if (root->right) {
        code[top] = 1;
        printCodes(root->right, code, top + 1, totalBits);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->ch);

        for (int i = 0; i < top; i++)
            printf("%d", code[i]);

        printf("\n");
        *totalBits += (long long)root->freq * top;
    }
}

int main() {
    char ch[] = {'a', 'c', 'd', 'e', 'o', 'm', 's', 't', 'u'};
    int freq[] = {20, 11, 2, 10, 15, 8, 10, 22, 2};
    int size = 9;

    struct Node* heap[20];

    for (int i = 0; i < size; i++)
        heap[i] = createNode(ch[i], freq[i]);

    while (size > 1) {
        struct Node* x = extractMin(heap, &size);
        struct Node* y = extractMin(heap, &size);

        struct Node* parent =
            createNode('$', x->freq + y->freq);

        parent->left = x;
        parent->right = y;

        heap[size++] = parent;
    }

    int code[100];
    long long totalBits = 0;

    printf("Huffman Codes:\n");
    printCodes(heap[0], code, 0, &totalBits);

    printf("\nTotal bits = %lld\n", totalBits * 100);
    printf("Total bytes = %lld\n", totalBits * 100 / 8);

    return 0;
}
