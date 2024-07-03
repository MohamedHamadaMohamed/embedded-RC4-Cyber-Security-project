/*
 * RC4.h
 *
 *  Created on: Jul 3, 2024
 *      Author: Moham
 */

#ifndef INC_RC4_H_
#define INC_RC4_H_

#include "stdint.h"

void RC4_init(uint8_t *s,uint8_t* key,uint8_t length);
void RC4_encrypt(uint8_t* s,uint8_t* message , uint8_t* encryptedMessage,uint8_t length);

#endif /* INC_RC4_H_ */
