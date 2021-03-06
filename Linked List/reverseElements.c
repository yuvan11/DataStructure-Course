#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
void Rdisplay(struct Node *temp)
{
    if( temp != NULL) 
    {
        printf("%d ",temp->data); 
        Rdisplay(temp->next); 
    }
}
void reverseElement(struct Node* first, int len) // T(n) = 8n + 7
{
    int arr[len],i=0; // 2 unit
    struct Node* temp = first; // 1 unit
    while(temp!=NULL) // n + 1 unit
    {
        arr[i] = temp->data; // n unit
        i++; // n unit
        temp = temp->next; // n unit
    }
    temp = first; // 1 unit
    i--; // 1 unit

    while(temp!=NULL) // n+1 unit
    {
        temp->data = arr[i]; // n unit
        temp=temp->next; // n unit
        i--; // n unit
    }

}
void create() 
{
    struct Node *First,*last; 
    First = (struct Node*)malloc(sizeof(struct Node)); 
    int x; 
    scanf("%d",&x); 
    First -> data = x;  
    int len = 1;
    last = First; 
    last -> next = NULL; 
    scanf("%d",&x); 
    while(x != -1) 
    {
        len++;
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));  
        temp->data = x; 
        last -> next = temp; 
        last = temp; 
        last -> next = NULL; 
        scanf("%d",&x); 
    }

    reverseElement(First,len);
    Rdisplay(First);


}
int main()
{
   create();
}