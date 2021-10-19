#include <stdio.h>
#include <stdlib.h>
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
    struct student *temp = school;
    while (school != NULL) {
        school = school->next;
        free((void *) temp);
        temp = school;
    }
    return temp;
}

struct student *remove_node(struct student *front, int data) {
    struct student *temp1 = front;
    if (temp1 == NULL) return front;
    if (temp1->grade == data) {
        front = front->next;
        free((void *) temp1);
        return front;
    }
    struct student *temp2 = front->next;
    while (temp2 != NULL) {
        if (temp2->grade == data) {
            temp1->next = temp2->next;
            free((void *) temp2);
            return front;
        }
        temp2 = temp2->next;
        temp1 = temp1->next;
    }
    return front;
}
