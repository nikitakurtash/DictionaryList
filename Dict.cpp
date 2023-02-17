#include <iostream>
#include "DictionaryList.h"

using namespace std;

#define type string

int main()
{
    DictionaryList<type> list1;
    DictionaryList<type> list2;

    
    list1.insert_item("abc");
    list1.insert_item("mno");
    list1.insert_item("def");
    list1.insert_item("jkl");
    list1.insert_item("ghi");

    cout << "Full List1:" << endl;
    list1.print_items();

    list2.insert_item("df");
    list2.insert_item("ghi");
    list2.insert_item("zia");

    cout << "Full List2:" << endl;
    list2.print_items();

    cout << endl;

    list2.delete_item("ghi");

    cout << "List2 without 'ghi': " << endl;
    list2.print_items();

    cout << endl;

    cout << "List 1 has 'abc': " << list1.search_item("abc") << endl;
    cout << "List 1 has 'def': " << list1.search_item("def") << endl;
    cout << "List 1 has 'ghi': " << list1.search_item("ghi") << endl;
    cout << "List 1 has 'jkl': " << list1.search_item("jkl") << endl;
    cout << "List 1 has 'mno': " << list1.search_item("mno") << endl;

    cout << endl;

    cout << "List 2 has 'def': " << list2.search_item("def") << endl;
    cout << "List 2 has 'ghi': " << list2.search_item("ghi") << endl;
    cout << "List 2 has 'zia': " << list2.search_item("zia") << endl;

    cout << endl;

    DictionaryList<type>::merge_items(&list1, &list2);

    cout << "Merge output:" << endl;
    list1.print_items();
    cout << endl;

    DictionaryList<type> getIntersection = DictionaryList<type>::getIntersection(&list1, &list2);

    cout << "Intersection lists: " << endl;
    getIntersection.print_items();
    cout << endl;

    DictionaryList<type>::delete_items(&list1, &getIntersection);

    cout << "List1 without intersection: " << endl;
    list1.print_items();

}