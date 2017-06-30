/*
Y���na say� ekleme-��karma-listeleme yap�labilcek.��kar�lan say� y���n�n son eleman� olcak.Listelemeyi yigina eklenen sekilde yazd�rcak.
*/
#include<stdio.h>
#include<stdlib.h>

struct yigin_yapisi{	
	
	int data;
    struct yigin_yapisi *ileri;

};

typedef struct yigin_yapisi yigin; //Burada "yigin" tipini yarat�yoruz.
typedef yigin *yiginPtr; // Pointerlar�n tipini yarat�yoruz.

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
                yazdir(aPtr);//Pointerda de�i�iklik yapmayaca��z, sadece yazaca��m�z i�in adresini almad�k.
                break;    //aPtr listenin ba� pointer�n�n adresini g�nderir ��nk� biz ekle fonksiyonunda s�rekli ba� pointer�n
                          //adresini de�i�tirdik ama hep o ba�� g�sterdi.
			
        }
    }
        
	system("pause");
    return 0;
}
