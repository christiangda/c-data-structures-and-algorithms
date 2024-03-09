#include "../include/linked_list.h"
#include <stdio.h>
#include <stdlib.h>

List *list_new()
{
  List *l = (List *)malloc(sizeof(List));
  l->head = NULL;
  l->tail = NULL;
  l->size = 0;

  return l;
}

void list_destroy(List *list)
{
  if (list->head == NULL)
  {
    free(list);
    return;
  }

  Node *temp_node = NULL;

  while (list->head != NULL)
  {
    temp_node = list->head;
    list->head = temp_node->next;

    free(temp_node->data);
    free(temp_node);
  }

  free(list);
}

void list_prepend(List *list, Node *node)
{
  if (list == NULL || node == NULL)
  {
    return;
  }

  // store the pointer to the first element prepend to the list
  if (list->size == 0)
  {
    list->tail = node;
  }

  node->next = list->head;
  list->head = node;
  list->size++;
}

void list_append(List *list, Node *node)
{
  if (list == NULL || node == NULL)
  {
    return;
  }

  node->next = NULL;

  if (list->size == 0)
  {
    list->head = node;
    list->tail = node;
  }

  // add the node to the tail of the list
  list->tail->next = node;
  list->tail = node;

  list->size++;
}

size_t list_size(List *list)
{
  return list->size;
}

void list_prepend_value(List *list, void *value, size_t size)
{
  Node *node = malloc(sizeof(Node));
  node->next = NULL;

  node->data = malloc(size);
  node->data = value;
  node->size = size;

  list_prepend(list, node);
}

void list_append_value(List *list, void *value, size_t size)
{
  Node *node = malloc(sizeof(Node));
  node->next = NULL;

  node->data = malloc(size);
  node->data = value;
  node->size = size;

  list_append(list, node);
}