#include "DictionaryList.h"

template<typename T> DictionaryList<T>::DictionaryList() {
    head = nullptr;
}

template DictionaryList<int>::DictionaryList<int>();
template DictionaryList<string>::DictionaryList<string>();

template<typename T> void DictionaryList<T>::insert_item(T item) {
    if (search_item(item)) return;

    if (head) {
        Node* current = head;

        if (item < current->item) {
            Node* new_node = new Node;

            new_node->item = item;
            new_node->next = head;
            head = new_node;

            return;
        }

        while (true) {
            if (item > current->item) {
                if (!current->next or (current->next and current->next->item > item)) {
                    Node* new_node = new Node;

                    new_node->item = item;
                    new_node->next = current->next;
                    current->next = new_node;

                    return;
                }
            }

            if (!current->next) break;

            current = current->next;
        }
    }
    else {
        head = new Node;

        head->item = item;
        head->next = nullptr;
    }
}

template void DictionaryList<int>::insert_item(int);
template void DictionaryList<string>::insert_item(string);

template<typename T> void DictionaryList<T>::delete_item(T item) {
    if (head) {
        Node* current = head;

        if (current->item == item) {
            Node* new_head = head->next;

            free(head);

            head = new_head;

            return;
        }

        while (current->next) {
            if (current->next->item == item) {
                Node* new_next = current->next->next;

                free(current->next);

                current->next = new_next;

                return;
            }

            if (!current->next) break;

            current = current->next;
        }
    }
}

template void DictionaryList<int>::delete_item(int);
template void DictionaryList<string>::delete_item(string);

template<typename T> bool DictionaryList<T>::search_item(T item) {
    if (head) {
        Node* current = head;

        while (true) {
            if (current->item == item) return true;

            if (!current->next) break;

            current = current->next;
        }
    }

    return false;
}

template bool DictionaryList<int>::search_item(int);
template bool DictionaryList<string>::search_item(string);

template<typename T> void DictionaryList<T>::print_items() {
    cout << "List: ";

    if (head) {
        Node* current = head;

        while (true) {
            cout << current->item << " ";

            if (!current->next) break;

            current = current->next;
        }

    }
    else {
        cout << "Empty";
    }

    cout << endl;
}

template void DictionaryList<int>::print_items();
template void DictionaryList<string>::print_items();

template<typename T> void DictionaryList<T>::merge_items(DictionaryList* list1, DictionaryList* list2) {
    if (list2->head) {
        Node* current = list2->head;

        while (true) {
            list1->insert_item(current->item);

            if (!current->next) return;

            current = current->next;
        }
    }
}

template void DictionaryList<int>::merge_items(DictionaryList*, DictionaryList*);
template void DictionaryList<string>::merge_items(DictionaryList*, DictionaryList*);

template<typename T> void DictionaryList<T>::delete_items(DictionaryList* list1, DictionaryList* list2) {
    if (list2->head) {
        Node* current = list2->head;

        while (true) {
            list1->delete_item(current->item);

            if (!current->next) return;

            current = current->next;
        }
    }
}

template void DictionaryList<int>::delete_items(DictionaryList*, DictionaryList*);
template void DictionaryList<string>::delete_items(DictionaryList*, DictionaryList*);

template<typename T> DictionaryList<T> DictionaryList<T>::getIntersection(DictionaryList* list1, DictionaryList* list2) {
    DictionaryList result;

    if (list1->head) {
        Node* current = list1->head;

        while (true) {
            if (list2->search_item(current->item)) result.insert_item(current->item);

            if (!current->next) return result;

            current = current->next;
        }
    }

    return result;
}

template DictionaryList<int> DictionaryList<int>::getIntersection(DictionaryList*, DictionaryList*);
template DictionaryList<string> DictionaryList<string>::getIntersection(DictionaryList*, DictionaryList*);