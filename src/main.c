#include <_stdio.h>
#include <stdio.h>

// maybe i should build a recursive and iterative version of each function?

typedef struct node {
  int Value;
  // void *Value;
  struct node *NextNode;
  // should i keep track of the total size of the linked list?
} node;

void PrintEachNode(node *Head, int NodeCount) {
  NodeCount++;
  printf("#%i: %p\n", NodeCount, Head);
  if (Head == NULL || Head->NextNode == NULL) {
    return;
  }
  PrintEachNode(Head->NextNode, NodeCount);
}

void PreAppend() {}
void InsertNode(node *Node, node *NewNode) {}
void ReverseList(node *Head) {}
int GetListLength(node *Head) {}
void ListFindMiddle(node *Head) {}
void MergeList(node *Head) {}

void AppendNode(node *Node, void *NewNode) {
  if (Node->NextNode == NULL) {
    Node->NextNode = NewNode;
    return;
  }
  AppendNode(Node->NextNode, NewNode);
}
// but what happens if I remove a node in the middle of two nodes?
/// Head and node you want to delete
void RemoveNode(node *Head, node *DeleteNode) {
  // i need to keep reucrisng until I know what the node above the node i want
  // to delete is so i can point the above node to whatever the node im going to
  // delete is pointed to
  //
  // 1
  // 2 (head)
  // 3 (current)
  // 4 (delete)
  // 5
  //
  // New list
  // 1
  // 2
  // 3
  // 5

  // if (Head == DeleteNode) {
  //   Head = Head->NextNode;
  // }
  //
  // if (Head->NextNode == DeleteNode && DeleteNode->NextNode != NULL) {
  //   Head->NextNode = DeleteNode->NextNode;
  //   DeleteNode->NextNode = NULL;
  //   return;
  // }
  // RemoveNode(Head->NextNode, DeleteNode);

  node *PreviousNode = NULL;
  while (1) {
    if (Head == DeleteNode) {
      Head = DeleteNode->NextNode;
      printf("Head %p\n", Head);
      break;
    }

    printf("PreviousNode %p", PreviousNode);
    PreviousNode = Head;
    Head = Head->NextNode;
  }
}

int main(void) {
  int n = 10;
  int y = 11;
  printf("addr=%p\n", &n);
  printf("addr=%p\n\n", &y);
  int *np = &n;
  int *yp = &y;
  printf("np=%p\n", np);
  printf("yp=%i\n", *yp);

  printf("np=%p\n", np);
  printf("yp=%i\n", *yp);

  printf("------------------\n");

  node Head = {.Value = 1, .NextNode = NULL};
  node Node2 = {.Value = 2, .NextNode = NULL};
  node Node3 = {.Value = 3, .NextNode = NULL};
  node Node4 = {.Value = 4, .NextNode = NULL};
  node Node5 = {.Value = 5, .NextNode = NULL};
  // printf("#1: %p\n", &Head);
  // printf("#2 %p\n", &Node2);
  // printf("#3: %p\n", &Node3);
  // printf("#4 %p\n", &Node4);
  // printf("#5: %p\n", &Node5);
  AppendNode(&Head, &Node2);
  AppendNode(&Head, &Node3);
  AppendNode(&Head, &Node4);
  AppendNode(&Head, &Node5);
  PrintEachNode(&Head, 0);
  printf("---------------\n");
  RemoveNode(&Head, &Head);
  PrintEachNode(&Head, 0);
}
