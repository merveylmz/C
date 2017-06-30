#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

FILE *p, *f ;	int i ;	 char secim ;

struct ogrenci{
	
	char ad[10], soyad[10] ;
	double no ;
	int kntrl ;

}kayit, girilen, kontrol;

void Listele( struct ogrenci k ){	//LÝSTELEME

	printf("ADI\t\tSOYADI\t\tNUMARASI\n");	printf("---\t\t------\t\t--------\n");
	
	p=fopen("kayit.txt","r");
	while( !feof(p) ){
		
		fscanf(p, "%s\t\t%s\t\t%ld %d\n", k.ad, k.soyad, &k.no, &k.kntrl);
		if(k.kntrl == 1)
			printf("%s\t\t%s\t\t%ld\n", k.ad, k.soyad, k.no);
	}
	fclose(p);		
}

void SiraliEkle( struct ogrenci *kayit, struct ogrenci *girilen, struct ogrenci kontrol ){	//SIRALI EKLEME
	
	int kayitvar=0, geln=0 ;
			
	printf("\n  Isim giriniz: ");		scanf("%s",girilen -> ad);		//    if(kayitvar = Bul (&(*kayit), *girilen))
	printf("  Soyisim giriniz: ");	    scanf("%s",girilen -> soyad);    // 	  printf("\nGirdiginiz numara listede zaten bulunmaktadir...\n");
	printf("  Numara giriniz: ");		scanf("%ld",&girilen -> no);
	
	p=fopen("kayit.txt","r");
	while( !feof(p) ){
		
		fscanf(p, "%s\t\t%s\t\t%ld %d\n", kayit -> ad, kayit -> soyad ,&kayit -> no, &kayit -> kntrl);
		if(girilen -> no == kayit -> no && kayit -> kntrl == 1 && kontrol.no != kayit -> no){
			
			printf("\n  Girdiginiz numara listede zaten bulunmaktadir...\n");
			kayitvar=1;
			break;
		}
	}
	fclose(p);
	
	if(kayitvar == 0){		// girilen kaydýn bilgileri dosyada bulunmuyorsa
		
		p=fopen("kayit.txt","r");
		f=fopen("sýralý.txt","w");
		do{
			
			fscanf(p, "%s\t\t%s\t\t%ld %d\n", kayit -> ad, kayit -> soyad, &kayit -> no, &kayit -> kntrl);
			if(geln == 0){			// yeni girilen kaydýn bilgilerini dosyaya yazdýrýlmadýysa
				
				for(i=0; kayit -> ad[i] != '\0' && girilen -> ad[i] != '\0'; ){		//  isme göre sýralama 
					
					if(girilen -> ad[i] < kayit -> ad[i]){
							
						fprintf(f, "%s\t\t%s\t\t%ld 1\n", girilen -> ad, girilen -> soyad, girilen -> no);
						geln++;
						break;
					}
					else if(girilen -> ad[i] == kayit -> ad[i]) i++;
					else if(girilen -> ad[i] > kayit -> ad[i])  break;
				}
				if(kayit -> ad[i] == '\0' && girilen -> ad[i] == '\0' && girilen -> ad[i] == kayit -> ad[i]){		// isimler aynýysa
					
					for(i=0; (kayit -> soyad[i] != '\0' && girilen -> soyad[i] != '\0'); ){		// soyisime göre sýralama
						
						if(girilen -> soyad[i] < kayit -> soyad[i]){
								
							fprintf(f, "%s\t\t%s\t\t%ld 1\n", girilen -> ad, girilen -> soyad, girilen -> no);
							geln++;
							break;
						}
						else if(girilen -> soyad[i] == kayit -> soyad[i]) i++;
						else if(girilen -> soyad[i] > kayit -> soyad[i])  break;
					}
				}
			}
			if(kayit -> ad != kontrol.ad && kayit -> soyad != kontrol.soyad && kayit -> no != kontrol.no)	// deðiþtirme yapýlýrken deðiþtirilcek olan kaydýn bilgilerine 
				fprintf(f, "%s\t\t%s\t\t%ld %d\n", kayit -> ad, kayit -> soyad, kayit -> no, kayit -> kntrl);	// eþit olmadýðý sürece yazdýrma
		
		}while( !feof(p) );
		
		if(geln == 0 ) 		//girilen kayýt sonuncu ise 
			fprintf(f, "%s\t\t%s\t\t%ld 1\n", girilen -> ad, girilen -> soyad, girilen -> no);
	
		fclose(p);	fclose(f);
	
		remove("kayit.txt");	rename("sýralý.txt","kayit.txt");
		printf("\n  Islem basariyla gerceklestirildi...\n");
	}
}

int Bul( struct ogrenci *k, struct ogrenci g ){	//BULMA
	
	int kayityok=0;
	scanf("%ld",&g.no);		
	
	p=fopen("kayit.txt","r");
	while( !feof(p) ){
	
		fscanf(p, "%s\t\t%s\t\t%ld %d\n", k -> ad, k -> soyad, &k -> no, &k -> kntrl);
		if(g.no == k -> no && k -> kntrl == 1 && kayityok == 0){
				
				printf("\n  KAYDIN BILGILERI :\n");
				printf("\n  Kaydin Adi : %s\n",k -> ad);
				printf("  Kaydin Soyadi : %s\n",k -> soyad);
				printf("  Kaydin Numarasi : %ld\n",k -> no);
				kayityok++;
				break;
		}
	}
	if(kayityok == 0)
		printf("\n  Aradiginiz kayit bulunamadi!..\n");
	fclose(p);		return kayityok ;
}
	
void Degistir( struct ogrenci kayit, struct ogrenci girilen, struct ogrenci kontrol ){	//DEGÝÞTÝRME
	
	if(int buldu = Bul(&kontrol, girilen)){

		printf("\n  Kaydi degistirmek istediginize emin misiniz?\n  ( Evet--> e Hayir--> h ) ===> ");
		scanf(" %c",&secim);
	
		if(secim == 'e' || secim == 'E'){
		
			printf("\n  YENI BILGILERI GIRINIZ :\n");
			SiraliEkle(&kayit, &girilen, kontrol);
		}
	}
}

void Sil( struct ogrenci kayit, struct ogrenci girilen ){		//SÝLME
	
	int degskn = 0;
	scanf("%ld",&girilen.no);
	
	p=fopen("kayit.txt","r");
	f=fopen("sýralý.txt","w");
	while( !feof(p) ){
		
		int sildi=0 ;			
		fscanf(p, "%s\t\t%s\t\t%ld %d\n", kayit.ad, kayit.soyad, &kayit.no, &kayit.kntrl);
		if(girilen.no == kayit.no && kayit.kntrl == 1 && sildi == 0 ){
			
			degskn++;
			printf("\n  KAYDIN BILGILERI :\n");
			printf("\n  Kaydin Adi : %s\n",kayit.ad);
			printf("  Kaydin Soyadi : %s\n",kayit.soyad);
			printf("  Kaydin Numarasi : %ld\n",kayit.no);
			printf("\n  Kaydi silmek istediginize emin misiniz?\n  ( Evet--> e Hayir--> h) ===> ");
			scanf(" %c",&secim);
			if(secim == 'e' || secim == 'E'){
				
				fprintf(f, "%s\t\t%s\t\t%ld 0\n", kayit.ad, kayit.soyad, kayit.no);
				sildi=1;
			}
			else{
				
				fprintf(f, "%s\t\t%s\t\t%ld 1\n", kayit.ad, kayit.soyad, kayit.no);	
				sildi=1;						
			}
			printf("\n  Islem basariyla gerceklestirildi...\n");
		}
		if(sildi == 0)			
			fprintf(f, "%s\t\t%s\t\t%ld %d\n", kayit.ad, kayit.soyad, kayit.no, kayit.kntrl);
		
		if(girilen.no == kayit.no && kayit.kntrl == 0){
			degskn++;
			printf("\n  Kayit zaten silinmistir...\n");	
		}
	}
	if(degskn == 0)
		printf("\n  Silmek istediginiz kayit bulunamadi...\n");
	
	fclose(p);	fclose(f);
			
	remove("kayit.txt");	rename("sýralý.txt","kayit.txt");	fflush(stdin);
}

int main (){
	
	int kntrl ;
	do{
		system("cls");
		printf("\n\t ----------\n");	printf("\t| ANA MENU |\n");	printf("\t ----------");
		printf("\n  << 1 >> --> Listeyi Sirala\n");
		printf("  << 2 >> --> Kayit Ekle\n");
		printf("  << 3 >> --> Kayit Ara\n");
		printf("  << 4 >> --> Kayit Duzenle\n");
		printf("  << 5 >> --> Kayit Sil\n");
	
		printf("\n  Yapmak istediginiz islemi seciniz ===> ");
		scanf(" %c",&secim);
		
		system("cls");
		switch(secim){
			
			case '1' :
				Listele(kayit);
				break ;
				
			case '2' :
				printf("\n  Eklemek Istediginiz Kaydin Bilgilerini Giriniz :\n");
				SiraliEkle(&kayit, &girilen, kontrol);
				break ;
				
			case '3' :
				printf("\n  Aramak istediginiz kaydin numarasini giriniz : ");
				Bul(&kayit, girilen);
				break ;
				
			case '4' :
				printf("\n  Degistirmek istediginiz kaydin numarasini giriniz : ");
				Degistir(kayit, girilen, kontrol);
				break ;
				
			case '5' :
				printf("\n  Silmek istediginiz ogrencinin numarasini giriniz : ");
				Sil(kayit, girilen);
				break ;
			
			default :
				printf("\n  Yanlis secim yaptiniz ...\n ");
				break ;
		}	
		printf("\n  Baska islem yapmak istiyor musunuz?\n  ( Evet--> e Hayir--> h ) ===> ");
		scanf(" %c",&kntrl);	
	
	}while(kntrl == 'e' || kntrl == 'E');
	
	getch ();	return 0;
}
