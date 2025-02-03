#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Student {
    int rollno;
    char name[50];
    float marks;
};

// Function to add a student
void addStudent() {
    struct Student s;
    FILE *file = fopen("students.dat", "ab");

    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Roll No: ");
    scanf("%d", &s.rollno);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, file);
    fclose(file);
    printf("Student added successfully!\n");
}

// Function to display students
void displayStudents() {
    struct Student s;
    FILE *file = fopen("students.dat", "rb");

    if (!file) {
        printf("No records found!\n");
        return;
    }

    printf("\nRoll No\tName\tMarks\n");
    while (fread(&s, sizeof(s), 1, file)) {
        printf("%d\t%s\t%.2f\n", s.rollno, s.name, s.marks);
    }

    fclose(file);
}

// Main function
int main() {
    int choice;
    while (1) {
        printf("\n1. Add Student\n2. Display Students\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
