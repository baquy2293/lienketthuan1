#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#define true 1
#define false 0
#define TIME_FAST 100
typedef struct
{
    char hoTen[100];
    int tuoi;
    float diemTB;
}SinhVien;
typedef struct node
{
    SinhVien data;
    struct node*next;
}node;
node* first = NULL;
SinhVien nhapdata()
{
    SinhVien sv;
    printf("nhap ho ten sinh vien\n");fflush(stdin);
    gets(sv.hoTen);
    printf("nhap tuoi \n");fflush(stdin);
    scanf("%d",&sv.tuoi);
    printf("nhap diem trung binh\n");fflush(stdin);
    scanf("%f",&sv.diemTB);
    return sv;

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
void sapXepTangDan()
{
    if (first==NULL)
        return;
    for (node* i=first; i->next!=NULL; i=i->next)
    {
        for (node* j=i->next; j!=NULL; j=j->next)
        {
            if (strcmp(i->data.hoTen,j->data.hoTen) > 0)
            {
                SinhVien tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
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
void hienthimotSinhvien(SinhVien sv)
{
    printf("%20s%20d%20.2f\n",sv.hoTen,sv.tuoi,sv.diemTB);
}
void hienThiDanhSach ()
{
    int stt=1;
    printf("\tDANH SACH THONG TIN SINH VIEN\n");
    printf("%5s%20s%20s%20s","STT","HO TEN","TUOI","DIEM TB\n");
    for (node* i=first; i!=NULL; i=i->next)
    {
        printf("%5d",stt);stt++;
        hienthimotSinhvien(i->data);
    }
    printf("\n");
}
node* timnodetheoten(char* tencantim)
{
    char tmptencantim[100];
    char tmpHoten[100];
    for(node* i =first;i!=NULL;i=i->next)
    {
        strcpy(tmpHoten,i->data.hoTen);
        strcpy(tmptencantim,tencantim);
        strupr(tmptencantim);
        strupr(tmpHoten);
        if(strcmp(tmpHoten,tmptencantim)==0)
            return i;
    }
    return NULL;
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
void suanode(node* pnode)
{
 pnode->data=nhapdata();
}
void inmenu()
{
    printf("\t\tMENU\n");
     printf("\t0. KET THUC\n");
    printf("\t1. TAO DANH SACH SINH VIEN\n");
    printf("\t2. HIEN THI DANH SACH\n");
    printf("\t3. CHEN THEM MOT SINH VIEN\n");
    printf("\t4. XOA MOT SINH VIEN\n");
    printf("\t5. SUA MOT SINH VIEN\n");
    printf("\t6. SAP SEP TANG DAN THEO A - B\n");
    printf("\ VUI LONG CHON: ");
}
void taodanhsachsinhvien()
{
    int dem =1;
    while(true)
    {
        printf("nhap thong tin sinh vien thu %d \n",dem++);
        themnodevaocuoi(taovanhapnode());
         printf("nhap y de tiep tuc ");
         fflush(stdin);
               char chon =getchar();
               if(chon!='y'&&chon!='Y')
                break;
    }
}

int main()
{

   while(true)
   {
    inmenu();
    int chon;
    printf("MOI BAN CHON YEU CAU\n");
    scanf("%d",&chon);
    fflush(stdin);
    system("cls");
       if(chon == 1)
       {
           xoatoanbodanhsach();
           printf("\tBAN DA CHON TAO DANH SACH SINH VIEN\n");
       taodanhsachsinhvien();
       }
       else if(2==chon)
       {

        hienThiDanhSach();

       }
       else if(3==chon)
       {
printf("BAN DA CHON CHEN MOT SINH VIEN\n");
printf("VUI LONG NHAP THONG TIN SINH VIEN MOI\n");
   themnodevaocuoi(taovanhapnode());

       }
       else if(4==chon)
       {
           printf("BAN DA CHON XOA MOT SINH VIEN\n");
       printf("vui long ban nhap ten muon xoa\n");
       char tencantim[100];fflush(stdin);
       gets(tencantim);
    node* qnode = timnodetheoten(tencantim);
    xoanode(qnode);
       }
       else if(5==chon)
       {

           printf("BAN DA CHON SUA MOT SINH VIEN\n");
       printf("vui long ban nhap ten muon sua\n");
       char tencantim[100];fflush(stdin);
       gets(tencantim);
    node* editnode = timnodetheoten(tencantim);
    suanode(editnode);
       }
       else if(0==chon)
       {
printf("\t\t\tBYTE !");
return 0;

       }
       else if(6==chon)
       {
  printf("\tBan da chon sap xep danh sach theo ten\n");
sapXepTangDan();
     printf("\tSap xep xong!!! Danh sach moi la\n");
  hienThiDanhSach();

       }else{
       printf("nhap cac so tu 0 den 7");
       }
printf("BAM PHIM BAT KI DE VAO MENU\n");
getch();
   }
}




























