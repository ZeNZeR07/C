#include <stdio.h>

#define SCORE_A 80
#define SCORE_B 70
#define SCORE_C 60
#define SCORE_D 50

struct Student {
    int student_id;
    int score;
    char grade;
};

void calculate_grade(struct Student *s_ptr);
void input_data(struct Student *s_ptr);
void view_report(struct Student *s_ptr);

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
        
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n');
            choice = 0;
        }

        switch (choice) {
            case 1:
                input_data(&record);
                break;

            case 2:
                view_report(&record);
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
    if (s_ptr->score >= SCORE_A) {
        s_ptr->grade = 'A';
    } else if (s_ptr->score >= SCORE_B) {
        s_ptr->grade = 'B';
    } else if (s_ptr->score >= SCORE_C) {
        s_ptr->grade = 'C';
    } else if (s_ptr->score >= SCORE_D) {
        s_ptr->grade = 'D';
    } else {
        s_ptr->grade = 'F';
    }
}

void input_data(struct Student *s_ptr) {
    printf("Enter Student ID: ");
    scanf("%d", &s_ptr->student_id);
    printf("Enter Score (0-100): ");
    scanf("%d", &s_ptr->score);

    calculate_grade(s_ptr);

    printf("Data updated. Grade calculated.\n");
}

void view_report(struct Student *s_ptr) {
    if (s_ptr->student_id == 0) {
        printf("No student data has been entered yet (ID is 0).\n");
    } else {
        printf("\n--- STUDENT REPORT ---\n");
        printf("ID: %d\n", s_ptr->student_id);
        printf("Score: %d\n", s_ptr->score);
        printf("Grade: %c\n", s_ptr->grade);
    }
}