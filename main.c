#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct student {
    char id[10];
    int grade;
    double gpa;
    struct student *next;
};

void print_list(struct student *school) {
    if (school == NULL) return;
    printf("Student %s: %02dth grade, gpa of %lf\n",school->id,school->grade,school->gpa);
    print_list(school->next);
    return;
}

struct student *insert_front(struct student *next, char *id, int grade, double gpa) {
    struct student *s = (struct student *) calloc(1, sizeof(struct student));
    strncpy((char *)&(s->id), id, sizeof(s->id)-1);
    s->grade = grade;
    s->gpa = gpa;
    s->next = next;
    return s;
}

struct student *free_list(struct student *school) {
    struct student *next = school->next;
    while (next != NULL) {
        free((void *) school);
        school = next;
        next = next->next;
    }
    return next;
}

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

    // Freeing Linked List Of Students
    school = free_list(school);
    printf("Freed Linked List Of Students:\n");
    print_list(school);
    printf("\n");
}
