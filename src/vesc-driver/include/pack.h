#ifndef PACK_H_
#define PACK_H_

#include <errno.h>
#include <fcntl.h> 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "crc.h"
#include "vesc.h"

uint8_t unpack_payload(uint8_t* message, int lenMes, uint8_t* payload, int lenPay);
int pack_send_payload(uint8_t* payload, int lenPay);

#endif /* PACK_H_ */