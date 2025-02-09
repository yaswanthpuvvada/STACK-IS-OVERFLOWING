#include<stdio.h>
#include<stdlib.h>
struct node{
char data;
struct node *top;
};
typedef struct node* stack;
stack push(stack sp,char da){
    stack temp=sp,new;
    new=(stack )malloc(sizeof(stack));
    new->data = da;
    new->top = temp;
    temp=new;
    return temp;  
}
stack pop(stack sp){
        stack temp=sp,new;
sp=sp->top;
free(temp);
}
 void linkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->top; 
    }
}
int isempty(stack st) {
    if(st == NULL){
    return 1;}
    else{
        return 0;
    }
}
void checkbalance(stack k, char arr[]) {
    int i = 0;
    while (arr[i] != '\0') {
        if (arr[i] == '{') {
            k = push(k, arr[i]);
        }
        if (arr[i] == '}') {
            if (isempty(k)) {
                printf("imbalanced expression\n");
                exit(1);
            }
            k = pop(k);
        }
        i++;
    }

    if (isempty(k)) {
        printf("balanced expression\n");
    } else {
        printf("imbalanced expression\n");
    }
}

int main() {
    char ar[] = {'a', 'b', 'd', '{', '}', 'x', 'y'};
    stack s = NULL; // Initialize the stack to NULL
    checkbalance(s, ar);
    return 0; // Add a return statement for successful execution
}