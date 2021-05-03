#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../c/driver.h"


// Structure of the node

Node * getNode(char *name)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->webpage,name);
    new_node->next = new_node->prev = new_node;
    return new_node;
}

Node * insert(Node* start)
{
    char name[32];
    printf("Enter the name of web-page:");
    scanf("%s",name);
    Node* new_node = getNode(name);
    if(!new_node)
    {
        printf("\n OUT OF MEMORY");
        exit(0);
    }
    if (start == NULL)
    {
        start = new_node;
        return start;
    }
    Node *last = (start)->prev;
    new_node->next = start;
    new_node->prev = last;
    (start)->prev = new_node;
    last->next = new_node;
    return start;
}
Node * delete(Node* start)
{
    Node *temp=start;
    Node *prev1=NULL;
    char name[32];
    printf("Enter the web-page to be removed:");
    scanf("%s",name);
    while (strcmp(name,temp->webpage)!=0)
    {
        // If node is not present in the list
        if (temp->next == start) {
            printf("\nNot found");
            return start;
        }
        prev1= temp;
        temp=temp->next;
    }

    // Check if node is the only node in list
    if (temp->next == start && prev1 == NULL) {
      printf("\nDeletion of HOME page not allowed");
    }

    // If list has more than one node,
    // check if it is the last node
    else if(temp->next == start) {
        // Adjust the pointers of prev_1 and start node
        prev1->next = start;
        (start)->prev = prev1;
        free(temp);
        printf("Deletion successful");
    }
    else {
        // create new pointer, points to next of curr node
        Node *temp1 = temp->next;
        prev1->next = temp1;
        temp1->prev = prev1;
        free(temp);
        printf("Deletion successful");
    }
    return start;
}

void intro()
{
    printf("\n\t\t\t\tDATA STRUCTURES PROJECT SEMESTER-3\n");
    printf("PROJECT TITLE: Implementation of web browser navigation");
}
void search(Node *start)
{
    char key[400]="START ";
    char name[32];
    Node *temp=start;
    int found=0,flag;
    printf("Enter the web-page name:");
    scanf("%s",name);
    if(strcmp(name,"home.html")==0)
       {
        flag=system("START home.html");
        found=1;
       }
    temp=temp->next;
    while(temp!=start)
    {
        if(strcmp(temp->webpage,name)==0)
        {
            strcat(key,temp->webpage);
            flag=system(key);
            if(flag==-1)
                ;
            strcpy(key,"START ");
            found=1;
            break;
        }
        temp=temp->next;
    }
    if(found==0)
        printf("\nPAGE NOT FOUND\n");
}

void display(Node* start)
{
    Node *temp = start;
    char key[400]="START ";
    int op,flag;
    flag=system("START home.html");
    if(flag!=-1)
    printf("\nHOME-PAGE Displayed!");
    do
    {
    printf("\n\nEnter your option:\n1.Previous page\n2.Next page\n3.Exit navigation\n4.HOME\nOption:");
    scanf("%d",&op);
    switch(op)
    {
        case 1:
            temp=temp->prev;
            strcat(key,temp->webpage);
            flag=system(key);
            if(flag!=-1)
                ;
            strcpy(key,"START ");
            break;
        case 2:
            temp=temp->next;
            strcat(key,temp->webpage);
            flag=system(key);
            if(flag!=-1)
                ;
            strcpy(key,"START ");
            break;
        case 4:
            flag=system("START home.html");
            if(flag!=-1)
                printf("\nHOME-PAGE Displayed!");
            break;
    }
    }while(op!=3);
}

void destroy(Node* n){
   if(!n)
    return;
   destroy(n->next);
   free(n);
   n = NULL;
   }
int main()
{
    Node *start=getNode("home.html");
    int ch;
    intro();
    do
    {
    ch=menu(&start);
    }while(ch!=55);
    printf("\n\t\tTHANK YOU");
    destroy(start);
}


