/*
 * RC4.c
 *
 *  Created on: Jul 3, 2024
 *      Author: Mohamed Hamada
 */

#include "RC4.h"

static void swap(uint8_t* item1,uint8_t* item2);
void RC4_init(uint8_t *s,uint8_t* key,uint8_t length)
{
    for(uint16_t i =0;i<=255;i++)
    {
        s[i]=i;
    }

    uint8_t t[256];
    for(uint16_t i =0;i<256;i++)
    {
        t[i] = key[i % length];
    }
    uint8_t j =0;
    for (uint16_t i = 0; i < 256; i++)
    {
        j = (j + s[i] + t[i])%256;
        swap(&s[i],&s[j]);
    }



}
void RC4_encrypt(uint8_t* s,uint8_t* message , uint8_t* encryptedMessage,uint8_t length)
{
int j=0;
uint8_t t=0;
uint8_t k =0;
for (uint16_t i = 0; i < length; i++)
{
    j = (j+i)%256;
    t = (s[i]+s[j])%256;
    swap(&s[i],&s[j]);
    k = s[t];
    encryptedMessage[i] = message[i]^k;

}
}

void RC4_decrypt(uint8_t* s,uint8_t* message , uint8_t* decryptedMessage,uint8_t length)
{
int j=0;
uint8_t t=0;
uint8_t k =0;
for (uint16_t i = 0; i < length; i++)
{
    j = (j+i)%256;
    t = (s[i]+s[j])%256;
    swap(&s[i],&s[j]);
    k = s[t];
    decryptedMessage[i] = message[i]^k;

}
}

static void swap(uint8_t* item1,uint8_t* item2)
{
    int temp = *item1;
    *item1   = *item2;
    *item2   = temp;
}



