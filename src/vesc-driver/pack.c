#include "pack.h"

uint8_t unpack_payload(uint8_t* message, int lenMes, uint8_t* payload, int lenPay)
{
	uint8_t buffer[256];
	read(vesc_fd, buffer, 256);
	return 0;
	/*
	printf("%s", buffer);

	uint16_t crcMessage = 0;
	uint16_t crcPayload = 0;
	//Rebuild src:
	crcMessage = message[lenMes - 3] << 8;
	crcMessage &= 0xFF00;
	crcMessage += message[lenMes - 2];
	#ifdef DEBUG
	debugSerialPort->print("SRC received: "); debugSerialPort->println(crcMessage);
	#endif

	//Extract payload:
	memcpy(payload, &message[2], message[1]);

	crcPayload = crc16(payload, message[1]);

	#ifdef DEBUG
	debugSerialPort->print("SRC calc: "); debugSerialPort->println(crcPayload);
	#endif

	if(crcPayload == crcMessage)
	{
		#ifdef DEBUG
		debugSerialPort->print("Received: "); SerialPrint(message, lenMes); debugSerialPort->println();
		//debugSerialPort->print("Payload :      "); SerialPrint(payload, message[1] - 1); debugSerialPort->println();
		#endif
		return true;
	}
	else return false;
	*/
}

int pack_send_payload(uint8_t* payload, int lenPay)
{
	uint16_t crcPayload = crc16(payload, lenPay);
	int count = 0;
	uint8_t messageSend[256];

	if (lenPay <= 256)
	{
		messageSend[count++] = 2;
		messageSend[count++] = lenPay;
	}
	else
	{
		messageSend[count++] = 3;
		messageSend[count++] = (uint8_t)(lenPay >> 8);
		messageSend[count++] = (uint8_t)(lenPay & 0xFF);
	}
	memcpy(&messageSend[count], payload, lenPay);

	count += lenPay;
	messageSend[count++] = (uint8_t)(crcPayload >> 8);
	messageSend[count++] = (uint8_t)(crcPayload & 0xFF);
	messageSend[count++] = 3;
	messageSend[count] = 0;

	//Sending package
	if(vesc_fd) return write(vesc_fd, messageSend, count);
}