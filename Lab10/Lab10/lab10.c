/*
 * CSE108 - Lab #10
 * Structs and Unions
 *
 * Complete the missing parts marked with TODO.
 * Do not change the main function.
 */

#include <stdio.h>

/* TODO: Define music_t struct */
typedef struct {
double monthly_fee;
double extra_hours;
double extra_hour_fee;
double total_cost;
}music_t;


/* TODO: Define cloud_t struct */
typedef struct {
double base_fee;
double extra_gb;
double gb_fee;
double total_cost;
}cloud_t;


/* TODO: Define course_t struct */
typedef struct {
double monthly_fee;
double number_of_courses;
double course_fee;
double total_cost;
}course_t;

/* TODO: Define subscription_data_t union */
typedef union {
music_t music;
cloud_t cloud;
course_t course;
}subscription_data_t;

/* TODO: Define subscription_t struct */
typedef struct {
char type;
subscription_data_t data;
}subscription_t;

/* Function prototypes */
subscription_t get_subscription_info(void);
subscription_t compute_total_cost(subscription_t subscription);

int main(void)
{
    subscription_t one_subscription;

    printf("Digital Subscription Cost Computation Program\n");

    for (one_subscription = get_subscription_info();
         one_subscription.type != 'Q';
         one_subscription = get_subscription_info()) {

        one_subscription = compute_total_cost(one_subscription);
    }

    return 0;
}

subscription_t get_subscription_info(void)
{
    subscription_t subscription;
    char choice;

    printf("\nEnter subscription type ");
    printf("(M for music, C for cloud, O for online course, Q to quit): ");
    scanf(" %c", &choice);
    switch(choice){
    case 'M':
    subscription.type=choice;
    printf("\nEnter monthly fee :");
    scanf("%lf",&subscription.data.music.monthly_fee);
    printf("\nEnter extra listening hours :");
    scanf("%lf",&subscription.data.music.extra_hours);
    printf("\nEnter fee pre extra hour :");
    scanf("%lf",&subscription.data.music.extra_hour_fee);
    break;
    case 'C':
    subscription.type=choice;
    printf("\nEnter base fee :");
    scanf("%lf",&subscription.data.cloud.base_fee);
    printf("\nEnter extra storage in GB :");
    scanf("%lf",&subscription.data.cloud.extra_gb);
    printf("\nEnter fee pre extra GB :");
    scanf("%lf",&subscription.data.cloud.gb_fee);
    break;
    case 'O':
    subscription.type=choice;
    printf("\nEnter monthly fee :");
    scanf("%lf",&subscription.data.course.monthly_fee);
    printf("\nEnter number of additional paid courses :");
    scanf("%lf",&subscription.data.course.number_of_courses);
    printf("\nEnter fee pre additional courses :");
    scanf("%lf",&subscription.data.course.course_fee);
    break;
    default:
    subscription.type='Q';
    break;
    }
    return subscription;
}

subscription_t compute_total_cost(subscription_t subscription)
{
    switch(subscription.type){
    case 'M':
    subscription.data.music.total_cost=subscription.data.music.monthly_fee + subscription.data.music.extra_hours * subscription.data.music.extra_hour_fee;
    printf("\nTotal cost for music streaming :%.2lf",subscription.data.music.total_cost);
    break;
    case 'C':
    subscription.data.cloud.total_cost=subscription.data.cloud.base_fee + subscription.data.cloud.extra_gb * subscription.data.cloud.gb_fee;
    printf("\nTotal cost for cloud storage :%.2lf",subscription.data.cloud.total_cost);
    break;
    case 'O':
    subscription.data.course.total_cost=subscription.data.course.monthly_fee + subscription.data.course.number_of_courses * subscription.data.course.course_fee;
    printf("\nTotal cost for online course platform :%.2lf",subscription.data.course.total_cost);
    break;
    default:
    subscription.type='Q';
    break;
    }
    return subscription;
}
