/**
 * @file vector.c
 * @author Christian González Di Antonio <chirisitangda@gmail.com>
 * @brief Implementation of Linked List
 * @version 0.1
 * @date 2024-03-21
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "../include/vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Vector *vector_new(size_t item_size)
{
  if (item_size == 0)
  {
    return NULL;
  }

  Vector *vector = malloc(sizeof(Vector));

  vector->item_size = item_size;
  vector->size = 0;
  vector->head = NULL;

  return vector;
}

void vector_destroy(Vector *vector)
{
  while (vector->head != NULL)
  {
    Item *delete = vector->head;
    vector->head = delete->next;

    free(delete->content);
    free(delete);
  }

  free(vector);
}

void vector_add(Vector *vector, void *value)
{
  if (vector == NULL || value == NULL)
  {
    fprintf(stderr, "Invalid arguments on vector_add\n");
    exit(EXIT_FAILURE);
  }

  Item *new_item = malloc(vector->item_size);
  new_item->content = value;

  new_item->next = vector->head;
  vector->head = new_item;
  vector->size++;
}

void vector_insert(Vector *vector, size_t index, void *value)
{
  if (vector == NULL || value == NULL)
  {
    fprintf(stderr, "Invalid arguments on vector_insert\n");
    exit(EXIT_FAILURE);
  }

  if (index > vector->size)
  {
    fprintf(stderr, "Invalid index, out of range in vector_insert\n");
    exit(EXIT_FAILURE);
  }

  Item *new_item = malloc(vector->item_size);
  new_item->next = NULL;

  new_item->content = malloc(sizeof(vector->item_size));
  memcpy(new_item->content, value, vector->item_size);

  if (vector->head == NULL) // first element, and index should be 0 too,
  {
    vector->head = new_item;
    vector->size++;
    return;
  }

  // here the list has at least 1 element
  Item *current = vector->head; // track current from the beginning of the list
  Item *next = NULL;            // track next node
  if (vector->head->next != NULL)
  {
    next = vector->head->next;
  }

  if (index == 0) // we will prepend and point the vector->head
  {
    new_item->next = current;
    vector->head = new_item;
    vector->size++;
    return;
  }

  size_t i = 0;
  while (i < index)
  {
    current = next; // move until the index
  }

  new_item->next = next;
  current->next = new_item;

  vector->size++;
}