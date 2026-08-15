/*
 * CSE107 / C Programming - Lab 4
 * Topic: Pointers + Functions + Input Validation + Nested Loops
 *
 * Students implement:
 * 1) Input validation in main (ask until 0..86399).
 * 2) convertTime (returns h, m, s via pointers).
 * 3) split2Digits (returns tens/ones via pointers).
 * 4) In printTime3x3(): the three split2Digits calls (must pass addresses).
 * 5) digitCell(): complete the missing cases for digits 4, 6 and 9.
 *
 * Provided:
 * - digitCell() examples for 0, 1, 8
 * - printDigitRow() helper
 * - printing layout in printTime3x3()
 *
 * Rules:
 * - Use pointers to return multiple values from functions.
 * - Use loops and conditions.
 */
 
#include <stdio.h>
 
void convertTime(int totalSec, int *hour, int *min, int *sec);
void split2Digits(int value, int *tens, int *ones);
 
char digitCell(int digit, int row, int col);          /* partially provided */
void printDigitRow(int digit, int row);               /* provided helper */
void printTime3x3(int hour, int min, int sec);               /* partially TODO */
 
/* ========================= MAIN ========================= */
int main(void) {
    int totalSeconds;
    
    /* TODO-1: Read totalSeconds from user.
       - It must be in the range [0, 86399].
       - If invalid, keep asking until a valid value is entered.
       NOTE:
         You may assume the input is an integer (no need to handle letters).
    */
    printf("Enter the total seconds (from 0 to 86399)");
    scanf("%d",&totalSeconds);
    while(totalSeconds<0 || totalSeconds>86399){
     printf("invalid input pls enter a value between 0 and 86399 \n");
     printf("Enter the total seconds (from 0 to 86399)");
     scanf("%d",&totalSeconds);
    }
    
 
 
    /* TODO-2: Convert totalSeconds to hour, min, sec using pointers. */
    /* Step 1: Declare integer variables hour, min, and sec. */
    /* Step 2: Call convertTime */  
    int hour,min,sec;
    convertTime(totalSeconds,&hour,&min,&sec);
    
 
    /* TODO-3: Print the time in 3x3 ASCII digits (HHMMSS) */
    /* Call printTime3x3  */
    printTime3x3(hour,min,sec);
    
 
    return 0;
}
 
/* =================== STUDENTS IMPLEMENT =================== */
 
/* Converts total seconds to hours, minutes, seconds using pointers */
void convertTime(int totalSec, int *hour, int *min, int *sec) {
    /* TODO-4:
       1. Calculate the number of hours from totalSec.
       2. Find the remaining seconds after extracting hours.
       3. Calculate the number of minutes from the remaining seconds.
       4. Store the leftover seconds as the final seconds value.
       5. Save all results through the pointer parameters h, m, and s.
    */
*hour=totalSec/3600;
int remaining = totalSec % 3600;
*min=remaining /60;
*sec=remaining %60;
}
 
 
 
/* Splits a number (0..99) into tens and ones using pointers */


/* Splits a number (0..99) into tens and ones using pointers */
void split2Digits(int value, int *tens, int *ones) {
    /* Calculate the tens digit */
    *tens = value / 10;
 
    /* Calculate the ones digit */
    *ones = value % 10;
}
 
/* =================== PROVIDED / PARTIAL =================== */
 
/* Returns the character at (row, col) of a 3x3 digit.
   row: 0..2, col: 0..2, digit: 0..9
   Use only ' ', '_' and '|'
*/
char digitCell(int digit, int row, int col) {
    switch (digit) {
        case 0:
            if (row == 0 && col == 1) return '_';
            if (row == 1 && (col == 0 || col == 2)) return '|';
            if (row == 2 && (col == 0 || col == 2)) return '|';
            if (row == 2 && col == 1) return '_';
            return ' ';
 
        case 1:
            if ((row == 1 || row == 2) && col == 2) return '|';
            return ' ';
 
        case 2:
            if (row == 0 && col == 1) return '_';
            if (row == 1 && col == 2) return '|';
            if (row == 1 && col == 1) return '_';
            if (row == 2 && col == 0) return '|';
            if (row == 2 && col == 1) return '_';
            return ' ';
 
        case 3:
            if (row == 0 && col == 1) return '_';
            if (row == 1 && col == 2) return '|';
            if (row == 1 && col == 1) return '_';
            if (row == 2 && col == 2) return '|';
            if (row == 2 && col == 1) return '_';
            return ' ';
 
        /* TODO-6: Students implement digit 4 */
        case 4:
            /* TODO */
            if (row == 1 && col == 0) return '|';
            if (row == 1 && col == 1) return '_';
            if (row == 1 && col == 2) return '|';
            if (row == 2 && col == 2) return '|';
 
            return ' ';
 
        case 5:
            if (row == 0 && col == 1) return '_';
            if (row == 1 && col == 0) return '|';
            if (row == 1 && col == 1) return '_';
            if (row == 2 && col == 2) return '|';
            if (row == 2 && col == 1) return '_';
            return ' ';
 
        /* TODO-7: Students implement digit 6 */
        case 6:
            /* TODO */
            if (row == 0 && col == 1) return '_';
            if (row == 1 && col == 0) return '|';
            if (row == 1 && col == 1) return '_';
            if (row == 2 && col == 0) return '|';
            if (row == 2 && col == 1) return '_';
            if (row == 2 && col == 2) return '|';
 
            return ' ';
 
        case 7:
            if (row == 0 && col == 1) return '_';
            if ((row == 1 || row == 2) && col == 2) return '|';
            return ' ';
 
        case 8:
            if (row == 0 && col == 1) return '_';
            if (row == 1 && (col == 0 || col == 2)) return '|';
            if (row == 1 && col == 1) return '_';
            if (row == 2 && (col == 0 || col == 2)) return '|';
            if (row == 2 && col == 1) return '_';
            return ' ';
 
        /* TODO-8: Students implement digit 9 */
        case 9:
            /* TODO */
            if (row == 0 && col == 1) return '_';
            if (row == 1 && (col == 0 || col == 2)) return '|';
            if (row == 1 && col == 1) return '_';
            if (row == 2 && col == 2) return '|';
            if (row == 2 && col == 1) return '_';
            return ' ';
 
        default:
            return ' ';
    }
}
 
/* Prints a single digit row (row = 0..2) as 3 characters */
void printDigitRow(int digit, int row) {
    /* provided helper: prints one row of a digit using a loop */
    for (int col = 0; col < 3; col++) {
        putchar(digitCell(digit, row, col));
    }
}
 
/* Prints HHMMSS as 3x3 ASCII digits (side-by-side).
   Students must fill only the split2Digits calls (3 lines).
*/
void printTime3x3(int hour, int min, int sec) {
    int ht, ho, mt, mo, st, so;
    /*
    ht -> Stores the tens digit of the hour (the first digit in HH)
    ho -> Stores the ones digit of the hour (the second digit in HH)
 
    mt -> Stores the tens digit of the minute (the first digit in MM)
    mo -> Stores the ones digit of the minute (the second digit in MM)
 
    st -> Stores the tens digit of the second (the first digit in SS)
    so -> Stores the ones digit of the second (the second digit in SS)
    */
 
    /* TODO-9:
       Split h into its tens and ones digits and store them in ht and ho.
       Split m into its tens and ones digits and store them in mt and mo.
       Split s into its tens and ones digits and store them in st and so.
       You must call split2Digits exactly three times.
    */
 
    split2Digits(hour, &ht, &ho);
 
    split2Digits(min, &mt, &mo);
 
    split2Digits(sec, &st, &so);
 
 
 
    /* PROVIDED PRINTING LOGIC (do not change) */
    for (int row = 0; row < 3; row++) {
        printDigitRow(ht, row); putchar(' ');
        printDigitRow(ho, row); putchar(' ');
        putchar(' '); /* extra space between HH and MM */
        printDigitRow(mt, row); putchar(' ');
        printDigitRow(mo, row); putchar(' ');
        putchar(' '); /* extra space between MM and SS */
        printDigitRow(st, row); putchar(' ');
        printDigitRow(so, row);
        putchar('\n');
    }
    putchar('\n');
}
