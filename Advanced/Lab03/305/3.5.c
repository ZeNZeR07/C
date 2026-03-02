#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 20
#define STUDENTS_PER_ROOM 10

struct Student {
    char name[MAX_NAME_LENGTH];
    int age;
    char sex;
    float gpa;
};

typedef struct Student (*RoomArray)[STUDENTS_PER_ROOM];

RoomArray allocate_and_fill_rooms(int *num_rooms);
void print_student_info(RoomArray rooms, int num_rooms);
void input_single_student(struct Student *s, int student_num);

int main() {
    RoomArray classrooms;
    int room_count = 0;

    classrooms = allocate_and_fill_rooms(&room_count);

    if (classrooms == NULL) {
        return 1;
    }

    print_student_info(classrooms, room_count);

    free(classrooms);

    return 0;
}

RoomArray allocate_and_fill_rooms(int *num_rooms) {
    printf("Enter number of rooms: ");
    if (scanf("%d", num_rooms) != 1) {
        return NULL;
    }

    RoomArray rooms = malloc(*num_rooms * sizeof(struct Student[STUDENTS_PER_ROOM]));
    
    if (rooms == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    for (int roomIdx = 0; roomIdx < *num_rooms; roomIdx++) {
        printf("Room %d:\n", roomIdx + 1);
        for (int studentIdx = 0; studentIdx < STUDENTS_PER_ROOM; studentIdx++) {
            input_single_student(&rooms[roomIdx][studentIdx], studentIdx + 1);
        }
    }
    return rooms;
}

void input_single_student(struct Student *s, int student_num) {
    printf("Student %d (Name Age Sex GPA): ", student_num);
    scanf("%19s", s->name); 
    scanf("%d", &s->age);
    scanf(" %c", &s->sex);
    scanf("%f", &s->gpa);
}

void print_student_info(RoomArray rooms, int num_rooms) {
    for (int roomIdx = 0; roomIdx < num_rooms; roomIdx++) {
        printf("Room %d:\n", roomIdx + 1);
        for (int studentIdx = 0; studentIdx < STUDENTS_PER_ROOM; studentIdx++) {
            printf("Student %d: %s %d %c %.2f\n", 
                   studentIdx + 1, 
                   rooms[roomIdx][studentIdx].name, 
                   rooms[roomIdx][studentIdx].age, 
                   rooms[roomIdx][studentIdx].sex, 
                   rooms[roomIdx][studentIdx].gpa);
        }
    }
}   