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
