
#include <stdio.h>
#include <math.h>
 
typedef enum { simp=1, conv } menu_t;
typedef enum { polyn=1, cosine } func_t;
typedef enum { edge_detection=1, smoothing, sharpening } kernel_t;
typedef enum { success, invalid_bounds, not_positive, not_even } error_t;
 
double polynomial(double x);
double cosinefunc(double x);
double simpson(double f(double), double a, double b, int n, enum error_t *error);
void convolution(int arr[], int size, int kernel[3], int result[]);
 
int main() {
    enum menu_t choice;
    enum func_t funcchoice;
    enum kernel_t kernelchoice;
    enum error_t error;
 
    int arr1[10] = {1,3,2,5,4,7,6,9,8,10};
    int arr2[10] = {0};
 
    int sarr1[3] = {1,0,-1};
    int sarr2[3] = {1,2,1};
    int sarr3[3] = {-1,2,-1};
 
    double lowerb, upperb, finalresult;
    int numofintervals;
 
    printf("1- integral calc with Simpson's rule \n2- convolution filter for 1D array \nEnter your choice: ");
    scanf("%d", &choice);
 
    switch(choice) {
        case simp:
            printf("\nSelect function to integrate:\n1- f(x)= x^3 + 2x +1\n2- f(x)= cos(x)\nEnter function choice: ");
            scanf("%d", &funcchoice);
 
            printf("\nEnter lower bound a, upper bound b, and number of intervals n: ");
            scanf("%lf %lf %d", &lowerb, &upperb, &numofintervals);
 
            switch(funcchoice) {
                case polyn:
                    finalresult = simpson(polynomial, lowerb, upperb, numofintervals, &error);
                    break;
                case cosine:
                    finalresult = simpson(cosinefunc, lowerb, upperb, numofintervals, &error);
                    break;
                default:
                    printf("Invalid function choice\n");
                    return 0;
            }
 
            if(error == success) {
                printf("Success! Result = %lf\n", finalresult);
            } else if(error == invalid_bounds) {
                printf("Error: invalid bounds\n");
            } else if(error == not_even) {
                printf("Error: n must be even\n");
            } else {
                printf("Error: n must be positive\n");
            }
            break;
 
        case conv:
            printf("\nSelect kernel type\n1-Edge detection [1,0,-1]\n2-Smoothing [1,2,1]\n3-Sharpening [-1,2,-1]\nEnter kernel choice: ");
            scanf("%d", &kernelchoice);
 
            switch(kernelchoice) {
                case edge_detection:
                    convolution(arr1, 10, sarr1, arr2);
                    break;
                case smoothing:
                    convolution(arr1, 10, sarr2, arr2);
                    break;
                case sharpening:
                    convolution(arr1, 10, sarr3, arr2);
                    break;
                default:
                    printf("Invalid kernel choice\n");
                    return 0;
            }
 
            printf("\nThe result:\n");
            for(int i=0; i<10; i++) {
                printf("%d ", arr2[i]);
            }
            printf("\n");
            break;
 
        default:
            printf("Invalid choice\n");
    }
    return 0;
}
 
double polynomial(double x) { return x*x*x + 2*x + 1; }
double cosinefunc(double x) { return cos(x); }
 
double simpson(double f(double), double a, double b, int n, enum error_t *error) {
    if(a >= b) {
        *error = invalid_bounds;
        return 0;
    } else if(n <= 0) {
        *error = not_positive;
        return 0;
    } else if(n % 2 != 0) {
        *error = not_even;
        return 0;
    }
 
    *error = success;
    double h = (b - a) / n;
    double sum = f(a) + f(b);
 
    for(int i=1; i<n; i++) {
        double x = a + i*h;
        if(i % 2 == 0) sum += 2*f(x);
        else sum += 4*f(x);
    }
 
    return (h/3.0) * sum;
}
 
void convolution(int arr[], int size, int kernel[3], int result[]) {
    for(int i=0; i<size; i++) {
        result[i] = 0;
        for(int j=0; j<3; j++) {
            if(i+j < size) {
                result[i] += arr[i+j] * kernel[j];
            }
        }
    }
}

