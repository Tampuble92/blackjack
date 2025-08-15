#include <stdio.h>
#include <stdlib.h>

int elhesaplama(int kart1,int kart2){
    if(kart1 > 11)
        kart1 = 10; // Face cards -> 10
    if(kart2 > 11)
        kart2 = 10; // Face cards -> 10
    int hand = kart1 + kart2;
    if(hand > 21) 
        if(kart1 == 11 || kart2 == 11) 
            hand -= 10; // Ace 11 -> 1
    if(hand < 11){
        if(kart1 == 1 || kart2 == 1) 
            hand += 10; // Ace 1 -> 11
    }
    return hand;
}

int kartcekme(int hand){
    int yenikart = 0;
    if(yenikart == 0){
        yenikart = rand() % 14 + 1; 
    }
    hand += yenikart;
    if(yenikart > 11) yenikart = 10; 
    if(yenikart == 1 && hand <= 10) yenikart = 11; 
    if(hand + yenikart > 21 && yenikart == 11) yenikart = 1;
    return hand;
}

int main()
{
    int kart1, kart2, kart3, kart4, secim;

    kart1 = rand() % 14 + 1;
    kart2 = rand() % 14 + 1;
    kart3 = rand() % 14 + 1;
    kart4 = rand() % 14 + 1;

    int toplam = elhesaplama(kart1, kart2);
    int kurpiyer = elhesaplama(kart3, kart4);
    if(kart1 > 11) kart1 = 10; // Face cards -> 10
    if(kart2 > 11) kart2 = 10; // Face cards -> 10
    if(kart3 > 11) kart3 = 10; // Face cards -> 10
    if(kart4 > 11) kart4 = 10; // Face cards -> 10 

    printf("Kartlariniz: %d %d Toplam: %d\n",kart1, kart2, elhesaplama(kart1, kart2));
    printf("Kurpiyerin Kartı: %d\n", kart3);

    printf("Yapmak istediginiz islemi seciniz:\n");
    while (1)
    { 
    printf("Kart çekmek için 1'e, durmak için 2'ye basın: ");
    scanf("%d", &secim);

    if(secim == 1){
        printf("Yeni Kart Cekiliyor...\n");
        toplam = kartcekme(toplam);
        printf("Yeni Toplam: %d\n", toplam);
        if(toplam > 21) {
            printf("Kaybettiniz! Toplam: %d\n", toplam);
            break; 
        }
    }

    else if(secim == 2){
        printf("Kurpiyerin eli: %d %d Toplam: %d\n", kart3, kart4, kurpiyer);
        printf("Kurpiyer kart cekiyor...\n");
        while(kurpiyer < 17){
            kurpiyer = kartcekme(kurpiyer);
            printf("Kurpiyerin Yeni Kart: %d Toplam: %d\n", kart3, kurpiyer);
        }
        break;
    }
    }
    if(kurpiyer > 21) {
        printf("Kazandiniz! Toplam: %d Kurpiyer: %d\n", toplam, kurpiyer);
    } else if(toplam < kurpiyer) {
        printf("Kaybettiniz! Toplam: %d Kurpiyer: %d\n", toplam, kurpiyer);
    } else if(toplam > kurpiyer) {
        printf("Kazandiniz! Toplam: %d Kurpiyer: %d\n", toplam, kurpiyer);
    } else {
        printf("Berabere! Toplam: %d Kurpiyer: %d\n", toplam, kurpiyer);
    }
}