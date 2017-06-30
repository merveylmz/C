#include <stdio.h>
#include <iostream>
#include<time.h>
#include <graphics.h>
using namespace std;
int a=290,b=160;  
int i,boy;   int score=0,r=10;
char tus;
char puan[100];
int yem=0;
int c,d;
int yedi=0;
int c1=0,d1=0;
int score1=0;
int KontrolYem(int d[], int aranan, int boy);
void dosyadanOku(char isim[], int score);
void joker(int *c, int *d, int yedi)
{
     if(yedi == 1)
     {
             setcolor(0);
             circle(*c,*d,r);             
             setfillstyle(0,0);
             fillellipse(*c,*d,r,r);
             
             
             setfillstyle(0,0);
             fillellipse(*c+20,*d,r,r);
             setcolor(0);
             circle(*c+20,*d,r);
             
             
             setcolor(0);
             line((*c+10),(*d-30),*c,(*d-10));
             line((*c+10),(*d-30),(*c+20),(*d-10));
             
             *c=0;
             *d=0;
     }
     else
     {
         setfillstyle(1,RED);
         fillellipse(*c,*d,r,r);
         setcolor(11);
         circle(*c,*d,r);
         
         setfillstyle(1,RED);
         fillellipse(*c+20,*d,r,r);
         setcolor(11);
         circle(*c+20,*d,r);
     
         setcolor(2);
         line((*c+10),(*d-30),*c,(*d-10));
         line((*c+10),(*d-30),(*c+20),(*d-10));
     }
     
}
int bitis(int score,int score1)
{
     char isim[10];
  char tus;
     
     setfillstyle(1,0);        
     bar(20,30,560,450);
     
     setcolor(12);
     setlinestyle(0,0,3);
     rectangle(119,89,461,391);
     
     setfillstyle(1,0); 
     bar(120,90,460,390);
     
     outtextxy(210,130,"KENDÝNÝ YEDÝN...");
     outtextxy(190,155,"OYUNU KAYBETTÝN");
     
     outtextxy(240,200,"PUANINIZ:");
     score=score+score1;
     sprintf(puan,"%d",score);
     outtextxy(270,220,puan);
     
     outtextxy(240,250,"Ýsim giriniz:");
     while( !kbhit() ); 
     i=0;                    
     tus=getch();
     isim[i]=tus;
     outtextxy(240,290,isim);
     while(tus != 13)
     {
            tus=getch();
            if(tus == 13) break;
            i++;
            isim[i]=tus;
            outtextxy(240,290,isim); 
     }
  dosyadanOku(isim,score);
     
     getchar();
     getch();
}
int YemNoktasi(int d[], int secim, int boy)
{
    int nokta;
    int aralik;
    if(secim == 0)        // x koordinatý için
    {
             aralik=24;
             nokta=rand()%aralik;
             nokta++;
             nokta=nokta*20;
             nokta=nokta+30;
    }
    else                   // y koordinatý içn
    {
        aralik=18;
        nokta=rand()%aralik;
        nokta++;
        nokta=nokta*20;
        nokta=nokta+40;
    }
    while( KontrolYem(d,nokta,boy) == 1)
    {
                          nokta=rand()%aralik;
                          nokta++;
                          nokta=nokta*20;
                          if(aralik == 24)  nokta=nokta+10;
                          else if(aralik == 18)  nokta=nokta+20;
    }
    return nokta;
}
int KontrolYem(int d[], int aranan, int boy)
{
    int buldu=0;
    
    for(int i=0 ; i<boy ; i++)
    {     
         if (d[i] == aranan)
         {        
                  buldu=1;
                  break;
         }
    }
    return buldu;
}
int yemyeme(int *a, int *b, int *c, int *d, int x[], int y[], int boy)   //yemin ve jokerin yeni koordinatlarý
{   
    score=score+100;  
    
    sprintf(puan,"%d",score);
    outtextxy(585,210,puan);
    
    yem++;
    
    if(yem % 2 == 0)   //jokerin koordinatlarý
    {
           *c=YemNoktasi(x,0,boy);  c1=*c;     
           *d=YemNoktasi(y,1,boy);   d1=*d;
           joker(&c1,&d1,0);
    }
    else if(yem % 2 == 1)  joker(&c1,&d1,1);
    
    *a=YemNoktasi(x,0,boy);   //yemin koordinatlarý
    *b=YemNoktasi(y,1,boy);
    
    i=rand()%13;
    i++;
    setcolor(i);
    setlinestyle(0,0,1);    
    
    if((*a == *c) && (*b == *d))  //yemin ve jokerin koordinatlarý aynýysa yeme yeniden deðer atýyor
    {
           *a=YemNoktasi(x,0,boy);
           *b=YemNoktasi(y,1,boy);
    }
    circle(*a,*b,10);     
}
void sag(int x[], int y[], int boy, int score)
{
     setcolor(BLACK);
     circle(x[0],y[0],r);
     
     for(i=0 ; i<boy ; i++)
     {
                       x[i]=x[i+1];
                       y[i]=y[i+1];
     }
     x[boy]=x[boy]+20;
     
     if(x[boy]==10 || x[boy]==570 || y[boy]==20 || y[boy]==460)   x[boy]=30;
                                                          
     setcolor(WHITE);
     circle(x[boy],y[boy],r); 
}
void sol(int x[], int y[], int boy, int score)
{
     setcolor(BLACK);
     circle(x[0],y[0],r);
     
     for(i=0 ; i<boy ; i++)
     {
                       x[i]=x[i+1];
                       y[i]=y[i+1];
     }
     x[boy]=x[boy]-20;
     
     if(x[boy]==10 || x[boy]==570 || y[boy]==20 || y[boy]==460)    x[boy]=550;
                                                          
     setcolor(WHITE);
     circle(x[boy],y[boy],r);
}
void asagi(int x[], int y[], int boy, int score)
{
     setcolor(BLACK);
     circle(x[0],y[0],r);
     
     for(i=0 ; i<boy ; i++)
     {
                       x[i]=x[i+1];
                       y[i]=y[i+1];
     }
     y[boy]=y[boy]+20;
     
     if(x[boy]==10 || x[boy]==570 || y[boy]==20 || y[boy]==460)    y[boy]=40;
                                                          
     setcolor(WHITE);
     circle(x[boy],y[boy],r); 
}
void yukari(int x[], int y[], int boy, int score)
{
     setcolor(BLACK);
     circle(x[0],y[0],r);
     
     for(i=0 ; i<boy ; i++)
     {
                       x[i]=x[i+1];
                       y[i]=y[i+1];
     }
     y[boy]=y[boy]-20;
     
     if(x[boy]==10 || x[boy]==570 || y[boy]==20 || y[boy]==460)   y[boy]=440;
                                                          
     setcolor(WHITE);
     circle(x[boy],y[boy],r);
}
void dosyadanOku(char isim[], int score)
{
     
     FILE *p,*q;
     char s[10];
     int puan;
     char p1[100];
     
     p=fopen("isimler.txt","r");
     q=fopen("siralama.txt","w");
     
     int yazdi=0;
     int okunan=0;
     int yazilan=0;
      
     fscanf(p,"%s\t%d\n",s,&puan);
     okunan++;
     while( !feof(p) )
     {
            if(score > puan  && yazdi==0)
            {
                     fprintf(q,"%s\t%d\n",isim,score);
                     yazdi=1;
                     yazilan++;
            }
            if(yazilan < 4)
            {
                       fprintf(q,"%s\t%d\n",s,puan);
                       yazilan++;
            }
            fscanf(p,"%s\t%d\n",s,&puan);
            okunan++;
     }
      
     if(score > puan  && yazdi == 0)
     {
              fprintf(q,"%s\t%d\n",isim,score);
              yazilan++;
     }
     if(yazilan < 3) fprintf(q,"%s\t%d\n",s,puan);
      
     fclose(p);
     fclose(q); 
     
     remove("isimler.txt");
     rename("siralama.txt","isimler.txt");
     
     setfillstyle(1,0);        
     bar(20,30,560,450);
     
     setcolor(12);
     setlinestyle(0,0,3);
     rectangle(119,89,461,391);
     
     setfillstyle(1,0); 
     bar(120,90,460,390);
     
     p=fopen("isimler.txt","r");
     
     outtextxy(195,150,"EN YÜKSEK PUANLAR:");
     for(i=0;i<3;i++)
     {
                     fscanf(p,"%s\t%d\n",s,&puan);
                     sprintf(p1,"%d",puan);
                     outtextxy(210,180+(i*20),s);
                     outtextxy(300,180+(i*20),p1);
                     
     }
     
     outtextxy(240,260,"PUANINIZ:");
     sprintf(p1,"%d",score);
     outtextxy(265,280,p1);  
     
     
}
int main( )
{
 initwindow( 650 , 490 , "WinBGIm" );
 
    srand(time(NULL));
 
 int x[100], y[100];
 int boy=4;
 int hiz;
 x[0]=50, y[0]=240;
    
    setcolor(11);
    setfillstyle(2,0); 
    bar(120,90,460,390);
     
    settextstyle(6,0,1);
    outtextxy(240,130,"YILAN OYUNU");
    settextstyle(10,0,1);
    outtextxy(240,165,"HOSGELDÝNÝZ.");
    settextstyle(8,0,1);
    outtextxy(125,200,"OYUNA BAÞLAMAK ÝÇÝN SEVÝYEYÝ SEÇÝNÝZ: ");
    settextstyle(8,0,1);
    setcolor(9);
    outtextxy(211,240,"YAVAÞ ÝÇÝN 1'E BASINIZ. ");
    outtextxy(211,260,"ORTA ÝÇÝN 2'E BASINIZ. ");
    outtextxy(211,280,"HIZLI ÝÇÝN 3'E BASINIZ. ");
    settextstyle(8,0,2);
    setcolor(10);
    outtextxy(165,315,"BASLAMAK ÝCÝN ENTER'A BASINIZ.");
    while( kbhit() );
     
    tus=getch();
     
    if (tus == '1')  hiz = 500;
    else if (tus == '2')  hiz = 200;
    else if (tus == '3')  hiz = 80;
    else hiz=200; 
    
    while(tus != 13)
    {
       tus=getch();
       if (tus == 13)
       {
          cleardevice();
          setcolor(9);                   //duvar
          setlinestyle(0,0,3);                      
          rectangle(18,28,562,452);
 
          setlinestyle(0,0,1);           //yem
          circle(a,b,10);  
    
          setcolor(9);                   //puanlama kýsmý
          settextstyle(3,0,2);
          outtextxy(575,190,"PUAN:");
    
          sprintf(puan,"%d",score);
          outtextxy(595,210,puan);
       
          setcolor(WHITE);             //yýlan
       circle(x[0],y[0],r);
       for(i=1 ; i<=boy ; i++)
          {
                       y[i]=240;
                       x[i]=x[i-1]+20;
                       setcolor(WHITE);
                       circle(x[i],y[i],r);         
          }
          while( 1 )
          {
            tus=getch();  
            if(tus == 27) exit(0);
            else
            {
                if(tus == 77)                 //saða hareket
                {
                          while( i )
                          {
                                  if(x[boy] == (a-20) && y[boy] == b)
                                  {
                                                    boy++;                 //yemi yerse büyüyor
                                                    setcolor(WHITE);    x[boy]=x[boy-1]+20;  y[boy]=y[boy-1];
                                                    circle(x[boy],y[boy],r);
                                                    delay(hiz);    
                                                    yemyeme(&a,&b,&c,&d,x,y,boy); 
                                  }
                                  if(x[boy] == (c-20) && y[boy] == d)  //joker yem yeme durumu
                                  {
                                                   yedi=1;
                                                   joker(&c, &d ,yedi);
                                                   score1=score1+500;
                                                   setcolor(9);
                                                   sprintf(puan,"%d",score1);
                                                   outtextxy(585,230,puan);
     
                                  }
                                  for(i=0 ; i<boy ; i++)
                                  {
                                            if(x[boy] == x[i] && y[boy] == y[i])  bitis(score,score1);
                                  }
                                  if( kbhit() )  break;
                                  sag(x,y,boy,score);   
                                  delay(hiz);
                          }
                }
                                        
                else if(tus == 75)                //sola hareket
                {
                     while( i )
                     {
                             if(x[boy] == (a+20) && y[boy] == b)
                             {
                                               boy++;                //yemi yerse büyüyor
                                               setcolor(WHITE);    x[boy]=x[boy-1]-20;  y[boy]=y[boy-1];
                                               circle(x[boy],y[boy],r);
                                               delay(hiz);
                                               yemyeme(&a,&b,&c,&d,x,y,boy); 
                             }
                             if(x[boy] == (c+40) && y[boy] == d)   //joker yem yeme durumu 
                                  {
                                                   yedi=1;
                                                   joker(&c, &d ,yedi);
                                                   score1=score1+500;
                                                   setcolor(9);
                                                   sprintf(puan,"%d",score1);
                                                   outtextxy(585,230,puan);
     
                                  }
                             for(i=0 ; i<boy ; i++)
                             {
                                               if(x[boy] ==x [i] && y[boy] == y[i])  bitis(score,score1);
                             }  
                             if( kbhit() ) break;
                             sol(x,y,boy,score);
                             delay(hiz);
                     }
                }
                       
                else if(tus == 80)              //aþaðý hareket 
                {
                     while( i )
                     {
                             if(x[boy] == a && y[boy] == (b-20))
                             {
                                          boy++;                  //yemi yerse büyüyor
                                          setcolor(WHITE);    x[boy]=x[boy-1];  y[boy]=y[boy-1]+20;
                                          circle(x[boy],y[boy],r);
                                          delay(hiz);    
                                          yemyeme(&a,&b,&c,&d,x,y,boy); 
                             }
                             
                             if((x[boy] == c && y[boy] == (d-20)) || (x[boy] == c+20 && y[boy] == (d-20)))
                             {
                                                   yedi=1;
                                                   joker(&c, &d ,yedi);
                                                   score1=score1+500;
                                                   setcolor(9);
                                                   sprintf(puan,"%d",score1);
                                                   outtextxy(585,230,puan);
     
                                         
                             }
                             for(i=0 ; i<boy ; i++)
                             {
                                               if(x[boy] == x[i] && y[boy] == y[i])  bitis(score,score1);
                             }
                             if( kbhit() ) break;
                             asagi(x,y,boy,score);
                             delay(hiz);
                     }
                }     
         
                else if(tus == 72)                 //yukarý hareket
                {
                     while( i )
                     {
                             if(x[boy] == a && y[boy] == (b+20))
                             {
                                          boy++;                  //yemi yerse büyüyor
                                          setcolor(WHITE);    x[boy]=x[boy-1];  y[boy]=y[boy-1]-20;
                                          circle(x[boy],y[boy],r);
                                          delay(hiz);    
                                          yemyeme(&a,&b,&c,&d,x,y,boy); 
                             }
                             if((x[boy] == c && y[boy] == (d+20)) || (x[boy] == c+20 && y[boy] == (d+20)))
                             {
                                                   yedi=1;
                                                   joker(&c, &d ,yedi);
                                                   //setcolor(WHITE);    
                                                   //circle(x[boy],y[boy],r);
                                                   score1=score1+500;
                                                   setcolor(9);
                                                   sprintf(puan,"%d",score1);
                                                   outtextxy(585,230,puan);
     
                                         
                             }
                             for(i=0 ; i<boy ; i++)
                             {
                                               if(x[boy] == x[i] && y[boy] == y[i])  bitis(score,score1);
                             }
                             if( kbhit() ) break;
                             yukari(x,y,boy,score);
                             delay(hiz); 
                     }
                }      
            }    
        }
        }
        }
    while( !kbhit() ); 
  
    closegraph( );
    
 return( 0 );
}

