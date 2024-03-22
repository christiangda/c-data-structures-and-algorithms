/**
 * @file vector.h
 * @author Christian González Di Antonio <chirisitangda@gmail.com>
 * @brief Structs and Prototype Function of a Linked List implementation to store generic values
 * @version 0.1
 * @date 2024-03-21
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>

typedef struct Item
{
  void *content;
  struct Item *next;
} Item;

typedef struct Vector
{
  Item *head;
  size_t item_size;
  size_t size;
} Vector;

Vector *vector_new(size_t item_size);
void vector_destroy(Vector *vector);
void vector_add(Vector *vector, void *value);
void vector_insert(Vector *vector, size_t index, void *value);

#endif // VECTOR_H