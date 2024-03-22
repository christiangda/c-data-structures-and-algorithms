#include "../include/vector.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void test_vector_new()
{
  Vector *vector = vector_new(sizeof(int));

  assert(vector->size == 0);
  assert(vector->item_size == sizeof(int));
  assert(vector->head == NULL);

  vector_destroy(vector);
}

static void test_vector_destroy()
{
  Vector *vector = vector_new(sizeof(int));

  int len = 1000;
  for (int i = 0; i < len; i++)
  {
    // will be free by vector_destroy
    int *val = malloc(sizeof(int));
    // memmove(val, &i, sizeof(int));
    memcpy(val, &i, sizeof(int));

    vector_add(vector, val);
  }

  vector_destroy(vector);
}

static void test_vector_add()
{
  Vector *vector = vector_new(sizeof(int));

  int len = 100;
  for (int i = 0; i < len; i++)
  {
    // will be free by vector_destroy
    int *val = malloc(sizeof(int));
    // memmove(val, &i, sizeof(int));
    memcpy(val, &i, sizeof(int));

    vector_add(vector, val);
  }

  assert(vector->size == (size_t)len);

  // check values
  Item *item = vector->head;
  for (int i = len - 1; i >= 0; i--)
  {
    assert(vector->item_size = sizeof(int));

    int *val = (int *)item->content;
    // printf("val: %d, i:%d\n", *val, i);

    assert(*val == i);

    item = item->next;
  }

  vector_destroy(vector);
}

static void test_vector_insert_index_0()
{
  Vector *vector = vector_new(sizeof(int));

  int len = 100;
  for (int i = 0; i < len; i++)
  {
    // will be free by vector_destroy
    int *val = malloc(sizeof(int));
    memcpy(val, &i, sizeof(int));

    // printf("filling val: %d, i:%d\n", *val, i);
    vector_insert(vector, (size_t)0, val);

    free(val);
  }

  assert(vector->size == (size_t)len);

  // puts("");

  //  check values
  Item *item = vector->head;
  for (int i = (len - 1); i > 0; i--)
  {
    assert(vector->item_size = sizeof(int));

    int *val = (int *)item->content;

    // printf("checking val: %d, i:%d\n", *val, i);
    assert(*val == i);

    if (item->next != NULL)
    {
      item = item->next;
    }
  }

  vector_destroy(vector);
}

void tests_run_all(void)
{
  test_vector_new();
  test_vector_add();
  test_vector_destroy();
  test_vector_insert_index_0();
}

int main(void)
{
  tests_run_all();
}