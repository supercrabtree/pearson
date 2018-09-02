#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

Node* createNode() {
  Node *newNode = (Node *) malloc(sizeof(Node));
  newNode->value = 0;
  newNode->next = NULL;
  return newNode;
}

int main() {
  int c, i, largest;
  Node *root;
  Node *head;

  largest = 0;
  root = createNode();
  head = root;

  while((c = getchar()) != EOF && c != 10) {
    if (c == ' ') {
      head->next = createNode();
      head = head->next;
    } else {
      head->value++;
      if (head->value > largest) {
        largest = head->value;
      }
    }
  }

  i = largest;

  while (i > 0) {
    head = root;
    while (head != NULL) {
      if (head->value >= i) {
        printf("█");
      }
      else {
        printf(" ");
      }
      head = head->next;
    }
    printf("\n");
    i--;
  }
}
