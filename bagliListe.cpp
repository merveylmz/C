#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

/*Baðlý Liste'de Ekleme Listeleme Arama */


typedef struct liste {
	
	int numara ;
	struct liste *sonraki ;
	
}LISTE;

	LISTE *ilk = NULL ,*son = NULL ;

void ekle ( LISTE *bilgi )
{
	
	if ( ilk == NULL ){
		
		ilk = bilgi ;
		son = bilgi ;
		son ->  sonraki = NULL ;
		
	}
	else {
		
		son -> sonraki = bilgi ;
		son = bilgi ;
		son -> sonraki = NULL ;
		
	}
	
}

int listele ( ) 
{
	
	LISTE *gecici ;
	gecici = ilk ;
	
	if ( ilk == NULL )	return 0 ;
	 while ( gecici != NULL ){
	 	
	 	printf("%d\n",gecici->numara) ;
	 	gecici = gecici -> sonraki ;
	 
	 }
	return 1 ;
}

int ara ( int aranan ) 
{
	
	LISTE *gecici = ilk ;

	while (gecici != NULL ) {
		
		if(aranan == gecici -> numara )	return aranan ;
		
		gecici = gecici -> sonraki ;
	}
	
	return NULL;
	
}

void silme ( int num ){
	
	LISTE *gecici = ilk, *bironceki= NULL ;		//bir onceki bilgiyi kaybetmemek icin tuttuk...
     
    while( gecici!=NULL ){
    	
    	if(gecici -> numara == num) break;
        bironceki=gecici;
        gecici=gecici->sonraki;
    }
     
    if(gecici != NULL){
    	
    	if(bironceki == NULL){
    		
    		if(ilk == son){
    			
    			ilk = NULL ;
    			son = NULL ; 
    			
    		}
    		else
    			ilk = ilk -> sonraki ;
    		
    	}
    	
    
		else if(bironceki != NULL){
			
			if(gecici == son){
			
				son = bironceki ;
				delete gecici ;
				son -> sonraki = NULL ;
				
			}
			else 
				bironceki -> sonraki = gecici -> sonraki ;
			
		} 
	}
}


int main ()
{
	
	char secim ;
	LISTE *bilgi, *gecici ;
	int sayi, aranan, num, gelen ;
	
	do{
		
		printf("ekleme e listeleme l arama a cikis c \n");
		scanf ("%s",&secim) ;
		system("cls");
		
		switch ( secim ){
			
			case 'e' :
		
				bilgi = new LISTE ;
				printf ("Bir sayi giriniz : ") ;
				scanf ("%d",&bilgi -> numara) ;
				ekle ( bilgi ) ;
				break ;
				
			case 'l' :
				
				listele() ;
				break ;
				
			case 'a' :
				
				printf ("Aranacak numara :") ;
				scanf ("%d",&aranan) ;
				gelen = ara (aranan) ;
				if(gelen != NULL)
					printf("Aranan sayi mevcut\n");
				else 
					printf("Aranan sayi yok\n");
				break;
			case 's':
				printf("silinecek numarayi giriniz.");
				scanf("%d",&num);
				silme(num);
				break;
	    }
    }while(secim != 'c');

	getch () ;
	return 0 ;
	
} 
