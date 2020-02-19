#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int i=0;
typedef struct Kayit {
	char ad[50];
	char soyad[50];
	int tel;
	struct Kayit *sonraki;
}kayits;
struct Rehber {
	char ilkHarf;
	kayits *ilkKayitPtr;
}rehber[10];

kayits *start=NULL;

int main()
{
	char ad5[50];
	char soyad5[50];
	int tel5;
	int k=0;
    int x=0;
    char c= 'A';
    for(c='A';c<='Z';c++,k++)
        {
            rehber[k].ilkHarf=c;
            rehber[k].ilkKayitPtr=NULL;
			rehber[k].ilkKayitPtr=start;
        }
	kayits *ekle;
	int secim;
	while(1)
	{
		printf("MENU\n");
		printf("Kayit Ekleme               [1]\n");
		printf("Kayit Ara (AD+SOYAD)       [2]\n");
		printf("Kayit Sil (AD+SOYAD)       [3]\n");
		printf("Kayitlari Ada Gore Sirala  [4]\n");
		printf("Kayit Soyada Gore Sirala   [5]\n");
		printf("Tum Rehber icin            [6]\n");
		printf("Cikis icin                 [7]\n");
		printf("Seciminiz=");
		scanf("%d",&secim);
		if(secim==1)
		{
			i++;
			printf("\nAd=");
	        scanf("%s",&ad5);
	        printf("\nSoyad=");
	        scanf("%s",&soyad5);
	        printf("\nTelefon Numarasi=");
            scanf("%d",&tel5);
            x=konumbul(start,ad5,soyad5,tel5);
			k_ekle(start,ad5,soyad5,tel5,x);
		}
		else if(secim==2)
		{
			ara(start,i);
		}
		else if(secim==3)
		{
		    sil(start);
		}
		else if(secim==4)
		{
			asira(start);
		}
		else if(secim==5)
		{
			ssira(start);
		}
		else if(secim==6)
		{
			yazdir(start);
		}
		else if(secim==7)
		{
			exit(1);
		}
		else
		{
			printf("SECIMINIZ MENUDE YER ALMAMAKTADIR\n");
		}
    }
	return 0;
}
int konumbul(kayits *dugum,char ad5[],char soyad5[],int tel5)//eklenecek konumu bulur
{
	int j=0;
	int k=0;
	while(dugum!=NULL)
	{
		j++;
		if(strcmp(dugum->ad,ad5)<0)
		{
			return j;
		}
		else
		{
			k++;
		}
		dugum=dugum->sonraki;
	}
	if(k==i)
	{
		return j;
	}
}
void basaekle(kayits *dugum,char a[],char b[],int c)// basa ekleme yapar
{
    kayits *temp;
    temp = (kayits*)malloc(sizeof(kayits));
    strcpy(temp->ad,a);
    strcpy(temp->soyad,b);
    temp->tel=c;
    temp->sonraki=NULL;
    if(start == NULL)
    {
        temp->sonraki =NULL;
        start = temp;
    }
    else
    {
        temp->sonraki = start;
        start = temp;
    }
}
void k_ekle(kayits *dugum,char ad5[],char soyad5[],int tel5,int x)//Ekleme yapar
{
	kayits *ekle;
	int k=1;
	kayits *g=start;
	ekle=(kayits*)malloc(sizeof(kayits));
	
	strcpy(ekle->ad,ad5);
	strcpy(ekle->soyad,soyad5);
	ekle->tel=tel5;
    ekle->sonraki=NULL;
    if(x==1||dugum==NULL)
    {
    	basaekle(start,ad5,soyad5,tel5);
	}
	else if(x==i)
	{
		
	    if(dugum==NULL)
	    {
	        start=ekle;
	    }
        else
	    {
		    while(dugum->sonraki!=NULL)
		    {
			    dugum=dugum->sonraki;
		    }
		    dugum->sonraki=ekle;
	    }
	}
	else
	{
		while(k<x-1&&g->sonraki!=NULL)
		{
			g=g->sonraki;
			k++;
		}
		ekle->sonraki=g->sonraki;
		g->sonraki=ekle;
	}
}
void ara(kayits *dugum,int i)// Arama yapar
{
	char ad1[50];
	char soyad1[50];
	int k=0;
	printf("Aradiginiz kisinin Adi=");
	scanf("%s",&ad1);
	printf("Aradiginiz kisinin soyadi=");
	scanf("%s",&soyad1);
	
	while(dugum!=NULL)
	{
		if(strcmp(dugum->ad,ad1)==0&&strcmp(dugum->soyad,soyad1)==0)
		{
			printf("Kisi bulundu Numarasi=%d\n",dugum->tel);
			break;
		}
		else
		{
			k++;
		}
		dugum=dugum->sonraki;
	}
	if(k==i)
	{
		printf("Kisi bulunamadi\n");
	}
}
int silkayara(kayits *dugum,char ad2[],char soyad2[])// Silinecek kayýdý arar
{
	int k=0;
	while(dugum!=NULL)
	{
		if(strcmp(dugum->ad,ad2)==0&&strcmp(dugum->soyad,soyad2)==0)
		{
			return 1;
		}
		else
		{
			k++;
		}
		dugum=dugum->sonraki;
	}
	if(k==i)
	{
		return 0;
	}
}
void sil(kayits *dugum)//Silme yapar
{
	kayits *onceki=dugum;
	kayits *g;
	int x;
	char ad2[50],soyad2[50];
	printf("Silmek Istediginiz Kisinin Adi=");
	scanf("%s",&ad2);
	printf("Silmek Istediginiz Kisinin Soyadi=");
	scanf("%s",&soyad2);
	x=silkayara(start,ad2,soyad2);
	
	if(x==1)
	{
        g=onceki->sonraki;
        if(strcmp(start->ad,ad2)==0 && strcmp(start->soyad,soyad2)==0)
        {
    	    start=start->sonraki;
    	    printf("%s %s kaydi silindi !\n",ad2,soyad2);
    	    i--;
    	    return;
	    }
        while(strcmp(g->ad,ad2)!=0 && strcmp(g->soyad,soyad2)!=0)
        {
    	    onceki=g;
    	    g=g->sonraki;
        }  
        onceki->sonraki=g->sonraki;
        printf("%s %s kaydi silindi !\n",ad2,soyad2);
        i--;
        return;
	}
	else
	{
		printf("Kayit Bulunmadi !\n");
		return;
	}
}
void ssira(kayits *dugum)//soyada gore sýralama
{
	int h1,gtel1;
	char gad1[50],gsoy1[50];
	for (h1=0;h1<i;h1++)
	{
        dugum=start;
        while(dugum->sonraki!=NULL)
		{
            if(strcmp(dugum->soyad,dugum->sonraki->soyad)>0)
			{
                gtel1=dugum->sonraki->tel;
                dugum->sonraki->tel=dugum->tel;
                dugum->tel=gtel1;
                strcpy(gad1,dugum->sonraki->ad);
                strcpy(dugum->sonraki->ad,dugum->ad);
                strcpy(dugum->ad,gad1);
                strcpy(gsoy1,dugum->sonraki->soyad);
                strcpy(dugum->sonraki->soyad,dugum->soyad);
                strcpy(dugum->soyad,gsoy1);
            }
            dugum=dugum->sonraki;
        }
	}
	ters(start);
	printf("Telefon Listesi Soyada Gore Siralandi!\n");
}
void asira(kayits *dugum)// ada göre sýralama
{
	int h,gtel;
	char gad[50],gsoy[50];
	for (h=0;h<i;h++)
	{
        dugum=start;
        while(dugum->sonraki!=NULL)
		{
            if(strcmp(dugum->ad,dugum->sonraki->ad)>0)
			{
                gtel=dugum->sonraki->tel;
                dugum->sonraki->tel=dugum->tel;
                dugum->tel=gtel;
                strcpy(gad,dugum->sonraki->ad);
                strcpy(dugum->sonraki->ad,dugum->ad);
                strcpy(dugum->ad,gad);
                strcpy(gsoy,dugum->sonraki->soyad);
                strcpy(dugum->sonraki->soyad,dugum->soyad);
                strcpy(dugum->soyad,gsoy);
            }
            dugum=dugum->sonraki;
        }  
	}
	ters(start);
	printf("Telefon Listesi Ada Gore Siralandi!\n");
}
void ters(kayits *dugum)//yazdýrma yaparken tersden yazdýgý icin düzeltmesi amaçlý ters listeyi ters çevirme
{
	kayits *temp;
	kayits *prev=NULL;
	
	dugum=start;
	while(dugum!=NULL)
	{
		temp=dugum->sonraki;
		dugum->sonraki=prev;
		prev=dugum;
		dugum=temp;
	}
	start=prev;
}
void yazdir(kayits *dugum)// listeyi yazdirma
{
	ters(start);
	printf("\n");
	dugum=start;
	while(dugum!=NULL)
	{
		printf("Adi=         %s\t",dugum->ad);
        printf("Soyadi=      %s\t",dugum->soyad);
        printf("Telefon=     %d\n",dugum->tel);
        dugum=dugum->sonraki;
	}
	ters(start);
}
