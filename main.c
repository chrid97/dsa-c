#include <stdio.h>
#include <stdlib.h>
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

void WrongPush(Node *node, int data) {
  /* Node *newNode = &(Node){.value = data, .next = node}; */
  Node *newNode = malloc(sizeof(Node));
  newNode->value = data;
  newNode->next = node;
  node = newNode;
}

void Push(Node **node, int data) {
  Node *newNode = malloc(sizeof(Node));
  newNode->value = data;
  newNode->next = *node;

  *node = newNode;
}

int main() {
  Node *head = BuildOneTwoThree();
  Push(&head, 0);
  /* printf("%p\n", &head); */
  /* printf("head: %d\n", head->value); */
}
