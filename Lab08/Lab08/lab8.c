#include<stdio.h>
#include<string.h>
#define maxname 21
#define maxpairs 10
#define maxinput 101

int parse_line(char *line,int values[maxpairs],char labels[maxpairs][maxname],int *count,double *number){
*count=0;
char buffer[maxinput];
strcpy(buffer,line);
char *token=strtok(buffer, " \t");
if(token == NULL) return 0;
char *second =strtok(NULL,  " \t");

if(second==NULL){
sscanf(token, "%lf",number);
return 1;
}

while(token !=NULL&&second!=NULL){
sscanf(token, "%d",&values[*count]);
strncpy(labels[*count], second, maxname-1);
labels[*count][maxname-1]= '\0';
(*count)++;
token=strtok(NULL, " \t");
second=strtok(NULL, " \t");
}
return 2;
}

double compute_cost(char object[]){
char buffer[maxinput];
int values[maxpairs];
char lable[maxpairs][maxname];
int count=0;
double total=0.0;
double number=0.0;
printf("\nDefine %s :",object);
fgets(buffer,maxinput,stdin);
int flage=parse_line(buffer,values,lable,&count,&number);
if (flage == 1){
total=number;
}
else{
for(int i=0;i<count;i++){
total +=values[i]*compute_cost(lable[i]);
}
}
return total;
}

int main(){
char object[maxname];
double total;
printf("Name the object:");
fgets(object,maxname,stdin);
int leng = strlen(object);
object[leng-1]='\0';
total=compute_cost(object);
printf("Total: %.2f\n", total);
}
