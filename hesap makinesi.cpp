#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
main () {
	char islem;
	float a,b,sonuc;
    int kontrol;
    while(kontrol==0){
    printf("\nBirinci sayiyi giriniz--->");
	scanf("%f",&a);
	printf("\nYapmak istediginiz islemi giriniz--->");
	scanf(" %c",&islem);	
	printf("\nIkinci sayiyi giriniz--->");
	scanf("%f",&b);
	       if(islem=='+'){
		           sonuc=a+b; 
		           printf("\n\tToplamanin sonucu :%f",sonuc);
				   }
	       else if (islem=='-'){
		           sonuc=a-b;
		           printf("\n\tCikarmanin sonucu :%f",sonuc);
    			   }
	       else if (islem=='*'){
		           sonuc=a*b;
		           printf("\n\tCarpmanin sonucu :%f ",sonuc);
				   }
	       else if(islem=='/'){
		            while (b==0){
		            printf("Sayi 0 a bolunemez.Lutfen yeni bir sayi giriniz--->");
		            scanf("%f",&b);  
					}
		            sonuc=a/b;
		            printf("\n\tBolmenin sonucu :%f",sonuc); 
					}
	                   
	printf("\nIslemme devam etmek icin 0 a cikmak icin 1 e basiniz --->");    
	scanf("%d",&kontrol);  }             
	getch();
	return 0;
	}
