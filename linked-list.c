#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int key;
    int value;
    struct ListNode *next;
} node;

void print_node(node *print) {
    printf("Key: %d Value: %d Next: %d Address: %d\n",
            print->key,
            print->value,
            print->next,
            print);
}

void test_fn(node *current) {
    current->value += 1;
}


node * find_last(node *node) {
    return node->next == 0 ? node : find_last(node->next);
}

int list_append(node *root, node *new) {
    node *last = find_last(root);

    last->next = new;
    new->key = last->key + 1;
    return new->key;
}

node * node_new(int value) {
    node *new = malloc(sizeof(node));
    new->key = 0;
    new->next = 0;
    new->value = value;
    return new;
}

node * list_search(node *current, int key) {
    if (current->key == key)
        return current;
    else if (current->next == 0)
        return 0;
    else
        return list_search(current->next, key);
}

void list_each(node *current, void (*func)(node *)){
    func(current);
    if (current->next == 0)
        return;
    else
        list_each(current->next, func);
}

int list_size(node *current, int size) {
    size++;
    return current->next == 0 ? size : list_size(current->next, size);
}

int main() {
    node *root;
    root = node_new(rand());
    
    puts("Creating List...");
    int i;
    for(i = 0; i < 30000; i++) {
        list_append(root, node_new(rand()));
    }
    puts("List Created");
    puts("Iterating with a for loop...");
    for(i = 0; i < list_size(root, 0); i++) {
        test_fn(list_search(root, i));
    }
    puts("Job Finished");
    puts("Iterating with each...");
    list_each(root, &test_fn);
    puts("Job Finished");
} 
