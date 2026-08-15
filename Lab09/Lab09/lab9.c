/*
 * CSE102 — Lab 9: Structs
 */

#define CODE_LEN 10     // Maximum length for a course code string
#define EXAM_LEN 20     // Maximum length for an exam name string
#define MAX_EXAMS 5     // Maximum number of exams per course
#define STUDENT_NAME_LEN 20     // Maximum length for a student's name
#define MAX_STUDENTS 100        // Maximum number of students
#define MAX_COURSES 10          // Maximum number of courses
 
#include <stdio.h>
#include <string.h>
 
/* Structs */
typedef struct {
    char code[CODE_LEN];                // Stores the course code (e.g., "CSE102")
    char exams[MAX_EXAMS][EXAM_LEN];    // Stores exam names for the course (e.g., "Midterm", "Final")
    double weights[MAX_EXAMS];          // Stores weights of each exam (e.g., 0.4, 0.6)
    int exam_count;                     // Number of exams defined for this course
} course_t;
 
typedef struct {
    double values[MAX_EXAMS];           // Stores a student's grades for each exam in a course
} grades_t;
 
typedef struct {
    char name[STUDENT_NAME_LEN];        // Stores the student's name
    grades_t grades[MAX_COURSES];       // Stores grades for all courses (one grades_t per course)
} student_t;
 
 
/* Prints a course's details */
void print_course(const course_t *course)
{
    // ========================    TODO 5    ========================      
    // 1) Print the course code and exam count of the course. Use the course variable given as parameter.
    // 2) Loop through all exams in course using exam_count.
    // 3) In each iteration, print the exam name of the course and its weight.
    // ==============================================================
    printf("\n******course:%s(%d exam(s))******",course->code,course->exam_count);
    for(int i=0;i< course->exam_count;i++){
    printf("\n Exam:%s|weight:%.2lf",course->exams[i],course->weights[i]);
    }

}
 

/* Calculates weighted average of all exams in a course */
double weighted_average_for_course(const student_t *student, int course_index, const course_t *courses)
{
    // ========================    TODO 4    ========================
    // 1) Define two double variable named weighted_sum and total_weight.
    // 2) Initialize weighted_sum and total_weight to 0.0.
    // 3) Loop through all exams in courses[course_index] using exam_count.
    // 4) Inside the loop, calculate weighted_sum and accumulate it.
    // 5) Inside the loop, calculate total_weight and accumulate it.
    // 6) Return weighted_sum / total_weight.
    // ==============================================================

    // NOTE: weighted_sum += grades * weights. Use student parameter to access grades' values. Use courses[course_index] to access weights.
    // NOTE: total_weight += weights. Use courses[course_index] to access weights.
    double total=0.0,sum=0.0;
    for(int i=0;i<courses->exam_count;i++){
    sum+=student->grades[course_index].values[i]*courses[course_index].weights[i];
    total+=courses[course_index].weights[i];
    }
    return (sum/total);
}


/*
 * Helper function
 * Returns the index of the first occurrence of the target string in the items array;
 * if the target is not found, returns -1.
 */
int index_of_string(const char *target, const char *items[], int item_count)
{
    for (int i = 0; i < item_count; i++) {
        if (strcmp(items[i], target) == 0) {
            return i;
        }
    }
    return -1;
}


/*
 * Helper function
 * Returns the index of the course with the given course_code in the courses array;
 * if no matching course is found, returns -1.
 */
int index_of_course_by_code(const course_t *courses, int course_count, const char *course_code)
{
    const char *course_codes[MAX_COURSES];
    for (int i = 0; i < course_count; i++) {
        course_codes[i] = courses[i].code;
    }
    return index_of_string(course_code, course_codes, course_count);
}
 

/*
 * Helper function
 * Returns the index of the exam with the given exam_name in the course's exams array;
 * if no matching exam is found, returns -1.
 */
int index_of_exam_by_name(const course_t *course, const char *exam_name)
{
    const char *exam_names[MAX_EXAMS];
    for (int i = 0; i < course->exam_count; i++) {
        exam_names[i] = course->exams[i];
    }
    return index_of_string(exam_name, exam_names, course->exam_count);
}
 
 
/* Gets course details from the user */
void get_course_details_from_user(course_t *course)
{
    // ========================    TODO 1    ========================
    // 1) Ask the user for the course code (it is a string) and store it appropriately using course variable.
    // 2) Ask the user for the number of exams (it is an integer) and store it appropriately using course variable.
    // 3) Loop through all exams in course using exam_count.
    // 4) Inside loop, for each exam, ask the user for the exam name and store it appropriately using course variable.
    // 5) Inside loop, for each exam, ask the user for the exam's weight and store it appropriately using course variable.
    // ==============================================================

    // NOTE: Inside the loop, just before calling each scanf function, you might need to use this line: fflush(stdout);
    
    printf("\nEnter the course code:");
    scanf("%s",course->code);
    printf("\nEnter the number of exams:");
    scanf("%d",&course->exam_count);
    for(int i=0;i<course->exam_count;i++){
    printf("\nEnter the name of exam %d:",i+1);
    fflush(stdout);
    scanf("%s",course->exams[i]);
    printf("\nEnter the weight of the exam %d:",i+1);
    fflush(stdout);
    scanf("%lf",&course->weights[i]);
    }
}
 

/* Gets student details from the user */
void get_student_details_from_user(student_t *student, const course_t *courses, int course_count)
{
    // ========================    TODO 2    ========================
    // 1) Ask the user for the student name and store it appropriately using student variable.
    // 2) Loop through all courses using course_count variable.
    // 3) Loop through all exams of each course.
    // 4) Ask the user for exam grades of the course and store it appropriately using student variable.
    // ==============================================================
    printf("\nEnter student name :");
    scanf("%s",student->name);
    for(int i=0;i<course_count;i++){
    printf("\nThe grades for lesson %s:",courses[i].code);
    for(int j=0;j<courses[i].exam_count;j++){
    printf("\nEnter the grade of the %s exam:",courses[i].exams[j]);
    scanf("%lf",&student->grades[i].values[j]);
    }
    printf("\n");
    }
}
 
 
/* List students above a threshold for a given course */
void list_students(student_t *students, int student_count, const char *course_code,
                    course_t *courses, int course_count, double grade_threshold)
{
    // ========================    TODO 3    ========================
    // 1) Find course_index for the given course_code. To do this, call index_of_course_by_code function and assign its return value to a variable.
    // 2) Loop through all students using student_count variable.
    // 3) For each student, compute the weighted average of their grades for the course whose index was found above. Call weighted_average_for_course function.  
    // 4) Print the student name if the return value of weighted_average_for_course function is greater than grade_threshold.
    // ==============================================================
    int course_ind=index_of_course_by_code(courses,course_count,course_code);
     for(int i=0;i<student_count;i++){
     double grade= weighted_average_for_course(&students[i],course_ind,courses);
     if(grade>grade_threshold){
     printf("\nname:%s\n",students[i].name);
     }
     }
}

 
int main(void)
{
    course_t courses[MAX_COURSES];
    int course_count = 0;
 
    /* Q1: Get course details from the user */
    printf("========== Q1: get_course_details_from_user ==========\n");
    printf("Enter the number of courses to be defined: ");
    scanf("%d", &course_count);

    for (int i = 0; i < course_count; i++) {
        get_course_details_from_user(&courses[i]);
    }
 
    /* Print each course details */
    printf("\n========== print_course ==========\n");
    for (int i = 0; i < course_count; i++) {
        print_course(&courses[i]);  
        printf("\n");
    }
 
    /* Q2: Get student details from the user */
    printf("\n========== Q2: get_student_details_from_user ==========\n");
    int student_count = 0;
    student_t students[MAX_STUDENTS];

    printf("Enter number of students: ");
    scanf("%d", &student_count);

    for (int s = 0; s < student_count; s++) {
        get_student_details_from_user(&students[s], courses, course_count);
    }
 
    /* Q3: List student names above threshold for "CSE102" course */
    printf("\n========== Q3: list_students (threshold %.1f) ==========\n", 50.0);
    if (course_count > 0) {
        list_students(students, student_count, "CSE102", courses, course_count, 50.0);
    }
 
    return 0;
}
 
