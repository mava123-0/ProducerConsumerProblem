#include <stdio.h>
#include <stdlib.h>
int x=0,full=0,empty=4,mutex=1;

int main(){
void producer();
void consumer();
int wait(int);
int signal(int);
int n;
while(1){
printf("Enter n: ");
scanf("%d",&n);
switch(n){
case 1:
if(mutex==1 && empty!=0)
producer();
else
printf("Full");
break;
case 2:
if(mutex==1 && full!=0)
consumer();
else
printf("empty");
break;
case 3:
exit(0);
break;
}
}
return 0;
}

int wait(int s){
return (--s);
}

int signal(int s){
return(++s);
}

void producer(){
mutex=wait(mutex);
full=signal(full);
empty=wait(empty);
x=signal(x);
printf("Added element: %d",x);
mutex=signal(mutex);
}

void consumer(){
mutex=wait(mutex);
empty=signal(empty);
full=wait(full);
printf("Removed element: %d",x);
x=wait(x);
mutex=signal(mutex);
}