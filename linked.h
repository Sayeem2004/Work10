#ifndef LINKED

#define LINKED
struct student;
void print_list(struct student *school);
struct student *insert_front(struct student *next, char *id, int grade, double gpa);
struct student *free_list(struct student *school);
struct student *remove_node(struct student *front, int data);

#endif
