#ifndef VESC_H_
#define VESC_H_

#include <errno.h>
#include <fcntl.h> 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <termios.h>

typedef float float16;
typedef float float32;

extern int vesc_fd;

extern struct vesc_version vesc_version;

extern struct vesc_values vesc_values;

int vesc_connect(char* port);
int vesc_disconnect();

#endif /* VESC_H_ */