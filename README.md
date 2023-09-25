# Generic Type Array List Documentation

## Introduction

This C library provides a dynamic array list implementation that can store and manage elements of any data type using a generic approach. It allows you to perform various operations on the list, such as adding, inserting, removing, and sorting elements. This library is designed to be flexible and easy to use, making it suitable for a wide range of applications.

## Getting Started

### Including the Library

```c
#include <arraylist.h>
```

### Creating an ArrayList

```c
ArrayList *createList(void)
```

Usage:

```c
ArrayList *list = createList();
```

* Creates a new empty ArrayList.
* Returns a pointer to the newly created ArrayList.

### Cloning an ArrayList

```c
ArrayList *listClone(const ArrayList *list)
```

Usage:

```c
ArrayList *newList = listClone(list);
```

* Creates a new ArrayList that is a deep copy of an existing ArrayList.
* Returns a pointer to the newly created ArrayList.

## Function Pointers

### Equality Function

```c
typedef bool (*EqualityFunction)(const void *, const void *);
```

* A function to compare elements for equality.

### Comparison Function

```c
typedef int (*CompareFunction)(const void *, const void *);
```

* A comparison function that defines the sorting order.

### Check Function

```c
typedef bool (*CheckFunction)(const void *);
```

* A function that returns the result of a checked conditional.

## Basic Operations

### Adding an Element

```c
void listAdd(ArrayList **listPtr, void *val)
```

Usage:

```c
listAdd(&list, element);
```

* Adds an element to the end of the ArrayList.
* `element`: A pointer to the element you want to add.

### Adding All Elements from Another ArrayList

```c
void listAddAll(ArrayList **listPtr, const ArrayList *toAdd)
```

Usage:

```c
listAddAll(&list, toAdd);
```

* Adds all elements from another ArrayList (`toAdd`) to the end of the current ArrayList.
* `toAdd`: A pointer to the ArrayList containing the elements to be added.

### Inserting an Element

```c
void listInsert(ArrayList **listPtr, void *val, const size_t index)
```

Usage:

```c
listInsert(&list, element, index);
```

* Inserts an element at a specified index in the ArrayList.
* `element`: A pointer to the element you want to insert.
* `index`: The index at which to insert the element.

### Setting an Element

```c
void listSet(ArrayList **listPtr, void *val, const size_t index)
```

Usage:

```c
listSet(&list, element, index);
```

* Sets the value of an element at a specified index in the ArrayList.
* `element`: A pointer to the new value.
* `index`: The index of the element to be updated.

### Retaining All Elements from Another ArrayList

```c
void listRetainAll(ArrayList **listPtr, const ArrayList *toRetain, EqualityFunction compare)
```

Usage:

```c
listRetainAll(&list, toRetain, compareFunction);
```

* Retains only the elements of another ArrayList (`toRetain`) in the current ArrayList.
* `toRetain`: A pointer to the ArrayList containing the elements to be retained.
* `compareFunction`: A function used to compare elements for equality.

### Removing an Element at an Index

```c
void listRemove(ArrayList **listPtr, const size_t index)
```

Usage:

```c
listRemove(&list, index);
```

* Removes an element at a specified index from the ArrayList.
* `index`: The index of the element to be removed.

### Removing the First Occurrence of an Element

```c
void listRemoveElement(ArrayList **listPtr, const void *toRemove, EqualityFunction compare)
```

Usage:

```c
listRemoveElement(&list, element, compareFunction);
```

* Removes the first occurrence of a specified element from the ArrayList.
* `element`: A pointer to the element to be removed.
* `compareFunction`: A function to compare elements for equality.

### Removing Elements within a Range

```c
void listRemoveRange(ArrayList **listPtr, const size_t start, const size_t end)
```

Usage:

```c
listRemoveRange(&list, start, end);
```

* Removes elements from the ArrayList within the specified range, starting from the start index (inclusive) up to, but not including, the end index (exclusive).
* `start`: The index of the first element to be removed (inclusive).
* `end`: The index of the element immediately after the last element to be removed (exclusive).

### Removing All Elements that Satisfy a Condition

```c
void listRemoveIf(ArrayList **listPtr, CheckFunction check)
```

Usage:

```c
listRemoveIf(&list, checkFunction);
```

* Removes all elements that satisfy a conditional in the specified function.
* `checkFunction`: A function that returns the result of a checked conditional.

### Removing All Matching Elements in Another ArrayList

```c
void listRemoveAll(ArrayList **listPtr, const ArrayList *toRemove, EqualityFunction compare)
```

Usage:

```c
listRemoveAll(&list, toRemove, compareFunction);
```

* Removes all occurrences of elements from another ArrayList (`toRemove`) from the current ArrayList based on a specified comparison function.
* `toRemove`: A pointer to the ArrayList containing the elements to be removed.
* `compareFunction`: A function used to compare elements for equality.

### Clearing the ArrayList

```c
void listClear(ArrayList **listPtr)
```

Usage:

```c
listClear(&list);
```

* Removes all elements from the ArrayList, making it empty.

### Sorting the ArrayList

```c
void listSort(ArrayList **listPtr, CompareFunction compare)
```

Usage:

```c
listSort(&list, comparisonFunction);
```

* Sorts the elements in the ArrayList using the provided comparison function.
* `comparisonFunction`: A comparison function that defines the sorting order.

## Querying the ArrayList

### Retrieving Data at a Specified Index

```c
void *listGet(const ArrayList *list, const size_t index)
```

Usage:

```c
void *element = listGet(list, index);
```

* Retrieves the data stored at the specified index in the ArrayList.
* `list`: A pointer to the ArrayList from which you want to retrieve data.
* `index`: The index of the element you want to retrieve.

### Getting the Size

```c
size_t listSize(const ArrayList *list)
```

Usage:

```c
size_t size = listSize(list);
```

* Returns the current number of elements in the ArrayList.

### Checking if the ArrayList is Empty

```c
bool listIsEmpty(const ArrayList *list)
```

Usage:

```c
bool isEmpty = listIsEmpty(list);
```

* Returns true if the ArrayList is empty; otherwise, returns false.

### Checking if an Element Exists

```c
bool listContains(const ArrayList *list, const void *toFind, EqualityFunction compare)
```

Usage:

```c
bool exists = listContains(list, element, compareFunction);
```

* Returns true if the specified element exists in the ArrayList; otherwise, returns false.
* `element`: A pointer to the element to check for existence.
* `compareFunction`: A function to compare elements for equality.

### Finding the Index of an Element

```c
int listIndexOf(const ArrayList *list, const void *toFind, EqualityFunction compare)
```

Usage:

```c
int index = listIndexOf(list, element, compareFunction);
```

* Returns the index of the first occurrence of the specified element in the ArrayList.
* Returns -1 if the element is not found.
* `element`: A pointer to the element to find.
* `compareFunction`: A function to compare elements for equality.

### Finding the Last Index of an Element

```c
int listLastIndexOf(const ArrayList *list, const void *toFind, EqualityFunction compare)
```

Usage:

```c
int lastIndex = listLastIndexOf(list, element, compareFunction);
```

* Returns the index of the last occurrence of the specified element in the ArrayList.
* Returns -1 if the element is not found.
* `element`: A pointer to the element to find.
* `compareFunction`: A function to compare elements for equality.

## Memory Management

### Freeing the ArrayList

```c
void freeList(ArrayList **listPtr)
```

Usage:

```c
freeList(&list);
```

* Frees the memory associated with the ArrayList.
* This should be called when you are done using the ArrayList to prevent memory leaks.

## Customization

### Changing the Initial Capacity

* You can modify the INITIAL_CAPACITY macro in the source code to set the initial capacity of the ArrayList according to your requirements.

## Error Handling

### Memory Allocation Check

* The library includes error checking for memory allocation failures. If memory allocation fails, an error message is printed to `stderr`, and the program exits.

## Important Notes

* This library uses a generic approach to handle elements of any data type. However, you need to ensure that your elements are appropriately handled and compared using suitable functions.

## Example Usage

```c
#include <stdio.h>
#include <stdbool.h>
#include <arraylist.h> //Include the ArrayList header file

// Function to compare two ints for equality
bool compareFunction(const void *a, const void *b)
{
    int *valueA = (int *)a;
    int *valueB = (int *)b;

    return *valueA == *valueB; 
}

// Function to compare two ints for sorting (ascending order)
int sortFunction(const void *a, const void *b)
{
    int *valueA = (int *)a;
    int *valueB = (int *)b;

    return *valueA - *valueB; 
}

int main() 
{
    // Create two ArrayLists
    ArrayList *list1 = createList();
    ArrayList *list2 = createList();

    // Populate list1 with integer values
    int value1 = 42;
    int value2 = 7;
    int value3 = 15;
    listAdd(&list1, &value1);
    listAdd(&list1, &value2);
    listAdd(&list1, &value3);

    // Populate list2 with more integer values
    int value4 = 7;
    int value5 = 30;
    listAdd(&list2, &value4);
    listAdd(&list2, &value5);

    // Clone list1
    ArrayList *list3 = listClone(list1);

    // Print the size of list1
    printf("Size of list1: %zu\n", listSize(list1)); // Output: Size of list1: 3

    // Insert an element into list1 at index 1
    int newValue = 99;
    listInsert(&list1, &newValue, 1);

    // Check if an element exists in list1
    int elementToFind = 15;
    bool exists = listContains(list1, &elementToFind, compareFunction);
    printf("Element %d exists in list1: %s\n", elementToFind, exists ? "true" : "false"); // Output: Element 15 exists in list1: true

    // Find the index of an element in list1
    int indexToFind = 7;
    int foundIndex = listIndexOf(list1, &indexToFind, compareFunction);
    printf("Index of element %d in list1: %d\n", indexToFind, foundIndex); // Output: Index of element 7 in list1: 2

    // Remove all occurrences of an element from list1 using list2
    listRemoveAll(&list1, list2, compareFunction);

    // Sort list3 in ascending order
    listSort(&list3, sortFunction);

    // Print the contents of list3 after sorting
    printf("Sorted list3: ");
    for (int i = 0; i < listSize(list3); i++) 
    {
        int *element = (int *)listGet(list3, i);
        printf("%d ", *element);
    }
    printf("\n"); // Output: Sorted list3: 7 15 42

    // Free memory for all ArrayLists
    freeList(&list1);
    freeList(&list2);
    freeList(&list3);

    return 0;
}
```

# Compilation Guide

This guide provides instructions on how to compile and build the project. The project consists of source code located in the `src` directory, header files in the `include` directory, and a main source file named `main.c`. Compilation is managed using a Makefile that uses the GCC compiler.

## Prerequisites

Before you can compile, ensure that you have the following prerequisites installed on your system:

* GCC (GNU Compiler Collection)
* Standard C Library (libc) development files (usually provided by the libc-dev package on Linux systems)
* (Optional) Make (Build automation tool)

## Compilation Steps With Make

Follow these steps to compile:

1. **Clone the Repository:** If you haven't already, clone the "Generic_C_ArrayList" repository to your local machine:

   ```bash
   git clone https://github.com/KhiemNguyen15/Generic_C_ArrayList.git
   ```

2. **Navigate to the Project Directory:** Change your current directory to the project root.

3. **Compile the Program:** Run the `make` command to compile the program. The Makefile will automatically locate source files in the `src` directory, include header files from the `include` directory, and produce an executable named `arraylistrunner` (which can be changed in the Makefile):

    ```bash
    make
    ```

    If you encounter any errors during compilation, make sure you have met the prerequisites and resolved any issues.

4. **Clean Up (Optional):** To clean the build directory and remove compiled files and executables, you can use the following command:

    ```bash
    make clean
    ```

    This will delete all generated object files and the executable.

## Compilation Steps Without Make

Follow these steps to compile:

1. **Clone the Repository:** If you haven't already, clone the "Generic_C_ArrayList" repository to your local machine:

   ```bash
   git clone https://github.com/KhiemNguyen15/Generic_C_ArrayList.git
   ```

2. **Navigate to the Project Directory:** Change your current directory to the project root.

3. **Compile the Program:** Use the following `gcc` command to compile:

    ```bash
    gcc -I./include -o arraylistrunner main.c src/arraylist.c src/data.c
    ```

    Replace `arraylistrunner` with the desired executable name if you wish to do so.
    If you encounter any errors during compilation, make sure you have met the prerequisites and resolved any issues.
