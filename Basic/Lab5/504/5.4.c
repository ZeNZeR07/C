#include <stdio.h>

#define NUM_STUDENTS 3

struct Student {
    int id;
    int scores;

};

int find_max_score(struct Student students[], int size) {
    int i;
    int max_score = students[0].scores;
    int top_student_id = students[0].id;

    for(i = i; i < size; i++) {
        if(students[i].scores > max_score) {
            max_score = students[i].scores;
            top_student_id = students[i].id;
        }
    }
    return top_student_id;
}


int main(){
    struct Student students[NUM_STUDENTS];
    int top_student_id;
    int i;


    printf("Enter data for %d students:\n", NUM_STUDENTS);
    for (i = 0; i < NUM_STUDENTS; i++) {
        printf("Student %d ID: ", i + 1);
        printf("Enter ID: ");
        scanf("%d", &students[i].id);
        printf("Enter Scores: ");
        scanf("%d", &students[i].scores);
    }

    top_student_id = find_max_score(students, NUM_STUDENTS);

    printf("\n--- STUDENT SCORES REPORT ---\n");
    printf("ID     | Scores\n");
    printf("-------|-------\n");
    for (i = 0; i < NUM_STUDENTS; i++) {

        printf("%-7d| %d\n", students[i].id, students[i].scores);

    }
    printf("\nTOP PERFORMER ID: %d\n", top_student_id);

    return 0;

}
