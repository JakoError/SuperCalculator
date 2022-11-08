//
// Created by JakoError on 2020/12/26.
//
#pragma once
#ifndef MATRIX_HASHMAP_H
#define MATRIX_HASHMAP_H
#pragma warning (disable:4819)

#include "matrix_c.h"

#include <stdbool.h>

#define KEY_TYPE char*
#define VALUE_TYPE Matrix

#define DEFAULT_MAP_LENGTH 100
int times;

typedef struct {
    KEY_TYPE key;
    VALUE_TYPE value;
} DataType;

typedef struct node {
    DataType data;
    struct node *next;
} HashNode;

typedef struct {
    int size;
    HashNode map[DEFAULT_MAP_LENGTH];
} HashMap;

/*
 * 乘法hash算法，乘数为31（jdk8）
 * @param key --it should be string
 * @return hashcode of string-->abs
 */
int hash(char key[]);

/*
 * creat hashmap with existing keys and values
 * if key and value are null, the map will be empty
 * we allow keys or values are null
 *
 * when size is out of bound we have no idea to control it in C
 * @param keys format as string(i use strlen to do it)
 * @param values
 * @param size it is important to deal with size
 * @return hashmap
 */

HashMap *createHashMap(KEY_TYPE keys[], Matrix *values, int size);

//---增
bool putData(HashMap *hm, KEY_TYPE key, VALUE_TYPE value);

bool putAllData(HashMap *hm, KEY_TYPE key[], VALUE_TYPE value[], int size);

//---删
bool delete(HashMap *hm, KEY_TYPE key);

//--查
VALUE_TYPE *getValue(HashMap *hm, KEY_TYPE key);

DataType *getAllData(HashMap *hm);

void clear(HashMap *hm);

#endif //MATRIX_HASHMAP_H
