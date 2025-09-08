#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

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

Node *array_to_list(int *array, int array_len) {
  if (array_len == 0) {
    return NULL;
  }
  Node *head = malloc(sizeof(Node));
  head->value = array[0];
  head->next = NULL;

  Node *current_node = head;
  for (int i = 1; i < array_len; i++) {
    current_node->next = malloc(sizeof(Node));
    current_node = current_node->next;
    current_node->value = array[i];
    current_node->next = NULL;
  }

  return head;
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
  int arr[3] = {0, 1, 2};
  Node *head = array_to_list(arr, 3);
  print_list(head);
}
