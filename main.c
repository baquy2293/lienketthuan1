#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define true 1
#define false 0
#include <string.h>
#include<math.h>
#include<conio.h>
typedef struct
{
    char hoten[100];
    int tuoi;
    float diemtb;
} sinhvien;
sinhvien nhapdata()
{
    sinhvien sv;
    printf("nhap ho ten\n");
    fflush(stdin);
    gets(sv.hoten);
    printf("nhap tuoi\n");
    scanf("%d",&sv.tuoi);
    printf("nhap diem trung binh\n");
    scanf("%f",&sv.diemtb);
    return sv;
}
sinhvien* capphadong(int n)
{
    return (sinhvien*)malloc(n*sizeof(sinhvien));
}
sinhvien* nhapdanhsachsinhvienchuaxd(int *n)
{
    int stt=1;
    sinhvien* ds = NULL;
    while(true)
    {
        if(ds ==NULL)
            ds = capphadong(stt);
        else
            ds = (sinhvien*)realloc(ds,stt*sizeof(sinhvien));
        printf("nhap thong tin sinh vien thu %d\n",stt);
        ds[stt-1] = nhapdata();
        printf("\tnhap y de tiep tuc");
        fflush(stdin);
        char chon = getchar();
        if(chon!='y'&&chon!='Y')
            break;
        stt++;
    }
    *n = stt;
    return ds;
}
int timchisotheohoten(sinhvien* ds,int n,char* tencantim)
{
    for (int i=0; i<n; i++)
        if(strcmp(ds[i].hoten,tencantim)==0)
        {
            return i;
        }
    return -1;
}
sinhvien* chensinhvien(int* n,sinhvien ds[])
{
    if(ds ==NULL||*n ==0)
    {
        (*n) = 1;
        ds = capphadong(*n);
    }
    else
    {
        (*n)+=1;

        ds = (sinhvien*)realloc(ds,((*n))*sizeof(sinhvien));
    }
    ds[(*n)-1] = nhapdata();

    return ds;
}
sinhvien*  xoasinhvientheoten(sinhvien* ds,int* n,int chiso)
{
    int i;
//if(chiso<0||chiso>=n)
//    return ds;
// dich mang
    for ( i=chiso; i<(*n)-1; i++)
    {
        ds[i]= ds[i+1];
    }
    (*n)--;
    ds = (sinhvien*)realloc(ds,(*n)*sizeof(sinhvien));
    return ds;
}
sinhvien* suasinhvien(sinhvien ds[],int n,char *tencansua)
{
    int chiso = timchisotheohoten(ds,n,tencansua);
    if(chiso<0)return;
    printf("nhap lai thong tin cho sinh vien %s\n",tencansua);
    ds[chiso] = nhapdata();

}
void hienthithongtin(sinhvien sv)
{
    printf("%25s%20d%20f\n",sv.hoten,sv.tuoi,sv.diemtb);
}
void hienthidanhsach(sinhvien ds[],int n)
{
     system ("cls");
    printf("%5s%25s%20s%20s\n","STT","HO TEN","TUOI","DIEM TB");
    int stt =1;
    for (int i=0; i<n; i++)
    {
        printf("%5d",stt);
        hienthithongtin(ds[i]);
        stt+=1;
    }
}
void inmenu()
{
    printf("\t\tMENU\n");
    printf("\t1. TAO DANH SACH SINH VIEN\n");
    printf("\t2. HIEN THI DANH SACH\n");
    printf("\t3. CHEN THEM MOT SINH VIEN\n");
    printf("\t4. XOA MOT SINH VIEN\n");
    printf("\t5. SUA MOT SINH VIEN\n");
    printf("\t6. KET THUC\n");
    printf("\ VUI LONG CHON: ");
}
int main()
{
    int n;
    sinhvien* ds = NULL;
    n=0;
    while(true)
    {   system ("cls");
        inmenu();

        int chon;
        scanf("%d",&chon);
        switch(chon)
        {
        case 1:
        {
            if(ds != NULL)
                free(ds);
                printf("\t\t VUI LONG NHAP THONG TIN SINH VIEN\n");
           ds =  nhapdanhsachsinhvienchuaxd(&n);
            break;
        }
        case 2:
        {printf("DANH SACH SINH VIEN\n");
            hienthidanhsach(ds,n);break;
        }
        case 3:
        { printf("BAN DA CHON CHEN THEM MOT SINH VIEN\n");
        printf("NHAP THONG TIN BAN MUON CHEN\n");
            ds = chensinhvien(&n,ds);
            break;
        }
        case 4:
        { printf("BAN DA CHON XOA MOT SINH VIEN\n");
        printf("NHAP THONG TIN BAN MUON XOA\n");
        char tencanxoa[100];fflush(stdin);
        gets(tencanxoa);
        int chiso = timchisotheohoten(ds,n,tencanxoa);
            ds = xoasinhvientheoten(ds,&n,chiso);
            break;
        }
        case 5:
        {
            printf("BAN DA CHON SUA MOT SINH VIEN\n");
        printf("NHAP THONG TIN BAN MUON SUA\n");
         char tenthaythe[100];fflush(stdin);
        gets(tenthaythe);
        ds = suasinhvien(ds,n,tenthaythe);
        break;
        } case 6:
        {
            printf("\n\nBYTE!\n");
            ds = NULL;free(ds);
            return false;
        }
        default:
            printf("nhap tu 1 den 6\n");
    }
    printf("bam nut bat ki de va menu");
    getch();
}
}
