typedef struct ListNode {
	    int key;
	        int value;
		    struct ListNode *next;
} node;

void print_node(node *print);
node * find_last(node *node);
int list_append(node *root, node *new);
node * node_new(int value);
node *list_search(node *current, int key);
void list_each(node *current, void (*func)(node *));
int list_size(node *current, int size);
