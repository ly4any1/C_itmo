#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct listnode
{
struct listnode*prior;
struct listnode*next;
char data[30];
} NODE;
NODE*np;
NODE*insert(NODE*,char*);
int main()
{
    char name[30];
    NODE*root;
    NODE*newnode;
    root=(NODE*)malloc(sizeof(NODE));
    root->prior=root->next=root;
    root->data[0]='\0';
    for(;;)
    {
        gets(name);
        if(strcmp(name,"end")==0)
            break;
        insert (root,name);
    }
    for(np=root->next;np!=root;np=np->next)
    {
        printf("name=%s\n",np->data);
    }
    return 0;
}
NODE* insert(NODE*node,char*name)
{
NODE*np;
NODE*newnode;
for (np = node->next; (np!=node)&&strcmp(name,np->data)>0;np=np->next);
newnode = (NODE*)malloc(sizeof(NODE));
strncpy(newnode->data, name, 30);
newnode->next = np;
newnode->prior = np->prior;
(newnode->prior)->next = newnode;
np->prior=newnode;
return newnode;
}