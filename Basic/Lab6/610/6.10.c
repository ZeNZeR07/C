#include <stdio.h>

struct Student {
    int student_id;
    int score;
    char grade;
};

void calculate_grade(struct Student *s_ptr);

void display_menu() {
    printf("\n--- STUDENT RECORD MENU ---\n");
    printf("1. Input/Update Student Data\n");
    printf("2. View Student Report\n");
    printf("3. Exit Program\n");
    printf("Enter choice: ");
}

int main() {
    struct Student record = {0, 0, 'U'};
    int choice = 0;

    while (choice != 3) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Student ID: ");
                scanf("%d", &record.student_id);
                printf("Enter Score (0-100): ");
                scanf("%d", &record.score);

                calculate_grade(&record);

                printf("Data updated. Grade calculated.\n");
                break;

            case 2:
                if (record.student_id == 0) {
                    printf("No student data has been entered yet (ID is 0).\n");
                } else {
                    printf("\n--- STUDENT REPORT ---\n");
                    printf("ID: %d\n", record.student_id);
                    printf("Score: %d\n", record.score);
                    printf("Grade: %c\n", record.grade);
                }
                break;

            case 3:
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void calculate_grade(struct Student *s_ptr) {
    if (s_ptr->score >= 80) {
        s_ptr->grade = 'A';
    } else if (s_ptr->score >= 70 && s_ptr->score <= 79) {
        s_ptr->grade = 'B';
    } else if (s_ptr->score >= 60 && s_ptr->score <= 69) {
        s_ptr->grade = 'C';
    } else if (s_ptr->score >= 50 && s_ptr->score <= 59) {
        s_ptr->grade = 'D';
    } else {
        s_ptr->grade = 'F';
    }
}