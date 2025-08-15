#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define true 1
#define false 0

typedef struct Student{
    int ID;
    char name[100];
}Student;

typedef struct ListStd{
    Student *students;
    int count;
    int capacity;
}ListStd;

typedef ListStd *List;

List create(int capacity) {
    List list = (List)malloc(sizeof(ListStd));
    list->students = (Student*)malloc(capacity* sizeof(Student));
    if (list->students == NULL) {
        printf("Error\n");
    }
    list->count = 0;
    list->capacity = capacity;
    return list;
}

int Insert(List list, Student students, int p) {
    if (p > list->count || list->count > list->capacity){
        printf("Error\n");
        return false;
    }
    int current = list->count;
    while (p != current) {
        list->students[current] = list->students[current - 1];
        current--;
    }
    list->students[p] = students;
    list->count++;
    return true;
}

void Display(List List)  {
    for(int i = 0; i < List->count; i++){
        printf("ID: %-15dName: %-20s\n", List->students[i].ID, List->students[i].name);
    }
}

void del(List list, int p) {
    if (p > list->count) {
        return;
    }
    for (int i = p; i <= list->count - 1; i++) {
        list->students[i] = list->students[i+1]; 
    }
    list->count--;
}

void search(List List, int p) {
    printf("Sinh vien thu %d la:\n", p+1);
    printf("ID: %-15dname: %-20s\n", List->students[p].ID, List->students[p].name);
}

int main() {
    List List = create(100);

    Student e1, e2, e3;

    e1.ID = 01; strcpy(e1.name, "Tran Van Huy");
    e2.ID = 02; strcpy(e2.name, "Mai Van Hao");
    e3.ID = 03; strcpy(e3.name, "Nguyen Thai An");

    Insert(List, e1, 0);
    Insert(List, e2, 1);
    Insert(List, e3, 2);

    Display(List);

    del(List, 2);
    printf("Danh sach sau khi xoa:\n");
    Display(List);

    search(List, 0);

    return 0;
}