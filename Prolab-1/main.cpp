#include <winsock2.h>
#include <graphics.h>
#include <curl/curl.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <wininet.h>
#include <vector>
#include <cmath>
#include <math.h>
struct sekiller
{
	int sekil[100];
	int konum;
}sekilSayisi[3];



FILE *dosya;
//http://bilgisayar.kocaeli.edu.tr/prolab1/prolab1.txt


int boyali_mi(int baslangic_x,int baslangic_y,int i,int j,int grid_size){
    int gd = DETECT, gm;
    int kontrol_x=baslangic_x+grid_size*j;
    int kontrol_y=baslangic_y+grid_size*i;
    int k,z;
    for(k=1;k<grid_size-1;k++){
                             for(z=1;z<grid_size-1;z++){
                         if(getpixel(kontrol_x+z,kontrol_y+k)==BLUE) return 1;
                         }
                         }
    
    
    
    }


int tek_nokta_icinde_mi(int kontrol_x, int kontrol_y, int x_sort[4], int y_sort[4]){
    int check;
    float d, WA, WB, WC;
    int k, i, x, y ,bx, by, cx, cy, px, py; 
    int boyama_x;
    int boyama_y;
    px=kontrol_x;
    py=kontrol_y;
    bx=x_sort[1]-x_sort[0];
    by=y_sort[1]-y_sort[0];  
    cx=x_sort[2]-x_sort[0];  
    cy=y_sort[2]-y_sort[0];  
     
    x=px-x_sort[0];  
    y=py-y_sort[0];
    
    d=(bx*cy)-(cx*by);    
    WA=(x*(by-cy)+y*(cx-bx)+(bx*cy)-(cx*by))/d;
    WB=((x*cy)-(y*cx))/d;
    WC=((y*bx)-(x*by))/d;
    
    check=0;
    if(WA<1 && WA>0) check=check+1;
    if(WB<1 && WB>0) check=check+1;
    if(WC<1 && WC>0) check=check+1;
                         
                     
                         if(check==3){
                                      return 1;
                                      }
    
    return 0;
    
    }


int ucgen_icinde_mi(int matris_x,int matris_y,int kontrol_x,int kontrol_y, int square[10],int x_sort[4], int y_sort[4],int shape1[8], int konum, int grid_size){
    int z, i, j, k, px, py, x, y, alan=0;
    int bx, by, cx, cy;
    int sayac=0;
    int gd = DETECT, gm;
    int check;
    float d, WA, WB, WC;
    int boyama_x;
    int boyama_y;
    
    
    for(z=0;z<matris_x/grid_size+1;z++,kontrol_x+=grid_size){
                            
                            kontrol_y=square[1];
                            for(j=0;j<matris_y/grid_size+1;j++,kontrol_y+=grid_size){
    
                                                                
    boyama_x=0;
    boyama_y=0;
    px=kontrol_x;
    py=kontrol_y;
                                                                  
                                                    
    
    
    for(k=0, i=0; i<4; k+=2, i++){
             x_sort[i]=shape1[k];
             }
             
    for(k=1, i=0; i<4; k+=2, i++){
             y_sort[i]=shape1[k];
             }
   
    
    bx=x_sort[1]-x_sort[0];
    by=y_sort[1]-y_sort[0];  
    cx=x_sort[2]-x_sort[0];  
    cy=y_sort[2]-y_sort[0];  
     
    x=px-x_sort[0];  
    y=py-y_sort[0];
    
    d=(bx*cy)-(cx*by);    
    WA=(x*(by-cy)+y*(cx-bx)+(bx*cy)-(cx*by))/d;
    WB=((x*cy)-(y*cx))/d;
    WC=((y*bx)-(x*by))/d;
    
    check=0;
    if(WA<1 && WA>0) check=check+1;
	if(WB<1 && WB>0) check=check+1;
	if(WC<1 && WC>0) check=check+1;
	setfillstyle(1,BLUE);
    if(check==3){
		boyama_x=kontrol_x;
    	boyama_y=kontrol_y;
		if(konum==0){
        	if(getpixel(boyama_x+5,boyama_y+5)==BLUE) continue;
        	int boyama_dizi[10]={boyama_x, boyama_y, boyama_x+grid_size, boyama_y, boyama_x+grid_size, boyama_y+grid_size, boyama_x, boyama_y+grid_size, boyama_x, boyama_y};
        	fillpoly(5,boyama_dizi);
        	alan++;
        	check=0;
    	}
    	else if(konum==1){
			if(getpixel(boyama_x-5,boyama_y+5)==BLUE) continue;
        	int boyama_dizi[10]={boyama_x, boyama_y, boyama_x-grid_size, boyama_y, boyama_x-grid_size, boyama_y+grid_size, boyama_x, boyama_y+grid_size, boyama_x, boyama_y};
        	fillpoly(5,boyama_dizi);
        	alan++;
        	check=0;
    	}
    	else if(konum==2){
        	if(getpixel(boyama_x+5,boyama_y-5)==BLUE) continue;
        	int boyama_dizi[10]={boyama_x, boyama_y, boyama_x+grid_size, boyama_y, boyama_x+grid_size, boyama_y-grid_size, boyama_x, boyama_y-grid_size, boyama_x, boyama_y};
        	fillpoly(5,boyama_dizi);
        	alan++;
        	check=0;
    	}
    	else if(konum==3){
        	if(getpixel(boyama_x-5,boyama_y-5)==BLUE) continue;
        	int boyama_dizi[10]={boyama_x, boyama_y, boyama_x-grid_size, boyama_y, boyama_x-grid_size, boyama_y-grid_size, boyama_x, boyama_y-grid_size, boyama_x, boyama_y};
        	fillpoly(5,boyama_dizi);
    		alan++;
        	check=0;
    	}
	}
    else if(check!=3){
    	int dondurulen_alan=0;
        if(konum==0){
            int temp_x=kontrol_x+1;
            int temp_y=kontrol_y+1;
            dondurulen_alan=tek_nokta_icinde_mi(temp_x, temp_y, x_sort, y_sort);
            if(dondurulen_alan==1){
                boyama_x=kontrol_x;
                boyama_y=kontrol_y;
                if(getpixel(boyama_x+5,boyama_y+5)==BLUE) continue;
                    int boyama_dizi[10]={boyama_x, boyama_y, boyama_x+grid_size, boyama_y, boyama_x+grid_size, boyama_y+grid_size, boyama_x, boyama_y+grid_size, boyama_x, boyama_y};
                    fillpoly(5,boyama_dizi);
                    alan++;
            }
        }
        else if(konum==1){
            int temp_x=kontrol_x-1;
            int temp_y=kontrol_y+1;
            dondurulen_alan=tek_nokta_icinde_mi(temp_x, temp_y, x_sort, y_sort);
            if(dondurulen_alan==1){
                boyama_x=kontrol_x;
                boyama_y=kontrol_y;
                if(getpixel(boyama_x-5,boyama_y+5)==BLUE) continue;
                    int boyama_dizi[10]={boyama_x, boyama_y, boyama_x-grid_size, boyama_y, boyama_x-grid_size, boyama_y+grid_size, boyama_x, boyama_y+grid_size, boyama_x, boyama_y};
                    fillpoly(5,boyama_dizi);
                	alan++;
            }
        }
        else if(konum==2){
            int temp_x=kontrol_x+2;
            int temp_y=kontrol_y-2;
            dondurulen_alan=tek_nokta_icinde_mi(temp_x, temp_y, x_sort, y_sort);
            if(dondurulen_alan==1){
                boyama_x=kontrol_x;
                boyama_y=kontrol_y;
                if(getpixel(boyama_x+5,boyama_y-5)==BLUE) continue;
                    int boyama_dizi[10]={boyama_x, boyama_y, boyama_x+grid_size, boyama_y, boyama_x+grid_size, boyama_y-grid_size, boyama_x, boyama_y-grid_size, boyama_x, boyama_y};
                    fillpoly(5,boyama_dizi);
                	alan++;
            }
        }
        else if(konum==3){
            int temp_x=kontrol_x-2;
            int temp_y=kontrol_y-2;
            dondurulen_alan=tek_nokta_icinde_mi(temp_x, temp_y, x_sort, y_sort);
            if(dondurulen_alan==1){
                boyama_x=kontrol_x;
            	boyama_y=kontrol_y;
                if(getpixel(boyama_x-5,boyama_y-5)==BLUE) continue;
                    int boyama_dizi[10]={boyama_x, boyama_y, boyama_x-grid_size, boyama_y, boyama_x-grid_size, boyama_y-grid_size, boyama_x, boyama_y-grid_size, boyama_x, boyama_y};
                    fillpoly(5,boyama_dizi);
                    alan++;
            }
        }
        check=0;      
    } 
} 
}
return alan;
    }



int koordinat_duzlemi(int grid_size){
    int i, j;
    setcolor(GREEN);
    for(i=0;i<1000;i=i+grid_size){
        line(0,i,1000,i);}
	for(j=0;j<1000;j=j+grid_size){
        line(j,0,j,1000);}
 	setcolor(WHITE);
}




int sekli_cizdir(int shape1[14], int kenar_sayisi){
    int i;
    for(i=0;i<kenar_sayisi-3;i+=2){
    	line(shape1[i],shape1[i+1],shape1[i+2],shape1[i+3]);}
}



int calculate_area(int shape1[10], int grid_size, int* alanp){
    int i, j, k, temp;
    int x_sort[4];
    int y_sort[4];
    
    int square[10];
    
    for(k=0, i=0; i<4; k+=2, i++){
        x_sort[i]=shape1[k];
    }
             
    for(k=1, i=0; i<4; k+=2, i++){
        y_sort[i]=shape1[k];
    }
    
    
    for(j=0;j<4;j++){
    for(i=0;i<(4-j);i++){
        if(i==3) continue;
        if(x_sort[i]>x_sort[i+1]){
            temp=x_sort[i];
            x_sort[i]=x_sort[i+1];
            x_sort[i+1]=temp;
        }
    }    
    }  
                 
    for(j=0;j<4;j++){
    for(i=0;i<(4-j);i++){
        if(i==3) continue;
        if(y_sort[i]>y_sort[i+1]){
            temp=y_sort[i];
            y_sort[i]=y_sort[i+1];
            y_sort[i+1]=temp;
        }
    }    
    }
    
    square[0]=x_sort[0];
    square[1]=y_sort[0];
    square[2]=x_sort[0];
    square[3]=y_sort[3];
    square[4]=x_sort[3];
    square[5]=y_sort[3];
    square[6]=x_sort[3];
    square[7]=y_sort[0];
    square[8]=square[0];
    square[9]=square[1];            
     
    int matris_x, matris_y;
     
     
    matris_y = y_sort[3]-y_sort[0];
    matris_x = x_sort[3]-x_sort[0];
    if(matris_x<0) matris_x=matris_x*-1;
    if(matris_y<0) matris_y=matris_y*-1;
    for(i=0;i<8;i+=2){
        setcolor(RED);
        line(square[i],square[i+1],square[i+2],square[i+3]);
        setcolor(WHITE);
    } 
                   
    
    int kontrol_x=square[0];
    int kontrol_y=square[1];
    
    
    
    int alan=0;
    int z;
    int konum=0;
    alan=ucgen_icinde_mi(matris_x, matris_y, kontrol_x, kontrol_y, square, x_sort, y_sort, shape1, konum, grid_size);
    *alanp=*alanp+alan;
    
    konum=1;
    kontrol_x=square[0]+grid_size;
    kontrol_y=square[1];
    alan=ucgen_icinde_mi(matris_x, matris_y, kontrol_x, kontrol_y, square, x_sort, y_sort, shape1, konum, grid_size);
    *alanp=*alanp+alan;
    
    konum=2;
    kontrol_x=square[0];
    kontrol_y=square[1]+grid_size;
    alan=ucgen_icinde_mi(matris_x, matris_y, kontrol_x, kontrol_y, square, x_sort, y_sort, shape1, konum, grid_size);
    *alanp=*alanp+alan;
    
    konum=3;
    kontrol_x=square[0]+grid_size;
    kontrol_y=square[1]+grid_size;
    alan=ucgen_icinde_mi(matris_x, matris_y, kontrol_x, kontrol_y, square, x_sort, y_sort, shape1, konum, grid_size);
    *alanp=*alanp+alan;
    
    
    
    for(i=0;i<8;i+=2){
        setcolor(RED);
        line(square[i],square[i+1],square[i+2],square[i+3]);
        setcolor(WHITE);
    }
    return 1;
            
}

int islemler(int* alanp2,int* kare_sayisip,int kenar_sayisi,int shape1[20],int birim_sondaj_m,int birim_platform_m, int grid_size){
	
 int j, k;
 //8 üçgen, 10 dörtgen, 12 beþgen, 14 altýgen
 int triangle1[8];
 int triangle2[8];
 int triangle3[8];
 int triangle4[8];
 //iç bükeylerde sorun olmamasý için
 int ortalama_x=0, ortalama_y=0;
 int tespit_konum=0;
 int temp1, temp2;
 float fark_x, fark_y, toplam;
 float fark=500.0;
 for(j=0;j<kenar_sayisi-2;j+=2){
    ortalama_x+=shape1[j];
}
 for(j=1;j<kenar_sayisi-2;j+=2){
    ortalama_y+=shape1[j];
}
 ortalama_x=ortalama_x/(kenar_sayisi-2)*2;
 ortalama_y=ortalama_y/(kenar_sayisi-2)*2;
 for(j=0, k=1;j<kenar_sayisi-2;j+=2, k+=2){
    fark_x=ortalama_x-shape1[j];
    fark_y=ortalama_y-shape1[k];
    fark_x=pow(fark_x, 2);
    fark_y=pow(fark_y, 2);
    toplam=fark_x+fark_y;
    toplam=sqrt(toplam);
    if(toplam<fark){ 
        tespit_konum=j;
        fark=toplam;
    }
}
 while(tespit_konum>0){
    temp1=shape1[0];
    for(j=0;j<kenar_sayisi-3;j++){
        shape1[j]=shape1[j+1];
    }
    shape1[kenar_sayisi-3]=temp1;
    tespit_konum--;
}
 shape1[kenar_sayisi-2]=shape1[0];
 shape1[kenar_sayisi-1]=shape1[1];
 
 for(j=0;j<kenar_sayisi;j++){
    shape1[j]=shape1[j]*grid_size;
}
 
 if(kenar_sayisi==8){//üçgen
    k=0;
    for(j=0;j<6;j++, k++){
        triangle1[j]=shape1[j];
    }
    triangle1[6]=triangle1[0];
    triangle1[7]=triangle1[1];
}
 if(kenar_sayisi==10){//dörtgen
	k=0;
    for(j=0;j<6;j++, k++){
        triangle1[j]=shape1[k];
    }
    triangle1[6]=triangle1[0];
    triangle1[7]=triangle1[1];                                                  
    k=8;
    for(j=0;j<6;k++, j++){
        triangle2[j]=shape1[k];
        if(k%2==1){k-=4;}
    }
	triangle2[6]=triangle2[0];
    triangle2[7]=triangle2[1];
}
 
 if(kenar_sayisi==12){//beþgen
    k=0;
    for(j=0;j<6;j++, k++){
    	triangle1[j]=shape1[k];
    }
	triangle1[6]=triangle1[0];
    triangle1[7]=triangle1[1];                                                  
    k=10;
    for(j=0;j<6;k++, j++){
        triangle2[j]=shape1[k];
        if(k%2==1){k-=4;}
    }
    triangle2[6]=triangle2[0];
    triangle2[7]=triangle2[1];}
    triangle3[0]=shape1[0];
    triangle3[1]=shape1[1];
    triangle3[6]=triangle3[0];
    triangle3[7]=triangle3[1];
    k=4;
    for(j=2;j<6;j++,k++){
        triangle3[j]=shape1[k];
    }
 if(kenar_sayisi==14){//altýgen
    k=0;
    for(j=0;j<6;j++, k++){
        triangle1[j]=shape1[k];
    }
    triangle1[6]=triangle1[0];
	triangle1[7]=triangle1[1];                                                  
    k=12;
    for(j=0;j<6;k++, j++){
        triangle2[j]=shape1[k];
        if(k%2==1){k-=4;}
    }
    triangle2[6]=triangle2[0];
    triangle2[7]=triangle2[1];
    triangle3[0]=shape1[0];
    triangle3[1]=shape1[1];
    triangle3[6]=triangle3[0];
    triangle3[7]=triangle3[1];
    k=4;
    for(j=2;j<6;j++,k++){
        triangle3[j]=shape1[k];
    }
    triangle4[0]=shape1[0];
    triangle4[1]=shape1[1];
    triangle4[6]=triangle4[0];
    triangle4[7]=triangle4[1];
    k=6;
    for(j=2;j<6;j++,k++){
        triangle4[j]=shape1[k];
    }
}

 char gecis;
 int i,alan=0, temp;
 
 sekli_cizdir(shape1, kenar_sayisi);
 
 if(kenar_sayisi>7){
 calculate_area(triangle1, grid_size, &alan);
 sekli_cizdir(shape1, kenar_sayisi);}
 if(kenar_sayisi>9){
 calculate_area(triangle2, grid_size, &alan);
 sekli_cizdir(shape1, kenar_sayisi);}
 if(kenar_sayisi>11){
 calculate_area(triangle3, grid_size, &alan);
 sekli_cizdir(shape1, kenar_sayisi);}
 if(kenar_sayisi>13){
 calculate_area(triangle4, grid_size, &alan);
 sekli_cizdir(shape1, kenar_sayisi);}
 *alanp2=alan;
 fflush(stdin);
 scanf("%c",&gecis);
 
 int x_sort_main[kenar_sayisi/2];
 int y_sort_main[kenar_sayisi/2];
 int tekrar=kenar_sayisi/2;
 
 for(k=0, i=0; i<tekrar; k+=2, i++){
    x_sort_main[i]=shape1[k];
}
             
 for(k=1, i=0; i<tekrar; k+=2, i++){
    y_sort_main[i]=shape1[k];
}
 for(j=0;j<tekrar;j++){
    for(i=0;i<(tekrar-j);i++){
        if(i==tekrar-1) continue;
        if(x_sort_main[i]>x_sort_main[i+1]){
            temp=x_sort_main[i];
            x_sort_main[i]=x_sort_main[i+1];
            x_sort_main[i+1]=temp;
        }
                                       
    }    
}
  
  
                 
 for(j=0;j<kenar_sayisi/2;j++){
    for(i=0;i<((kenar_sayisi/2)-j);i++){
        if(i==kenar_sayisi/2-1) continue;
        if(y_sort_main[i]>y_sort_main[i+1]){
            temp=y_sort_main[i];
            y_sort_main[i]=y_sort_main[i+1];
            y_sort_main[i+1]=temp;
        }
    }    
}

 char alan_yazma[5];
 sprintf(alan_yazma, "%d", *alanp2);
 outtextxy((x_sort_main[0]+x_sort_main[kenar_sayisi/2-1])/2, y_sort_main[0]-grid_size, alan_yazma);
 delay(100);
	
 int x_uzunluk=x_sort_main[kenar_sayisi/2-1]-x_sort_main[0], y_uzunluk=y_sort_main[kenar_sayisi/2-1]-y_sort_main[0];
 x_uzunluk=x_uzunluk/grid_size;
 y_uzunluk=y_uzunluk/grid_size;
 int opt_hesap_matrisi[y_uzunluk][x_uzunluk];
 int check=0, z, n, karesi;
 *kare_sayisip=*alanp2;
 for(i=0;i<y_uzunluk;i++){
    for(j=0;j<x_uzunluk;j++){
        check=boyali_mi(x_sort_main[0], y_sort_main[0], i, j, grid_size);
        if(check==1) opt_hesap_matrisi[i][j]=1;
        else opt_hesap_matrisi[i][j]=0;
    }
}
 int sifirlar_matrisi[100];
 int temp_i, temp_j;
 float maaliyet_oran, kare_oran;
 int boyama_x;
 int boyama_y;
 int paralel_x=0, sayac=2, paralel_y=0, alinacak_kare=0, sifirlar_sayisi, azalan_kare=0, iki_sayac=0, uc_sayac=0;
 int a, s, dort_sayac=0;
 if (birim_platform_m!=0){
 
    maaliyet_oran=(float)birim_platform_m/birim_sondaj_m;

 
 for(z=1;z<5;z++){
 karesi=pow(2,z);
 for(i=0;i<y_uzunluk;i++){
 	for(j=0;j<x_uzunluk;j++){
 		check=0;
		sifirlar_sayisi=0;
		alinacak_kare=0;
		azalan_kare=0;
		if(opt_hesap_matrisi[i][j]>0){
 			for(n=0;n<karesi;n++){
 				for(a=0;a<karesi;a++){				 
				 if(opt_hesap_matrisi[i+n][j+a]==z){
 					check++;
				 }
				 
				}
				}
			
			
			if(check==karesi*karesi){                      //birleþtir
					if(paralel_x==0) paralel_x=j;
					if(paralel_y==0) paralel_y=i;
					if(((j-paralel_x)*karesi)%karesi!=0) continue;
					if(((i-paralel_y*karesi))%karesi!=0) continue;
					*kare_sayisip-=3;
					for(a=0;a<karesi;a++){
						for(s=0;s<karesi;s++){
							opt_hesap_matrisi[i+a][j+s]=sayac;
						}
					
					}
					
			 }
			 
			 
			 *kare_sayisip-=azalan_kare;
			
		
		}
	}
 }

 sayac++;
}
}
 
 for(z = 5; z>0; z--){
 for(i = 0; i < y_uzunluk; i++){
    for(j = 0; j < x_uzunluk; j++){
        if(opt_hesap_matrisi[i][j]==z){
            boyama_x=x_sort_main[0]+j*grid_size;
            boyama_y=y_sort_main[0]+i*grid_size;
            karesi=pow(2, opt_hesap_matrisi[i][j]-1);
            int boyama_dizi[10]={boyama_x, boyama_y, boyama_x+karesi*grid_size, boyama_y, boyama_x+karesi*grid_size, boyama_y+karesi*grid_size, boyama_x, boyama_y+karesi*grid_size, boyama_x, boyama_y};
            setfillstyle(1, RED);
            fillpoly(5,boyama_dizi);
            delay(z);
			for(z=i; z<i+karesi; z++){
                for(n=j; n<j+karesi; n++){
                    opt_hesap_matrisi[z][n]=-1;
                }
            }
        }
    }
}
}
}


int main()
{
 
 int i, j;
    // Ýndirilecek URL http://bilgisayar.kocaeli.edu.tr/prolab1/prolab1.txt
    const char *url = "http://bilgisayar.kocaeli.edu.tr/prolab1/prolab1.txt";
    const char *komut = "curl -o veri.txt ";

    // Komut ve URL'yi birleþtirme
    char tamKomut[256];
    snprintf(tamKomut, sizeof(tamKomut), "%s%s", komut, url);

    // Komutu çalýþtýrma
    int sonuc = system(tamKomut);

    if (sonuc == 0) {
        printf("Veri basariyla indirildi.\n");
    } else {
        fprintf(stderr, "Komut calistirma hatasi: %d\n", sonuc);
        return 1;
    }

    FILE *dosya = fopen("veri.txt", "r");

    if (dosya == NULL) {
        perror("Dosya acilirken hata olustu");
        return 1;
    }

    int satir_numarasi;
    int koordinatDizisi[100]; // Her satýrda en fazla 100 koordinat bulunabilir.
    int koordinatSayisi = 0;
    printf("Okunacak satir numarasini girin: ");
    scanf("%d", &satir_numarasi);

    char satir[256]; // Her satýrýn maksimum uzunluðunu artýrabilirsiniz.

    int mevcutSatir = 0;

    while (fgets(satir, sizeof(satir), dosya) != NULL) {
        mevcutSatir++;
        if (mevcutSatir == satir_numarasi) {
            char *koordinatlar = strstr(satir, "("); // Ýlk "(" karakterini bulun
            if (koordinatlar != NULL) {
                // Ýlk "(" karakterinden sonraki kýsmý yazdýrýn
                printf("%s\n", koordinatlar);

                // Koordinatlarý diziye aktarýn
                // Ýlk "(" karakterinden sonraki kýsmý iþleyin
                char *token = strtok(koordinatlar, "(,)");
                while (token != NULL) {
                    int sayi;
                    if (sscanf(token, "%d", &sayi) == 1) {
                        koordinatDizisi[koordinatSayisi++] = sayi;
                    }
                    token = strtok(NULL, "(,)");
                }
            } else {
                printf("Koordinatlar bulunamadý.\n");
            }
        }
    }

    fclose(dosya);

    int x_koordinatlari[100];
    int y_koordinatlari[100];
    int xy_koordinatlar[100][2];
    int yeni_koordinatlar[100][2];
    int yeni_koordinatSayisi = 0;
    int sayac=0;

    for (int i = 0; i < koordinatSayisi / 2; i++) {
        x_koordinatlari[i] = koordinatDizisi[i * 2];
        y_koordinatlari[i] = koordinatDizisi[i * 2 + 1];
    }
    printf("\n");

    for (int i = 0; i < koordinatSayisi / 2; i++) {
        xy_koordinatlar[i][0] = x_koordinatlari[i];
        xy_koordinatlar[i][1] = y_koordinatlari[i];
    }

    for (int i = 0; i < koordinatSayisi / 2; i++) {
        printf("Koordinat %d: x = %d, y = %d\n", i + 1, xy_koordinatlar[i][0], xy_koordinatlar[i][1]);
    }
    
    for (int i = 0; i < koordinatSayisi / 2; i++) {
        for (int j = i + 1; j < koordinatSayisi / 2; j++) {
            if (xy_koordinatlar[i][0] == xy_koordinatlar[j][0] && xy_koordinatlar[i][1] == xy_koordinatlar[j][1]) {
                printf("Koordinat %d ve Koordinat %d aynýdýr. (x = %d, y = %d)\n", i + 1, j + 1, xy_koordinatlar[i][0], xy_koordinatlar[i][1]);
                
            }
        }
	}
    
    
    
    sekilSayisi[sayac].sekil[0]=xy_koordinatlar[0][0];
    sekilSayisi[sayac].sekil[1]=xy_koordinatlar[0][1];
    
    for (int i = 0; i <=koordinatSayisi/2 ; i++) {
        
    int indis=0;	
    
    for ( j = i + 1; j < koordinatSayisi/2; j++) {
    	//printf("sayac %d\n",sayac);
    	if (xy_koordinatlar[i][0] == xy_koordinatlar[j][0] && xy_koordinatlar[i][1] == xy_koordinatlar[j][1]) {
    		sekilSayisi[sayac].sekil[j*2]=xy_koordinatlar[j][0];
    		sekilSayisi[sayac].sekil[j*2+1]=xy_koordinatlar[j][1];
			indis=j*2;
			if(xy_koordinatlar[j*2][0]==0 && xy_koordinatlar[j*2+1][1]==0)
				{
				sayac--;
				}
			sekilSayisi[sayac].konum=(j+1)*2;
				sayac++;
				break;
            }
    	sekilSayisi[sayac].sekil[j*2]=xy_koordinatlar[j][0];
    	sekilSayisi[sayac].sekil[j*2+1]=xy_koordinatlar[j][1];
    	
            
    	}
    
    }
    
      
    int kenarS1=sekilSayisi[0].konum;
 	int kenarS2=sekilSayisi[1].konum-sekilSayisi[0].konum;
 	int kenarS3=sekilSayisi[2].konum-sekilSayisi[1].konum;
 	if(kenarS2<0) kenarS2=0;
 	if(kenarS3<0) kenarS3=0;
 	printf("%d %d %d\n",kenarS1, kenarS2, kenarS3);
	 int sekil1[kenarS1];
 	int sekil2[kenarS2];
 	int sekil3[kenarS3];
    
    
    if(sayac>0){
	
    for(int i=0;i<kenarS1;i++)
       {
    	printf("%d ",sekilSayisi[0].sekil[i]);
		sekil1[i]=sekilSayisi[0].sekil[i];
	   }
	   printf("\n");
}
	if(sayac>1){
	
    for(int i=0;i<kenarS2;i++, j++)
       {
    	printf("%d ",sekilSayisi[1].sekil[j]);
		sekil2[i]=sekilSayisi[1].sekil[j];
	   }
	   	   printf("\n");
}
	if(sayac>2){
	
       for(int i=0;i<kenarS3;i++, j++)
       {
    	printf("%d ",sekilSayisi[2].sekil[j]);
		sekil3[i]=sekilSayisi[2].sekil[j];
	   }
}
 
 int kaynak_rezerv_degeri=0;
 int birim_sondaj_m=0, birim_platform_m;
 int grid_size;
 printf("Kare buyuklugunu giriniz(10 veya 15):");
 scanf("%d",&grid_size);
 while(1){
    printf("Birim sondaj maaliyetini giriniz(1-10 arasinda):");
    scanf("%d", &birim_sondaj_m);
    if(birim_sondaj_m>10) printf("10'dan buyuk olamaz.\n");
    else if(birim_sondaj_m<1) printf("1'den kucuk olamaz.\n");
    else break;
}
 
 int alan, kare_sayisi;
 
 printf("Birim platform maaliyetini giriniz:");
 scanf("%d", &birim_platform_m);
 initwindow(1000,1000);
 koordinat_duzlemi(grid_size);
 islemler(&alan, &kare_sayisi, kenarS1, sekil1, birim_sondaj_m, birim_platform_m, grid_size);
 printf("\nToplam Alan: %d\n", alan);
 printf("Kaynak Rezerv Degeri: %d\n", alan*10);
 printf("Sondaj Maaliyeti: %d\n", birim_sondaj_m*alan);
 printf("Platform Maaliyeti: %d\n", birim_platform_m*kare_sayisi);
 printf("Kar/Zarar: %d\n", alan*10-(birim_sondaj_m*alan)-(birim_platform_m*kare_sayisi));
 
 islemler(&alan, &kare_sayisi, kenarS2, sekil2, birim_sondaj_m, birim_platform_m, grid_size);
 printf("\nToplam Alan: %d\n", alan);
 printf("Kaynak Rezerv Degeri: %d\n", alan*10);
 printf("Sondaj Maaliyeti: %d\n", birim_sondaj_m*alan);
 printf("Platform Maaliyeti: %d\n", birim_platform_m*kare_sayisi);
 printf("Kar/Zarar: %d\n", alan*10-(birim_sondaj_m*alan)-(birim_platform_m*kare_sayisi));
 
 islemler(&alan, &kare_sayisi, kenarS3, sekil3, birim_sondaj_m, birim_platform_m, grid_size);
 printf("\nToplam Alan: %d\n", alan);
 printf("Kaynak Rezerv Degeri: %d\n", alan*10);
 printf("Sondaj Maaliyeti: %d\n", birim_sondaj_m*alan);
 printf("Platform Maaliyeti: %d\n", birim_platform_m*kare_sayisi);
 printf("Kar/Zarar: %d\n", alan*10-(birim_sondaj_m*alan)-(birim_platform_m*kare_sayisi));
 
 getch();
 closegraph();
 return 0;
}
