#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    char name[50];
    int rollNo;
    int marks;
};

struct Student students[MAX_STUDENTS];
int numStudents = 0;

void addStudent() {
    if (numStudents >= MAX_STUDENTS) {
        printf("Maximum number of students reached\n");
        return;
    }

    struct Student student;
    printf("Enter name: ");
    scanf("%s", student.name);
    printf("Enter roll number: ");
    scanf("%d", &student.rollNo);
    printf("Enter marks: ");
    scanf("%d", &student.marks);

    students[numStudents++] = student;
    printf("Student added successfully\n");
}

void displayStudent(int i) {
    printf("Name: %s\n", students[i].name);
    printf("Roll Number: %d\n", students[i].rollNo);
    printf("Marks: %d\n", students[i].marks);
}

void displayAllStudents() {
    if (numStudents == 0) {
        printf("No students added yet\n");
        return;
    }

    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i+1);
        displayStudent(i);
        printf("\n");
    }
}

void searchStudent() {
    if (numStudents == 0) {
        printf("No students added yet\n");
        return;
    }

    int rollNo;
    printf("Enter roll number to search: ");
    scanf("%d", &rollNo);

    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNo == rollNo) {
            printf("Student found:\n");
            displayStudent(i);
            return;
        }
    }

    printf("Student with roll number %d not found\n", rollNo);
}

void deleteStudent() {
    if (numStudents == 0) {
        printf("No students added yet\n");
        return;
    }

    int rollNo;
    printf("Enter roll number to delete: ");
    scanf("%d", &rollNo);

    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNo == rollNo) {
            for (int j = i; j < numStudents-1; j++) {
                students[j] = students[j+1];
            }
            numStudents--;
            printf("Student with roll number %d deleted successfully\n", rollNo);
            return;
        }
    }

    printf("Student with roll number %d not found\n", rollNo);
}

int main() 
{
    int choice;

    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayAllStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
