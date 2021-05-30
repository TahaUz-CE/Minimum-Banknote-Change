#include <SPI.h>        
#include <SD.h>         
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


File myFile;
int total = 3;
long SayiTut = 0;
int ParaAdedi[5];
int HizmetID[4];
char HizmetAd[4][15] = {"Kopukleme","Yikama","Kurulama","Cilalama"};
int KalanHizmetAdet[4];
int HizmetFiyat[4];

int a = 0;
int b = -1;
int e = -1;
int d = -1;
int f = -1;
int ka=0;



int buttonState = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;
int buttonState6 = 0;
int k=0,m=0;
int b_count[4]={0,0,0,0};
int b1_count[5]={0,0,0,0,0};


int MusteriPara=0;

int butonID[5]= {1,2,3,4,5};
int butonIslev[5]= {5,10,20,50,100};
int butonSecim=0;
int ParaYuklemeOnay=0,HizmetOnay=1;
int reset=0;
int temp_musteriPara;


int paraTakildi;

int kopukleme(int anaPara,int KalanHizmetAdet,int HizmetFiyat)
{

    if(anaPara-HizmetFiyat<0)
    {
        Serial.println("Yetersiz Bakiye");
        Serial.print("Hizmet Fiyat = ");
        Serial.print(HizmetFiyat);
        Serial.println();
        Serial.print("Guncel Bakiyeniz = ");
        Serial.print(anaPara);
        Serial.println();
        return anaPara;
    }
    if(KalanHizmetAdet == 0)
    {
        Serial.println("Hizmetimiz Tukenmistir");
        return anaPara;
    }

    Serial.println("Kopukleme Yapildi");
    Serial.print("Kalan Bakiye = ");
    Serial.print(anaPara-HizmetFiyat);
    Serial.println(" TL");
    return anaPara-HizmetFiyat;
}

int yikama(int anaPara,int KalanHizmetAdet,int HizmetFiyat)
{

    if(anaPara-HizmetFiyat<0)
    {
        Serial.println("Yetersiz Bakiye");
        Serial.print("Hizmet Fiyat = ");
        Serial.print(HizmetFiyat);
        Serial.println();
        Serial.print("Guncel Bakiyeniz = ");
        Serial.print(anaPara);
        Serial.println();
        return anaPara;
    }
    if(KalanHizmetAdet == 0)
    {
        Serial.println("Hizmetimiz Tukenmistir");
        return anaPara;
    }

    Serial.println("Yikama Yapildi");
    Serial.print("Kalan Bakiye = ");
    Serial.print(anaPara-HizmetFiyat);
    Serial.println(" TL");
    return anaPara-HizmetFiyat;
}

int kurulama(int anaPara,int KalanHizmetAdet,int HizmetFiyat)
{

    if(anaPara-HizmetFiyat<0)
    {
        Serial.println("Yetersiz Bakiye");
        Serial.print("Hizmet Fiyat = ");
        Serial.print(HizmetFiyat);
        Serial.println();
        Serial.print("Guncel Bakiyeniz = ");
        Serial.print(anaPara);
        Serial.println();
        return anaPara;
    }
    if(KalanHizmetAdet == 0)
    {
        Serial.println("Hizmetimiz Tukenmistir");
        return anaPara;
    }

    Serial.println("Kurulama Yapildi");
    Serial.print("Kalan Bakiye = ");
    Serial.print(anaPara-HizmetFiyat);
    Serial.println(" TL");
    return anaPara-HizmetFiyat;
}

int cilalama(int anaPara,int KalanHizmetAdet,int HizmetFiyat)
{

    if(anaPara-HizmetFiyat<0)
    {
        Serial.println("Yetersiz Bakiye");
        Serial.print("Hizmet Fiyat = ");
        Serial.print(HizmetFiyat);
        Serial.println();
        Serial.print("Guncel Bakiyeniz = ");
        Serial.print(anaPara);
        Serial.println();
        return anaPara;
    }
    if(KalanHizmetAdet == 0)
    {
        Serial.println("Hizmetimiz Tukenmistir");
        return anaPara;
    }

    Serial.println("Cilalama Yapildi");
    Serial.print("Kalan Bakiye = ");
    Serial.print(anaPara-HizmetFiyat);
    Serial.println(" TL");
    return anaPara-HizmetFiyat;
}

void setup() {
  
  Serial.begin(9600);

  while (!Serial) {
  
  }

  if (!SD.begin()) {

    while (1);
  }
  
  myFile = SD.open("test.txt");
  if (myFile) {


    int current = 0;
    while (myFile.available()) {
      char c = myFile.read(); 
      if (isdigit(c)) { 
        SayiTut *= 10; 
        SayiTut += (c - '0'); 
      } else if (c == ' ') { 


        if (a < 5 && b < 0) {
          ParaAdedi[a] = SayiTut;
          
          if (a < 4) {
            a++;
          }

          else {
            b = 0;

          }

        }
        
        else if (b > -1 && b < 4) {
         
          if (b == 0) {
            HizmetID[0] = SayiTut;
            
            b++;
          }
          else if (b == 1) {
            ka = SayiTut;
            
            b++;
          }
          else if (b == 2) {
            KalanHizmetAdet[0] = SayiTut;
            
            b++;
          }
          else if (b == 3) {
            HizmetFiyat[0] = SayiTut;
            
            b++;
            d=0;
            
          }
     
        }
       
        else if (d > -1 && d<4) {
         
          if (d == 0) {
            HizmetID[1] = SayiTut;
            
            d++;
          }
          else if (d == 1) {
            ka = SayiTut;
            
            d++;
          }
          else if (d == 2) {
            KalanHizmetAdet[1] = SayiTut;
            
            d++;
          }
          else if (d == 3) {
            HizmetFiyat[1] = SayiTut;
            
            e=0;
            d++;
          }
        }
        else if (e > -1 && e<4) {
         
          if (e == 0) {
            HizmetID[2] = SayiTut;
            
            e++;
          }
          else if (e == 1) {
            ka = SayiTut;
            
            e++;
          }
          else if (e == 2) {
            KalanHizmetAdet[2] = SayiTut;
            
            e++;
          }
          else if (e == 3) {
            HizmetFiyat[2] = SayiTut;
            
            f=0;
            e++;
          }
        }
        else if (f > -1 && f<4) {
         
          if (f == 0) {
            HizmetID[3] = SayiTut;
            
            f++;
          }
          else if (f == 1) {
            ka = SayiTut;
            
            f++;
          }
          else if (f == 2) {
            KalanHizmetAdet[3] = SayiTut;
            
            f++;
          }
          else if (f == 3) {
            HizmetFiyat[3] = SayiTut;
            
            f++;
          }
        }
          
        SayiTut = 0; 
      }
    }
    // close the file:
    myFile.close();
  } else {
    // eger dosya acilmazsa,hata vericektir:

  }
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(9, OUTPUT);
  pinMode(7,INPUT);
  pinMode(8, OUTPUT);
  
  srand(time(NULL));
}

void loop()
{
  
  buttonState=digitalRead(2);
  buttonState2=digitalRead(3);
  buttonState3=digitalRead(4);
  buttonState4=digitalRead(5);
  buttonState5=digitalRead(6);
  buttonState6=digitalRead(7);
  
  paraTakildi=rand() % 4 + 1;
  
  //paraTakildi=2;

  
  if(buttonState){
    butonSecim=1;
  }
  
  if(buttonState2){
    butonSecim=2;
  }
  
  if(buttonState3){
    butonSecim=3;
  }
  
  if(buttonState4){
    butonSecim=4;
  }
  
  if(buttonState5 == HIGH){
    digitalWrite(9,HIGH);
    butonSecim=5;
  }else{
    digitalWrite(9,LOW);
  }
  
  if(buttonState6 == HIGH){
    digitalWrite(8,HIGH);
    butonSecim=6;
  }else{
    digitalWrite(8,LOW);
  }
  
  delay(100);
  if(ParaYuklemeOnay != 1 && ParaYuklemeOnay != 2){
    if(k==0){
        for(int i=0;i<5;i++){
            
            Serial.print(butonIslev[i]);
            Serial.print(" TL = ");
            Serial.print(ParaAdedi[i]);
            Serial.println(" tane");
            
        }
      Serial.println("************************");
      Serial.println("OTO YIKAMAYA HOSGELDINIZ");
      Serial.println("************************");
      //Serial.println("Para Yukleme Islemini Gerceklestiriniz !");
      for(int i =0; i<5; i++)
      {
        Serial.print(butonID[i]);
        Serial.print(". Button : ");
        Serial.print(butonIslev[i]);
        Serial.print(" TL");
        Serial.println();
      }
      Serial.println("6. Button  Bitis");
      //Serial.println("Seceneklerden Birine Basiniz");
  
      k++;
    }
    if(butonSecim == 1)
    {
      MusteriPara += butonIslev[0];
      Serial.print(butonIslev[0]);
      Serial.print(" TL YUKLENDI");
      Serial.println();
        ParaAdedi[0]+=1;
        b1_count[0]++;
      butonSecim=0;
    }
    else if(butonSecim == 2)
    {
      MusteriPara += butonIslev[1];
      Serial.print(butonIslev[1]);
      Serial.print(" TL YUKLENDI");
      Serial.println();
        ParaAdedi[1]+=1;
        b1_count[1]++;
        butonSecim=0;
    }
    else if(butonSecim == 3)
    {
      MusteriPara += butonIslev[2];
      Serial.print(butonIslev[2]);
      Serial.print(" TL YUKLENDI");
      Serial.println();
        ParaAdedi[2]+=1;
        b1_count[2]++;
      butonSecim=0;
    }
    
    else if(butonSecim == 4)
    {
      MusteriPara += butonIslev[3];
      Serial.print(butonIslev[3]);
      Serial.print(" TL YUKLENDI");
      Serial.println();
        ParaAdedi[3]+=1;
        b1_count[3]++;
      butonSecim=0;
    }
    
    else if(butonSecim == 5)
    {
      MusteriPara += butonIslev[4];
      Serial.print(butonIslev[4]);
      Serial.print(" TL YUKLENDI");
      Serial.println();
        ParaAdedi[4]+=1;
        b1_count[4]++;
      butonSecim=0;
    }
    
    else if(butonSecim == 6)
    {
      ParaYuklemeOnay=1;
      Serial.println("Para Yukleme Tamamlandi .");
      butonSecim=0;
        HizmetOnay=0;
        temp_musteriPara = MusteriPara;
    }
    
    if(ParaYuklemeOnay == 1){
      Serial.print("Yuklenen Miktar = ");
      Serial.print(MusteriPara);
      Serial.print(" TL");
      Serial.println();
      ParaYuklemeOnay+=1;
    }
  }
  
  if(HizmetOnay != 1 && HizmetOnay != 2){
    if(m==0){
      Serial.println("*******************");
      Serial.println("Hizmet Islemleri");
      Serial.println("*******************");
        
        for(int i =0; i<4; i++)
      {
            Serial.print(HizmetID[i]);
            Serial.print("-)");
            Serial.print(HizmetAd[i]);
            Serial.print(" -->");
            Serial.print(" Hizmet Adeti ");
            Serial.print(KalanHizmetAdet[i]);
            Serial.print(" -->");
            Serial.print(" Hizmet Fiyati ");
            Serial.print(HizmetFiyat[i]);
            Serial.print(" TL");
          Serial.println();
      }
      
        for(int i =0; i<4; i++)
      {
        Serial.print(butonID[i]);
        Serial.print(". Button : ");
        Serial.print(HizmetAd[i]);
        Serial.println();
      }
      Serial.println("5. Button  Bitis");
      Serial.println("6. Button  Reset");
      //Serial.println("Seceneklerden Birine Basiniz");
  
      m++;
    }
    
    if(butonSecim == 1)
    {
      MusteriPara = kopukleme(MusteriPara,KalanHizmetAdet[0],HizmetFiyat[0]);
        if(KalanHizmetAdet[0]>0){
          KalanHizmetAdet[0] -= 1;
            b_count[0]++;
        }
      butonSecim=0;
    }
    else if(butonSecim == 2)
    {
      MusteriPara = yikama(MusteriPara,KalanHizmetAdet[1],HizmetFiyat[1]);
        if(KalanHizmetAdet[1]>0){
          KalanHizmetAdet[1] -= 1;
            b_count[1]++;
        }
      butonSecim=0;
    }
    else if(butonSecim == 3)
    {
      MusteriPara = kurulama(MusteriPara,KalanHizmetAdet[2],HizmetFiyat[2]);
        if(KalanHizmetAdet[2]>0){
          KalanHizmetAdet[2] -= 1;
            b_count[2]++;
        }
      butonSecim=0;
      
    }
    
    else if(butonSecim == 4)
    {
      MusteriPara = cilalama(MusteriPara,KalanHizmetAdet[3],HizmetFiyat[3]);
        if(KalanHizmetAdet[3]>0){
          KalanHizmetAdet[3] -= 1;
            b_count[3]++;
        }
      butonSecim=0;
    }
    
    else if(butonSecim == 5)
    {
      HizmetOnay=1;
      butonSecim=0;
      if(paraTakildi == 2){
        Serial.println("Hizmetler Iptal Edildi.");
        delay(4000);
        digitalWrite(9,HIGH);
        digitalWrite(8,HIGH);
        delay(8000);
        digitalWrite(9,LOW);
        digitalWrite(8,LOW);
        
        for(int i =0; i<4; i++)
      {
        KalanHizmetAdet[i]+=b_count[i];
      }
        
        HizmetOnay = 2;
        ParaYuklemeOnay = 2;
        
      }else{
        Serial.println("Hizmet Tamamlandi");
        HizmetOnay = 2;
        ParaYuklemeOnay = 2;
      }
    }
    
    else if(butonSecim == 6)
    {
        Serial.println("Secimler Iptal Ediliyor . ");
        butonSecim=0;
        ParaYuklemeOnay=1;
        HizmetOnay=0;
        MusteriPara=temp_musteriPara;
        for(int i =0; i<4; i++)
      {
        KalanHizmetAdet[i]+=b_count[i];
      }
        
        reset=1;
        k=0;
        m=0;
        for(int i =0; i<4; i++)
      {
        b_count[i]=0;
      }
        
        delay(100);
      
    }
    
    if(HizmetOnay == 1 && reset != 1){
      Serial.print("Kalan Para miktari = ");
      Serial.print(MusteriPara);
      Serial.print(" TL");
      Serial.println();
      HizmetOnay+=1;
        
    }
    reset=0;
  }
  
  if(HizmetOnay == 2 && ParaYuklemeOnay == 2){
    
    int kullanici_degeri, kullanici_degeri_yedek, beslik=0, onluk=0, yirmilik=0, ellilik=0,yuzluk=0;
    if(paraTakildi == 2){
      kullanici_degeri = temp_musteriPara;
        Serial.println("Para Takildi");
        delay(1500);
        Serial.print(temp_musteriPara);
        Serial.println(" TL Iade Edilicek.");
        delay(3000);
    }else{
      kullanici_degeri = MusteriPara;
    }

    kullanici_degeri_yedek = kullanici_degeri;
  
    yuzluk = kullanici_degeri / 100;
    if(yuzluk > 0){
      if(ParaAdedi[4]<=yuzluk){
        kullanici_degeri-=(ParaAdedi[4]*100);
        yuzluk=ParaAdedi[4];
        ParaAdedi[4]=0;
      }else{
        kullanici_degeri-=(yuzluk*100);
        ParaAdedi[4]-=yuzluk;
      }
    }
    
    ellilik = kullanici_degeri / 50;
    if(ellilik > 0){
      if(ParaAdedi[3]<=ellilik){
        kullanici_degeri-=(ParaAdedi[3]*50);
        ellilik=ParaAdedi[3];
        ParaAdedi[3]=0;
      }else{
        kullanici_degeri-=(ellilik*50);
        ParaAdedi[3]-=ellilik;
      }
    }
    
    yirmilik = kullanici_degeri / 20;
    if(yirmilik > 0){
      if(ParaAdedi[2]<=yirmilik){
        kullanici_degeri-=(ParaAdedi[2]*20);
        yirmilik=ParaAdedi[2];
        ParaAdedi[2]=0;
      }else{
        kullanici_degeri-=(yirmilik*20);
        ParaAdedi[2]-=yirmilik;
      }
    }

    onluk = kullanici_degeri / 10;
    if(onluk > 0){
      if(ParaAdedi[1]<=onluk){
        kullanici_degeri-=(ParaAdedi[1]*10);
        onluk=ParaAdedi[1];
        ParaAdedi[1]=0;
      }else{
        kullanici_degeri-=(onluk*10);
        ParaAdedi[1]-=onluk;
      }
    }
    
    beslik = kullanici_degeri / 5;
    if(beslik > 0){
      if(ParaAdedi[0]<=beslik){
        kullanici_degeri-=(ParaAdedi[0]*5);
        beslik=ParaAdedi[0];
        ParaAdedi[0]=0;
      }else{
        kullanici_degeri-=(beslik*5);
        ParaAdedi[0]-=beslik;
      }
    }

    if(paraTakildi == 2){
      Serial.print("Iade tutar ");
    }else{
      Serial.print("Para ustunuz  ");
    }
    
    if(yuzluk != 0){
        Serial.print(yuzluk);
        Serial.print(" adet 100 TL ");
    }
    if(ellilik != 0){
        Serial.print(ellilik);
        Serial.print(" adet 50 TL ");
    }
    if(yirmilik != 0){
        Serial.print(yirmilik);
        Serial.print(" adet 20 TL ");
    }
    if(onluk != 0){
        Serial.print(onluk);
        Serial.print(" adet 10 TL ");
    }
    if(beslik != 0){
        Serial.print(beslik);
        Serial.print(" adet 5 TL ");
    }
    if(MusteriPara == 0){
      Serial.print("0");
    }
    Serial.print("' dir .");
    
    Serial.println();
    
    if(kullanici_degeri>0){
        Serial.print("Kasada yeterli para yok.");
        Serial.println();
        Serial.print("Size ");
        Serial.print(kullanici_degeri);
        Serial.println(" TL borcumuz var.");
    }
    
    Serial.println("Yine Bekleriz ! ");
    delay(400);
    
    butonSecim=0;
    MusteriPara=0;
    ParaYuklemeOnay=0;
    HizmetOnay=1; 
    reset=1;
    k=0;
    m=0;
    for(int i =0; i<4; i++)
    {
      b_count[i]=0;
    }
    for(int i =0; i<5; i++)
    {
      b1_count[i]=0;
    }
    
    delay(8000);
  }
  
  delay(100);
}
