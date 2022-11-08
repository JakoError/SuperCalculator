#pragma warning (disable:4819)
//
// Created by JakoError on 2020/12/26.
//
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "hashMap.h"
#include "matrix_c.h"


int hash(char key[]) {
    int hash = 0;
    if (key != NULL)//null ????0
        for (int i = 0; i < strlen(key); ++i)
            hash = 31 * hash + key[i];
    return abs(hash);//???
}

HashMap *createHashMap(KEY_TYPE keys[], Matrix values[], int size) {
    if (keys == NULL && values == NULL && size != 0) {
        printf("\nFAILED TO CREAT MAP:SIZE is not equal to 0 when Keys and Value are null\n");
        return NULL;
    }
    //----------------------------------------------------------?????
    //we default to think malloc will be created successfully
    HashMap *hm = (HashMap *) malloc(sizeof(HashMap));

    clear(hm);

    if (!size)
        return hm;

    //-----------------------------------------------------------?????
    //?????????
    if (!putAllData(hm, keys, values, size))
        return NULL;

    return hm;
}

bool putData(HashMap *hm, KEY_TYPE key, VALUE_TYPE value) {
    if (hm == NULL)
        return false;
    int index = hash(key) % DEFAULT_MAP_LENGTH;
    HashNode *p = &(hm->map[index]);

    while (p->next != NULL) {
        if (strcmp(p->data.key, key) == 0) break;
        times++;
//        printf("?????%s-%s\n",key,p->data.key);
        p = p->next;
    }

    DataType *data = (DataType *) malloc(sizeof(DataType));
    data->key = malloc(sizeof(key));
    strcpy(data->key, key);
    data->value = value;
    p->data = *data;

    //----------------------------------------------------------?????
    p->next = (HashNode *) malloc(sizeof(HashNode));
    p->next->next = NULL;

    hm->size++;
    return true;
}

bool putAllData(HashMap *hm, KEY_TYPE key[], VALUE_TYPE value[], int size) {
    int ok = 0;
    for (int i = 0; i < size; ++i) {
        if (putData(hm, key[i], value[i]))
            ok++;
    }
    printf("\n???%d??????????%d??\n", size, ok);
    return ok == size;
}

//????§Õ????????¨°???
bool delete(HashMap *hm, KEY_TYPE key);

VALUE_TYPE *getValue(HashMap *hm, KEY_TYPE key) {
    int index = hash(key) % DEFAULT_MAP_LENGTH;
    HashNode *p = &hm->map[index];
    if (p->next == NULL)
        return NULL;
    if (p->next->next != NULL)
        while (strcmp(p->data.key,key)!=0) {
            p = p->next;
            if (p == NULL)
                return NULL;
        }
    return &p->data.value;
}

DataType *getAllData(HashMap *hm) {
    static DataType list[100];
    DataType *l = list;
    for (int i = 0; i < DEFAULT_MAP_LENGTH; ++i) {
        HashNode *p = &hm->map[i];
        if (p->next == NULL)
            continue;
        while (p->next != NULL) *(l++) = p->data;
    }
    return list;
}

void clear(HashMap *hm) {
    for (int i = 0; i < DEFAULT_MAP_LENGTH; ++i) {
        HashNode *temp = malloc(sizeof(HashNode));
        temp->next = NULL;
        hm->map[i] = *temp;
    }
    hm->size = 0;
}

