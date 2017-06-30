/*
Yýðýna sayý ekleme-çýkarma-listeleme yapýlabilcek.Çýkarýlan sayý yýðýnýn son elemaný olcak.Listelemeyi yigina eklenen sekilde yazdýrcak.
*/
#include<stdio.h>
#include<stdlib.h>

struct yigin_yapisi{	
	
	int data;
    struct yigin_yapisi *ileri;

};

typedef struct yigin_yapisi yigin; //Burada "yigin" tipini yaratýyoruz.
typedef yigin *yiginPtr; // Pointerlarýn tipini yaratýyoruz.

void ekle(yiginPtr * gelen,int veri){
	
	yiginPtr yeni;
    yeni = (yiginPtr)(malloc(sizeof(yigin)));
    yeni->data = veri;
    yeni->ileri = *gelen;
    *gelen = yeni;  
    
}

void cikar(yiginPtr *gelen){
	
	yiginPtr gecici;
    int cikarilan;
    gecici = *gelen;
    cikarilan = gecici->data;
    *gelen = (*gelen)->ileri;
    free (gecici);
    printf("\n%d yigindan cikarildi\n",cikarilan);
    
}

void yazdir(yiginPtr gelen){
	
	while(gelen != NULL){
		
		printf("%d\n",gelen->data);
        gelen = gelen->ileri;
		
	}
}

int main(){
	
	int sayi,secim,kontrol=1;
    yiginPtr aPtr=NULL;
    
	while(kontrol != 0){
		
		printf("\n0-->Cikis\n");
		printf("1-->Yigina sayi gir\n");
        printf("2-->Yigindan sayi cikar\n");
        printf("3-->Yigini goster\n");
        
        scanf("%d",&secim);
        switch(secim){
        	
        	case 0:
            	kontrol=0;
            	break;
        	
			case 1:
            	printf("\nYigina bir sayi giriniz\n");
              	scanf("%d",&sayi);
              	ekle(&aPtr,sayi);
              	break;
			
			case 2:
            	cikar(&aPtr);
              	break;
			
			case 3:
            	printf("\nYigindakiler : \n");
                yazdir(aPtr);//Pointerda deðiþiklik yapmayacaðýz, sadece yazacaðýmýz için adresini almadýk.
                break;    //aPtr listenin baþ pointerýnýn adresini gönderir çünkü biz ekle fonksiyonunda sürekli baþ pointerýn
                          //adresini deðiþtirdik ama hep o baþý gösterdi.
			
        }
    }
        
	system("pause");
    return 0;
}
