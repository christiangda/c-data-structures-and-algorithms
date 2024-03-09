#include "../include/linked_list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_list_new()
{
  List *list = list_new();

  assert(list->head == NULL);
  assert(list->size == 0);
}

void test_list_size_new()
{
  List *list = list_new();

  assert(list_size(list) == 0);
}

void test_prepend_to_new_list()
{
  List *list = list_new();
  Node *node = malloc(sizeof(Node));
  node->next = NULL;

  list_prepend(list, node);

  assert(list_size(list) == 1);
}

void test_prepend_10()
{
  List *list = list_new();

  for (int i = 0; i < 10; i++)
  {
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    list_prepend(list, node);
  }

  assert(list_size(list) == 10);
}

void test_append_10()
{
  List *list = list_new();

  for (int i = 0; i < 10; i++)
  {
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    list_append(list, node);
  }

  assert(list_size(list) == 10);
}

void test_list_destroy_10()
{
  List *list = list_new();

  for (int i = 0; i < 10; i++)
  {
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    list_prepend(list, node);
  }

  assert(list_size(list) == 10);

  list_destroy(list);
}

void test_list_prepend_value()
{
  List *list = list_new();

  for (int i = 10; i > 0; i--)
  {
    int *val = malloc(sizeof(int));
    *val = i;
    list_prepend_value(list, val, sizeof(int));
  }

  Node *temp_node = list->head;
  for (int i = 0; i < 10; i++)
  {
    // int *val = (int *)temp_node->data;
    // printf("value = %d, size = %zu (bytes)\n", *val, temp_node->size);

    assert(sizeof(int) == temp_node->size);
    temp_node = temp_node->next;
  }

  assert(list_size(list) == 10);
  list_destroy(list);
}

void test_list_append_value()
{
  List *list = list_new();

  for (int i = 10; i > 0; i--)
  {
    int *val = malloc(sizeof(int));
    *val = i;
    list_append_value(list, val, sizeof(int));
  }

  Node *temp_node = list->head;
  for (int i = 0; i < 10; i++)
  {
    // int *val = (int *)temp_node->data;
    // printf("value = %d, size = %zu (bytes)\n", *val, temp_node->size);

    assert(sizeof(int) == temp_node->size);
    temp_node = temp_node->next;
  }

  assert(list_size(list) == 10);
  list_destroy(list);
}

void tests_run_all(void)
{
  test_list_new();
  test_list_size_new();
  test_prepend_to_new_list();
  test_prepend_10();
  test_append_10();
  test_list_destroy_10();
  test_list_prepend_value();
  test_list_append_value();
}

int main(void)
{
  tests_run_all();
}