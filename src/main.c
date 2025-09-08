#include <_stdio.h>
#include <stdio.h>

typedef struct node {
  int Value;
  // void *Value;
  struct node *NextNode;
  // should i keep track of the total size of the linked list?
} node;

// design decision
// Do i just append a node to the current node? But what if new node has a node
// after it? then it just replaces it This should probably be append node and we
// keep iterating until we hit the end
void AppendNode(node *Node, void *new_node) { Node->NextNode = new_node; }
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
  if (Head->NextNode == DeleteNode && DeleteNode->NextNode != NULL) {
    Head->NextNode = DeleteNode->NextNode;
  }

  if (DeleteNode->NextNode != NULL) {
    Head->NextNode = DeleteNode->NextNode;
  }
  DeleteNode->NextNode = NULL;
}

int main(void) {
  node Head = {.Value = 1, .NextNode = NULL};
  node Node2 = {.Value = 2, .NextNode = NULL};
  node Node3 = {.Value = 3, .NextNode = NULL};
  node Node4 = {.Value = 4, .NextNode = NULL};
  node Node5 = {.Value = 5, .NextNode = NULL};
  AppendNode(&Head, &Node2);
  AppendNode(&Head, &Node2);
  AppendNode(&Head, &Node3);
  AppendNode(&Head, &Node4);
  AppendNode(&Head, &Node5);
}
