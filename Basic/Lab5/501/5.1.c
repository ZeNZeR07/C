#include <stdio.h>

int calculate_area(int length, int width){

    return length * width;

    
}

int main() {
    int input_lenth;
    int input_width;
    int result_area;


    printf("Enter rectangle length (integer): ");
    scanf("%d", &input_lenth);

    printf("Enter rectangle width (integer): ");
    scanf("%d", &input_width);


    result_area = calculate_area(input_lenth, input_width);


    printf("\n--- RECTANGLE AREA REPORT ---\n");
    printf("Length: %d\n", input_lenth);
    printf("Width: %d\n", input_width);
    printf("Calculated Area: %d\n", result_area);


    return 0;



}