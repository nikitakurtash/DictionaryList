#pragma once

#ifndef __DICTIONARY_LIST_H__
#define __DICTIONARY_LIST_H__

#include <iostream>

using namespace std;

template<typename T>
class DictionaryList {
private:
    struct Node {
        T item;
        Node* next;
    };

    Node* head;

public:
    DictionaryList();
    DictionaryList(const DictionaryList& list);
    DictionaryList(DictionaryList&& list) noexcept;
    ~DictionaryList();

    void insert_item(T item);
    void delete_item(T item);
    bool search_item(T item);
    void print_items();

    void swap(DictionaryList& other) noexcept;
    bool isEmpty();
    static void merge_items(DictionaryList* list1, DictionaryList* list2);
    static void delete_items(DictionaryList* list1, DictionaryList* list2);
    static DictionaryList getIntersection(DictionaryList* list1, DictionaryList* list2);
    DictionaryList& operator=(DictionaryList&& list) noexcept;
    
};

#endif