/*
     !!! ÇYFT YÖNLÜ !!!
   Çift yönlü ba?ly listede ekleme , syralama ve silme i?lemlerini yapar.
   ***Listelerken sondan yazdyryyor.
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct list
{
        int d;
        struct list *sonra;
        struct list *once;
}liste;

liste *ilk,*son,*p,*r;

void ekle(int x);
void sil(int x);
void listele();

main()
{
      int secim,a;
      p=ilk=son=new liste;
      while(1==1)
      {
          system("cls");
          printf("\n\n\t\t1-EKLEME\n\t\t2-LISTELE\n\t\t3-SIL\n\t\t4-CIKIS\n\t\tSecim Yapiniz : ");
          scanf("%d",&secim);
          if(secim==1)
          {
               printf("\n\tSayi Giriniz : ");
               scanf("%d",&a);
               ekle(a);
          }
          else if(secim==2)
          { listele(); }
          else if(secim==3)
          {
               printf("\n\t\tSilinecek sayiyi giriniz : ");
               scanf("%d",&a);
               sil(a);
          }
          else if(secim==4)
          { break; }
          else
          { printf("DOGRU SECIM YAPINIZ..."); }
      }
      getch();
}

void ekle(int x)
{
     if(ilk==NULL)
     {
          ilk->d=x;
          ilk->once=NULL;
          ilk->sonra=NULL;
          ilk=son;
     }
     else
     {
          r=new liste;
          r->d=x;
          r->sonra=NULL;
          r->once=NULL;
          if((ilk->d) > (r->d))
          {
              r->sonra=p;
              p->once=r;
              ilk=r;
          }
          else
          {
              for(p=ilk;p->sonra!=NULL && (p->sonra->d) < (r->d);p=p->sonra);
              if(p->sonra==NULL)
              {
                   p->sonra=r;
                   r->once=p;
                   son=r;
              }
              else
              {
                   
                   r->sonra=p->sonra;
                   r->once=p;
                   p->sonra=r;
                   r->sonra->once=r;
                   
              }
          }
     }
}

void listele()
{
     printf("\n\t\tLISTEDEKI SAYILAR");
     for(p=son->once;p!=ilk;p=p->once)
     { printf("\n\t\t->%d",p->d); }
     printf("\n\t\t->%d",p->d);
     getch();
}

void sil(int x)
{
     char s='0';
     if(ilk->d==x)
     {
          ilk=ilk->sonra;
          ilk->once=NULL;
     }
     else
     {
          for(p=ilk;p!=son;p=p->sonra)
          {
               if(p->sonra->d==x)
               {
                    r=new liste;
                    r=p->sonra;
                    p->sonra=r->sonra;
                    r->sonra->once=p;
                    delete r;
                    s='1';
                    break;
               }
          }
     }
     if(s=='1')
     { printf("\n\t\t%d sayisi silindi...",x); }
     else
     { printf("\n\t\t%d sayisi bulunamadi...",x); }
     getch();
}
