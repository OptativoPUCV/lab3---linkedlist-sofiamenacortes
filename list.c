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
  if(list->head != NULL)
  {
    list->head->prev = newNode;
  }
  else{
    list->tail = newNode;
  }
  list->head = newNode;
  list->size++;  
  
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
    if(list == NULL || list->current == NULL)
    {
        return;
    }
  Node* newNode = createNode(data);
  newNode->prev = list->current;
  newNode->next = list->current->next;

  if(list->current->next !=NULL)
  {
    list->current->next->prev = newNode; //el nodo que estaba despues del current se convierte en el prev del nuevo nodo
  }
  else{
    list->tail = newNode; //si el current era el ultimo nodo, el nuevo nodo se convierte en el nuevo
  }

  list->current->next = newNode;
  list->current = newNode;
  list->size++;
  
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
  if(list ==  NULL || list->current == NULL)
  {
    return NULL;
  }

  void* data = list->current->data;

  if(list->current->prev != NULL)
  {
    list->current->prev->next = list->current->next;
  }
  else{
    list->head = list->current->next;
  }

  if(list->current->next != NULL)
  {
    list->current->next->prev = list->current->prev;
  }
  else{
    list->tail = list->current->prev;
  }
  free(list->current);
  list->current = NULL;
  list->size++;
  return data;
  
    
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}

