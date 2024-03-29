#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
    int size;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List * newList = (List *)malloc(sizeof(List));
    newList->head = NULL;
    newList->tail = NULL;
    newList->current = NULL;
    return newList;   
}

void * firstList(List * list) {
    if (list == NULL || list->head == NULL)
    {
        return NULL;
    }
    list->current = list->head;
    return list->current->data;   
}

void * nextList(List * list) {
  if (list == NULL || list->current == NULL || list->current->next == NULL)
  {
    return NULL;
  }

  list->current = list->current->next;
  return list->current->data;
    
}

void * lastList(List * list) {
    if (list == NULL || list->tail == NULL)
    {
        return NULL;
    }
    list->current = list->tail;
    return list->current->data;
  
}

void * prevList(List * list) {
  if (list->current == NULL || list->current->prev == NULL)
  {
    return NULL;
  }
  list->current = list->current->prev;
  return list->current->data;
  
}

void pushFront(List * list, void * data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = list->head;
  if(list->head) 
  {
    list->head->prev = newNode;
  }
  list->head = newNode;
  list->size++;  
  
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}

/* Node * newNode = createNode(data);
if (list->head == NULL)
{
    list->tail = newNode;
}
else
{
    list->head->prev = newNode;      
}
//list->head = newNode;
if (list->current == NULL)
{
  list->current = newNode;
}*/