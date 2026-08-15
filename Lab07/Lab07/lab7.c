#include<stdio.h>
#include<string.h>
#define stud_num 100
#define letter 10
int fillarray(char name[][letter] , double gpa[]){
char tempname[30];
double tempgpa;
int counter=0;
printf("Enter student names and gpas\nType (END) as the student name to stop\n");
for(int i=0;i<stud_num;i++){
printf("\nEnter the name of the student:");
scanf("%s",tempname);
if (strcmp(tempname,"END")==0){
break;
}
printf("\n enter the gpa :");
scanf("%lf",&tempgpa);
gpa[i]=tempgpa;
strcpy(name[i],tempname);
counter++;
}
return counter;
}
void selec(char *pnames[],double gpa[],int counter){
for(int i=0;i<counter-1;i++){
int maxind=i;
for(int j=i+1; j<counter;j++){
if(gpa[j]>gpa[maxind]){
maxind=j;
}
}
double tempgpa=gpa[maxind];
gpa[maxind]=gpa[i];
gpa[i]=tempgpa;

char *temp=pnames[maxind];
pnames[maxind]=pnames[i];
pnames[i]=temp;
}
}

int main(){
char name[stud_num][letter];
double gpa[stud_num];
char *pnames[stud_num];
int counter=fillarray(name,gpa);
for (int i=0;i<counter;i++){
pnames[i]=name[i];
}
selec(pnames,gpa,counter);
printf("\nSorted student list :\n");
printf("%-15s   %-5s\n","Name","GPA");
printf("------------------------\n");
for(int m=0;m<counter;m++ ){
printf("%-15s   %-5.2lf \n",pnames[m],gpa[m]);
}
return 0;
}
