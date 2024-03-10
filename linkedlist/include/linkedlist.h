/**
 * @file linkedlist.h
 * @author Christian González Di Antonio <chirisitangda@gmail.com>
 * @brief Structs and Prototype Function of a Linked List implementation to store generic values
 * @version 0.1
 * @date 2024-03-10
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>

typedef struct Node
{
  // size of the data type
  size_t size;
  void *data;
  struct Node *next;
} Node;

typedef struct List
{
  Node *head;
  size_t size;

  // used to have a reference to the last node, but
  // this is not a circular linked list
  Node *tail;
} List;

/**
 * @brief Create a new Linked List
 *
 * This function create a new Linked List using malloc to allocate in the heap space
 * for the Linked List struct.
 * @code
 * #include "linked_list.h"
 * ...
 *  List list = list_new();
 * ...
 *
 * @return List*
 */
List *list_new();

/**
 * @brief Destroy (free) a Linked List resources created with 'list_new' function
 *
 * This function free all the resources allocated in a Linked List when these are
 * allocated using malloc function.  Designed to be used when a Linked List is create
 * using 'list_new' function.
 *
 * @param list Linked List created with 'list_new' function
 * @return Void.
 */
void list_destroy(List *list);

/**
 * @brief Destroy (free) a Node resource
 *
 * This function free resources allocated for a Node of a Linked List when
 * malloc function is used.
 *
 * @param node Node to be destroyed
 * @return Void.
 */
void list_node_destroy(Node *node);

/**
 * @brief Insert a Node in the head of the Linked List.
 *
 * This function insert a Node at the beginning (head) of the Linked List.
 *
 * @param list Linked List created with 'list_new' function
 * @param node Node to be inserted in the list
 * @return Void.
 */
void list_prepend(List *list, Node *node);

/**
 * @brief Insert a Node in the tail of the Linked List.
 *
 * This function insert a Node at the end (tail) of the Linked List.
 *
 * @param list Linked List created with 'list_new' function
 * @param node Node to be inserted in the list
 * @return Void.
 */
void list_append(List *list, Node *node);

/**
 * @brief Insert value of any type in the head of the Linked List.
 *
 * This function insert a value at the beginning (head) of the Linked List
 * creating a Node to store this value.
 *
 * @note The resources allocated for the Node should be free using list_destroy.
 *
 * @param list Linked List created with 'list_new' function
 * @param value Valued to be inserted in the list
 * @param size Size of the value to be inserted
 * @return Void.
 */
void list_prepend_value(List *list, void *value, size_t size);

/**
 * @brief Insert value of any type in the tail of the Linked List.
 *
 * This function insert a value at the end (tail) of the Linked List
 * creating a Node to store this value.
 *
 * @note The resources allocated for the Node should be free using list_destroy.
 *
 * @param list Linked List created with 'list_new' function
 * @param value Valued to be inserted in the list
 * @param size Size of the value to be inserted
 * @return Void.
 */
void list_append_value(List *list, void *value, size_t size);

/**
 * @brief Return (extract) a Node from the beginning (head) of the Linked List.
 *
 * This function extract a Node from the head of the Linked List.
 *
 * @note Given the node returned was extracted from the Linked List you must
 * free the resources allocated for this node using free function or
 * list_node_destroy fuction.
 *
 * @ref list_node_destroy
 *
 * @param list Linked List created with 'list_new' function
 * @return Node* Node from the head of the Linked List.
 */
Node *list_pop(List *list);

/**
 * @brief Return the size of the Linked List
 *
 * @param list Linked List created with 'list_new' function
 * @return size_t The size of the Linked List.
 */
size_t list_size(List *list);

#endif // LINKEDLIST_H