#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked.h"

int main() {
    // Creating Empty Linked List Of Students
    struct student *school = NULL;
    printf("Empty Linked List Of Students:\n");
    print_list(school);
    printf("\n");

    // Populating Linked List Of Students
    int i, q, n = 20;
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        char id[10];
        for (q = 0; q < 9; q++) id[q] = rand() % 10 + 48;
        int grade = rand() % 12 + 1;
        double gpa = (rand() % 1200) / 100.0 + 88;
        school = insert_front(school, id, grade, gpa);
    }
    printf("Populated Linked List Of Students:\n");
    print_list(school);
    printf("\n");

    // Removing One Person From Every Grade If Possible
    for (int i = 1; i <= 12; i++) {
        school = remove_node(school, i);
    }
    printf("Linked List Of Students With Some Removed:\n");
    print_list(school);
    printf("\n");

    // Freeing Linked List Of Students
    school = free_list(school);
    printf("Freed Linked List Of Students:\n");
    print_list(school);
    printf("\n");
}
