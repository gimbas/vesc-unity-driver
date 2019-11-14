#include "commands.h"

void unity_set_current(float current1, float current2)
{
	int32_t index = 0;
    uint8_t payload[9];

    payload[index++] = COMM_SET_CURRENT ;
    buffer_append_int32(payload, (int32_t)(current1 * 1000), &index);
    buffer_append_int32(payload, (int32_t)(current2 * 1000), &index);
    pack_send_payload(payload, 9);
}
void unity_set_position(float position1, float position2) {
	int32_t index = 0;
	uint8_t payload[9];

	payload[index++] = COMM_SET_POS ;
	buffer_append_int32(payload, (int32_t)(position1 * 1000000.0), &index);
    buffer_append_int32(payload, (int32_t)(position2 * 1000000.0), &index);
	pack_send_payload(payload, 9);
}
void unity_set_duty(float duty1, float duty2) {
	int32_t index = 0;
	uint8_t payload[9];

	payload[index++] = COMM_SET_DUTY ;
	buffer_append_int32(payload, (int32_t)(duty1 * 100000), &index);
    buffer_append_int32(payload, (int32_t)(duty2 * 100000), &index);
	pack_send_payload(payload, 9);
}
void unity_set_rpm(float rpm1, float rpm2) {
	int32_t index = 0;
	uint8_t payload[9];

	payload[index++] = COMM_SET_RPM ;
	buffer_append_int32(payload, (int32_t)(rpm1), &index);
    buffer_append_int32(payload, (int32_t)(rpm2), &index);
	pack_send_payload(payload, 9);
}
void unity_set_currentBrake(float brakeCurrent1, float brakeCurrent2) {
	int32_t index = 0;
	uint8_t payload[9];

	payload[index++] = COMM_SET_CURRENT_BRAKE;
	buffer_append_int32(payload, (int32_t)(brakeCurrent1 * 1000), &index);
	buffer_append_int32(payload, (int32_t)(brakeCurrent2 * 1000), &index);
	pack_send_payload(payload, 9);
}

