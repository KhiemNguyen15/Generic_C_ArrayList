#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <arraylist.h>

typedef struct Person
{
    char *name;
    int age;
} Person;

int sortByName(const void *a, const void *b)
{
    char *strA = ((Person *)(((Data *)a)->val))->name;
    char *strB = ((Person *)(((Data *)b)->val))->name;

    return strcmp(strA, strB);
}

int sortByAge(const void *a, const void *b)
{
    int ageA = ((Person *)(((Data *)a)->val))->age;
    int ageB = ((Person *)(((Data *)b)->val))->age;

    return (ageA < ageB) ? 1 : (ageA > ageB) ? -1 : 0; 
}

bool comparePerson(const void *a, const void *b)
{
    Person perA = *(Person *)a;
    Person perB = *(Person *)b;

    return (strcmp(perA.name, perB.name) == 0 && perA.age == perB.age);
}

int main(int argc, char **argv)
{
    List *list = createList();

    Person p1 = {"Charles", 20};
    Person p2 = {"Zach", 1928};
    Person p6 = {"Zach", 1928};
    Person p3 = {"Jake", 23};
    Person p4 = {"James", 29};
    Person p5 = {"Jason", 18};

    listAdd(&list, &p1);
    listAdd(&list, &p2);
    listAdd(&list, &p3);
    listAdd(&list, &p4);
    listAdd(&list, &p5);
    listAdd(&list, &p6);

    listSort(&list, sortByName);

    List *newList = listClone(list);

    for(int i = 0; i < listSize(newList); i++)
    {
        printf("Person %d:\n    Name: %s\n    Age: %d\n", i + 1, ((Person *)listGet(newList, i))->name, ((Person *)listGet(newList, i))->age);
    }
    Person toFind = {"Zach", 1928};
    Person toFind2 = {"Zack", 1928};
    printf("%d\n", listIndexOf(list, &toFind, comparePerson));
    printf("%d\n", listLastIndexOf(list, &toFind, comparePerson));
    printf("%d\n", listIndexOf(list, &toFind2, comparePerson));

    /*
    //Random class assignment
    int array[6] = {10,20,30,40,50,60};

    int *ptr = array;
    for(int i = 0; i < 6; i++)
        printf("%d ", *(ptr++));
    printf("\n");
    */
    /*
    listAdd(&list, "Howdy");
    listAdd(&list, "Sarah");
    listAdd(&list, "Jack");
    listAdd(&list, "Zach");
    listAdd(&list, "Henry");
    listAdd(&list, "Henry");
    listAdd(&list, "Henry");
    listAdd(&list, "Henry");
    listAdd(&list, "Henry");
    listAdd(&list, "Henry");
    listAdd(&list, "Henry");

    for(int i = 0; i < list->size; i++)
    {
        printf("%s ", (char *)listGet(list, i));
    }
    printf("\n%lu\n", list->capacity);

    ArrayList *newList = listClone(list);
    listClear(&list);

    for(int i = 0; i < list->size; i++)
    {
        printf("%s ", (char *)listGet(list, i));
    }
    printf("\n%lu\n", list->capacity);

    for(int i = 0; i < newList->size; i++)
    {
        printf("%s ", (char *)listGet(newList, i));
    }
    printf("\n%lu\n", newList->capacity);

    freeList(&newList);
    */

    freeList(&list);
    return 0;
}