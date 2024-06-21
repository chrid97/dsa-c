#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct Node {
  int value;
  struct Node *next;
} Node;

Node *BuildOneTwoThree() {
  Node *head = malloc(sizeof(Node));
  head->next = malloc(sizeof(Node));
  head->next->next = malloc(sizeof(Node));

  head->value = 1;
  head->next->value = 2;
  head->next->next->value = 3;
  head->next->next->next = NULL;

  return head;
}

int length(Node *node) {
  int count = 0;
  Node *current = node;
  while (current != NULL) {
    count++;
    current = current->next;
  }

  return count;
}

void insert_node(Node **node, int data) {
  Node *new_node = malloc(sizeof(Node));
  new_node->value = data;
  new_node->next = *node;

  *node = new_node;
}

Node *search_list(Node *head, int value) {
  if (head == NULL) {
    return NULL;
  }

  if (head->value == value) {
    return head;
  }

  return search_list(head->next, value);
}

Node *item_ahead(Node *node, Node *node2) {
  if (node == NULL || node->next == NULL) {
    return NULL;
  }

  if (node->next == node2) {
    return node;
  }

  return item_ahead(node->next, node2);
}

void delete_node(Node **head, Node *node) {
  Node *prev_node = item_ahead(*head, node);
  prev_node->next = node->next;
  free(node);
}

void print_list(Node *head) {
  Node *current = head;
  while (current != NULL) {
    printf("%d", current->value);
    current = current->next;
    if (current != NULL) {
      printf(" -> ");
    }
  }
  printf("\n");
}

int main() {
  Node *head = BuildOneTwoThree();
  insert_node(&head, 0);

  /* printf("OG Head: %p\n", head->next->next); */
  /* Node *new = search_list(head, 2); */
  /* printf("%p\n", new); */
  /* printf("head: %d\n", head->next->value); */
  print_list(head);
  delete_node(&head, head->next);
  print_list(head);
}
