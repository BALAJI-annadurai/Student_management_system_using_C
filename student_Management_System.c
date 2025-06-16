#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll_no;
    char name[50];
    float marks;
};

void addStudent() {
    FILE *fp = fopen("students.dat", "ab");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    struct Student s;
    printf("Enter Roll No: ");
    scanf("%d", &s.roll_no);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);  // accepts spaces
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("Student added successfully!\n");
}

void viewStudents() {
    FILE *fp = fopen("students.dat", "rb");
    if (!fp) {
        printf("Error opening file or no records exist!\n");
        return;
    }

    struct Student s;
    printf("\n%-10s %-20s %-10s\n", "Roll No", "Name", "Marks");
    printf("------------------------------------------------\n");
    while (fread(&s, sizeof(s), 1, fp)) {
        printf("%-10d %-20s %-10.2f\n", s.roll_no, s.name, s.marks);
    }

    fclose(fp);
}

void searchStudent() {
    int roll, found = 0;
    struct Student s;
    FILE *fp = fopen("students.dat", "rb");

    if (!fp) {
        printf("No data available.\n");
        return;
    }

    printf("Enter Roll No to search: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll_no == roll) {
            printf("\nStudent Found:\n");
            printf("Roll No: %d\nName: %s\nMarks: %.2f\n", s.roll_no, s.name, s.marks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student with Roll No %d not found.\n", roll);

    fclose(fp);
}

void editStudent() {
    int roll, found = 0;
    struct Student s;
    FILE *fp = fopen("students.dat", "rb+");

    if (!fp) {
        printf("No data available.\n");
        return;
    }

    printf("Enter Roll No to edit: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll_no == roll) {
            printf("Current Name: %s\nCurrent Marks: %.2f\n", s.name, s.marks);
            printf("Enter new name: ");
            scanf(" %[^\n]", s.name);
            printf("Enter new marks: ");
            scanf("%f", &s.marks);

            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);
            found = 1;
            printf("Record updated successfully!\n");
            break;
        }
    }

    if (!found)
        printf("Student with Roll No %d not found.\n", roll);

    fclose(fp);
}

void deleteStudent() {
    int roll, found = 0;
    struct Student s;
    FILE *fp = fopen("students.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (!fp || !temp) {
        printf("Error opening files.\n");
        return;
    }

    printf("Enter Roll No to delete: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll_no == roll) {
            found = 1;
        } else {
            fwrite(&s, sizeof(s), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        printf("Record deleted successfully.\n");
    else
        printf("Student with Roll No %d not found.\n", roll);
}

int main() {
    int choice;

    do {
        printf("\n========== Student Management System ==========\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student\n");
        printf("4. Edit Student\n");
        printf("5. Delete Student\n");
        printf("0. Exit\n");
        printf("===============================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: editStudent(); break;
            case 5: deleteStudent(); break;
            case 0: printf("Exiting... Thank you!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
git add .git add .