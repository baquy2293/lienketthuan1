#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#define true 1
#define false 0
#define TIME_FAST 100
typedef struct node
{
    int data;
    struct node*next;
}node;
node* first = NULL;
int nhapdata()
{
    int n;scanf("%d",&n);
    return n;
}
node* capphatnode()
{
    return (node*)malloc(sizeof(node));
}
node* taovanhapnode()
{
    node* pnode = capphatnode();
    pnode->data = nhapdata();
    pnode->next = NULL;
    return pnode;
}
void themnodedautien(node* pnode)
{
    first = pnode;
    pnode->next=NULL;
}

void themnodevaodau(node* pnode)
{
    if(first==NULL)
    {
        themnodedautien(pnode);
    }else{
    pnode->next=first;
    first= pnode;
    }
}
node* timnodecuoicung()
{
  if (first==NULL)
        return NULL;
    node* i = first;
    while (i->next!=NULL)
        i = i->next;
    return i;
}
void themnodevaocuoi(node* pnode)
{
    if(first==NULL)
    {

        themnodedautien(pnode);
    }else{
    node* lastnode = timnodecuoicung();
    lastnode->next = pnode;
    pnode->next = NULL;
    }
}
void hienThiDanhSach ()
{
    for (node* i=first; i!=NULL; i=i->next)
    {
        printf("%d ",i->data);
    }
    printf("\n");
}
void themPnodesauQnode(node* pnode,node* qnode)
{
    if(qnode==NULL)
    {
        return;
    }else{
    pnode->next=qnode->next;
    qnode->next= pnode;
    }
}
void xoanode(node* pnode)
{
    if(first==NULL)
    {
        return NULL;
    }
    // la phan tu dau tien
    if(pnode==first)
    {
        first = pnode->next;
        free(pnode);
    }else
    // bat ki vi tri nao trong danh sach
    {
        // tim phan tu truoc node
        node* i =first;
        while(i->next!=pnode)
        {
            i=i->next;
        }
        i->next = pnode->next;
        free(pnode);
    }
}
void xoatoanbodanhsach()
{
 while (first!=NULL)
    {
        xoanode(first);
        first=first->next;
    }
}
int main()
{
      themnodevaocuoi(taovanhapnode());
     themnodevaocuoi(taovanhapnode());
      themnodevaocuoi(taovanhapnode());
       themnodevaocuoi(taovanhapnode());
       hienThiDanhSach();
  // tu them cac tac dung sau ham main
}
