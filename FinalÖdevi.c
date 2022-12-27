#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int CSGoreEkMaas(int cocuksayisi, float maas);
char karsilamaMetni( char ad[50], char soyad[50]);
int dizi(int a, int b);
int yildiz(int k,int j,int n);

int main()
{
	/*
		Bir tekstil fabrikas�nda �al��an i��iler sahip oldukar� �ocuk say�lar�na ve her fazladan �rettikleri �r�n 
	say�s�na g�re ek �cret alacakt�r. �lk olarak �al��an�n ad� girilecektir. Sonra sahip oldu�u �ocuk say�s� 
	girilecektir. 1 �ocu�a sahip ise maa��n�n %5 i, 2 �ocu�a sahip ise maa��n�n %10 u, 3 �ocu�a sahip is 
	maa��n�n %15 i, 4 ve daha fazla �ocu�a sahip ise maa��n�n %20 si kadar ek �cret alacakt�r. Sonra �al��t��� 
	g�n say�s� girilecektir ve 1 g�nde 100 den fazla �retti�i her �r�n i�in %0,1 ek �cret alacakt�r. �ocu�a 
	sahip olmayanlar veya fazladan �r�n �retmeyenler ek �cret almayacakt�r. 
	*/
	
	FILE *dosyapoint;
    dosyapoint=(fopen("dosya.txt", "a"));
    
	if(dosyapoint == NULL)
   {
       printf("Hata!");
       system("PAUSE");
   }
	
	char cdizi1[7] = { 'K', 'a', 'r', 'a', 'c', 'a', '\0' };
	char cdizi2[8] = {'T', 'e', 'k', 's', 't','i', 'l', '\0' } ;
	printf("\r\r%s %s", cdizi1, cdizi2);
	
	int cocuksayisi, gun, urun ,calisansayisi, i,a ,b;
	int yas[]={0};
	char ad[50], soyad[50];
	float maas, ymaas, topmaas;
	
	printf("\n\n\nIs yerindeki calisan sayisini giriniz:\n");
	scanf("%d", &calisansayisi);
	for(i=0; i<calisansayisi; i++)
	{	
   		printf("\n%d. calisanin verilerini giriniz. \n", i+1);
   		
   		karsilamaMetni(ad, soyad);
   		
   		printf("Calisanin yasini giriniz: \n");
		scanf("%d", &yas[i]);
   		
   		printf("Maasini giriniz: \n");
		scanf("%f", &maas);
	
		printf("Sahip oldugu cocuk sayisini giriniz: \n");
		scanf("%d", &cocuksayisi);
   		
  		CSGoreEkMaas(cocuksayisi, maas);
	
		printf("\nCalistigi gun sayisini gir: \n");
		scanf("%d", &gun);

		printf("Fazladan urettigi urun sayisini gir: \n");
		scanf("%d", &urun);
	
		ymaas=gun*urun*10/100;
		printf("Yeni maasi %f dir.\n", ymaas);
	
		topmaas=maas+ymaas;
		printf("toplam maasi %f dir.\n\n\n", topmaas);
		printf("\n\n");
	
		int k,j,n=10;
		
    	yildiz(k,j,n=10);
    	
   		 printf("\n\n");
		
   		fprintf(dosyapoint,"\nAd: %s \nSoyAd: %s \nYas: %d \n", ad, soyad);
   		fprintf(dosyapoint,"Yas: %d \nCocukSayiyi: %d \n", yas, cocuksayisi);
   		fprintf(dosyapoint,"CalistigiGun: %d \nFazladanUrettigiUrunSayisi: %d \n", gun, urun);
   		fprintf(dosyapoint,"ToplamMaas=%f \n", topmaas);
   		 
	}
	fclose(dosyapoint);
    system("PAUSE");
	dizi(a, b);
	
	return 0;
}

	//is yerindeki iscilerin ad-soyadlara� 
	char karsilamaMetni( char ad[50], char soyad[50])
	{
		printf("Calisanin adini giriniz:\n");
		scanf("%s", &ad);
		
		printf("Calisanin soyadini giriniz: \n");
		scanf("%s", &soyad);
		
	}

	//cocuk sayisina g�re ek ucret hesaplama.
	int CSGoreEkMaas(int cocuksayisi, float maas)
	{
		if(cocuksayisi==0)
		printf("\nCocuga sahip olmadigindan ek ucret alamaz.\nYeni maasi %f dir.\n", maas);

		else if(cocuksayisi==1)
		{
			printf("\nMaasinin yuzde 5'i kadar ek ucret alir: \n");
			maas*=1.05;
			printf("Yeni maasi: %f dir. \n", maas);
		}
	
		else if(cocuksayisi==2)
		{
			printf("\nMaasinin yuzde 10'u kadar ek ucret alir: \n");
			maas*=1.1;
			printf("Yeni maasi: %f dir. \n", maas);
		}
	
		else if(cocuksayisi==3)
		{
			printf("\nMaasinin yuzde 15'i kadar ek ucret alir: \n");
			maas*=1.15;
			printf("\nYeni maasi: %f dir. \n", maas);
		}

		else
		{
			printf("\nMaasinin yuzde 20'si kadar ek ucret alir: \n");
			maas*=1.2;
			printf("Yeni maasi: %f dir. \n", maas);
		}	
	}
	
	//y�ld�z ekleme
	int yildiz(int k,int j,int n)
	{
		for(k=1 ; k<=n ; k++)
		{
        	for(j=1 ; j<=n-k ; j++)
        		printf(" ");
        	for(j=1 ; j<=(k*2-1) ; j++)
        		printf("*");
				printf("\n");
   		}
		
	}

	//dizi ekleme
	int dizi(int a, int b)
	{
		int dizi1[ 2 ][ 3 ] = { { 1, 2, 3 }, { 4, 5, 6 } },
    	dizi2[ 2 ][ 3 ] = { 1, 2, 3, 4, 5 },
   		dizi3[ 2 ][ 3 ] = { { 1, 2 }, { 4 } };
    
    	printf("Dizi 1: \n");
    	for(a=0;a<2;a++)
    	{
    		for(b=0;b<3;b++)
    		printf("%4d", dizi1[a][b]);
    		printf("\n");
		}
	
		printf("Dizi 2: \n");
    	for(a=0;a<2;a++)
    	{
    		for(b=0;b<3;b++)
    		printf("%4d", dizi2[a][b]);
    		printf("\n");
		}
	
		printf("Dizi 3: \n");
    	for(a=0;a<2;a++)
    	{
    		for(b=0;b<3;b++)
    		printf("%4d", dizi3[a][b]);
    		printf("\n");
		}
	}
