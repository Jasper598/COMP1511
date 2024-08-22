#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_LEN 100

struct arg_node {
    char data[MAX_LEN];
    struct arg_node *next;
};

static struct arg_node *strings_to_list(int len, char *strings[]);
int evaluate_reverse_polish_notation(struct arg_node *head);
void free_arg_list(struct arg_node *head);


// your exam q6 code here!
int evaluate_reverse_polish_notation(struct arg_node *head) {
    struct arg_node *n = head;
    
    return 0;
}


///////////// PROVIDED CODE ///////////////
// DO NOT MODIFY THESE FUNCTIONS

// we may use a different main function for marking
// please ensure your evaluate_reverse_polish_notation function is implemented. 
// DO NOT MODIFY THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    int length = argc - 1;
    struct arg_node *head = strings_to_list(length, &argv[1]);

    printf("%d\n", evaluate_reverse_polish_notation(head));
    free_arg_list(head);

    return 0;
}

// create linked list from array of strings
static struct arg_node *strings_to_list(int len, char *strings[]) {
    struct arg_node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct arg_node *n = malloc(sizeof (*n));
        assert(n != NULL);
        n->next = head;
        strcpy(n->data, strings[i]);
        head = n;
    }
    return head;
}

void free_arg_list(struct arg_node *head) {
    if (head == NULL) return;
    free_arg_list(head->next);
    free(head);
}

