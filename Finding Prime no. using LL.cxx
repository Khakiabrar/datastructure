#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct node
{
    //struct node *prev;
    int num;
    struct node *nxt;
}*head;

void store(int value){
    struct node *var, *temp;
    var = (struct node *)malloc(sizeof(struct node));
    var->num = value;
    if(head==NULL){
        head = var;
        head->nxt = NULL;
    }else{
        temp = var;
        temp->nxt = head;
        head=temp;
    }
}

void accept(int value, int i){
    if(i<2){
        printf("Enter value: ");
        scanf("%d", &value);
        store(value);
        i++;
        accept(value,i);
    }
}

void prime(){
    int num,x,y;
    struct node *temp,*temp2,*var;
    temp = head;
    temp2 = temp->nxt;
    y = temp->num;
    x = temp2->num;
    primeloop(x,y);
}
int primeloop(int x,int y){
    int num;
    if ( x == 1 ) x++;
    if(x <= y){
        num = isPrime(x,2); // second input parameter added
        printf("%d",num);
        if(num == 0){
             printf("");
         }else{
             printf("%5d",x);
         }
        primeloop(x+1,y);
    }
}

int isPrime(int n, int i){
    if(n%i==0 && n!=2 && n!=i){
      return(0);
    } else {
       if (i < sqrt(n)) {
        return( isPrime(n,i+1) );
    } else
     return(1);
    }
}

void main(){
    int i,value;
    clrscr();
    i = 0;
    accept(value,i);
    prime();
    getch();
}

int primeloop(int x,int y){
    int num;
    if ( x == 1 ) x++;
    if(x <= y){
        num = isPrime(x,2); // second input parameter added
        if(num != 0){
            printf("%5d ",x);
        }
        primeloop(x+1,y);
    }
}
