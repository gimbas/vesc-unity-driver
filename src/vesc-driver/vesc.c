#include "vesc.h"

int vesc_fd;

struct vesc_version
{
    uint8_t fwMajor;
    uint8_t fwMinor;
    uint8_t* hwName;
    uint8_t stm32_uuid[12];
} vesc_version;

struct vesc_values
{
    float16 temp_fet; 
    float16 temp_fet2;
    float16 temp_motor;
    float16 temp_motor2;
    float32 avg_motor_current;
    float32 avg_motor_current2;
    float32 avg_input_current;
    float32 avg_id;
    float32 avg_id2;
    float32 avg_iq;
    float32 avg_iq2;
    float16 duty_cycle;
    float16 duty_cycle2;
    float32 rpm;
    float32 rpm2;
    float16 voltage;
    float32 amp_hours;
    float32 amp_hours_charged;
    float32 watt_hours;
    float32 watt_hours_charged;
    int32_t tachometer_value;
    int32_t tachometer_value2;
    int32_t tachometer_abs_value;
    int32_t tachometer_abs_value2;
    uint8_t fault;
} vesc_values;

int set_interface_attribs(int fd, int speed)
{
    struct termios tty;

    if (tcgetattr(fd, &tty) < 0) {
        printf("Error from tcgetattr: %s\n", strerror(errno));
        return -1;
    }

    cfsetospeed(&tty, (speed_t)speed);
    cfsetispeed(&tty, (speed_t)speed);

    tty.c_cflag |= (CLOCAL | CREAD);    /* ignore modem controls */
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;         /* 8-bit characters */
    tty.c_cflag &= ~PARENB;     /* no parity bit */
    tty.c_cflag &= ~CSTOPB;     /* only need 1 stop bit */
    tty.c_cflag &= ~CRTSCTS;    /* no hardware flowcontrol */

    /* setup for non-canonical mode */
    tty.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON);
    tty.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
    tty.c_oflag &= ~OPOST;

    /* fetch bytes as they become available */
    tty.c_cc[VMIN] = 1;
    tty.c_cc[VTIME] = 1;

    if (tcsetattr(fd, TCSANOW, &tty) != 0) {
        printf("Error from tcsetattr: %s\n", strerror(errno));
        return -1;
    }
    return 0;
}

void set_mincount(int fd, int mcount)
{
    struct termios tty;

    if (tcgetattr(fd, &tty) < 0) {
        printf("Error tcgetattr: %s\n", strerror(errno));
        return;
    }

    tty.c_cc[VMIN] = mcount ? 1 : 0;
    tty.c_cc[VTIME] = 5;        /* half second timer */

    if (tcsetattr(fd, TCSANOW, &tty) < 0)
        printf("Error tcsetattr: %s\n", strerror(errno));
}

int vesc_connect(char* port)
{
    vesc_fd = open(port, O_RDWR | O_NOCTTY | O_SYNC);
    if(vesc_fd < 0)
    {
        printf("Error opening %s: %s\n", port, strerror(errno));
        return -1;
    }

    return 0;
    /*baudrate 115200, 8 bits, no parity, 1 stop bit */
    //set_interface_attribs(fd, B115200);
    //set_mincount(fd, 0);                /* set to pure timed read */
}

int vesc_disconnect()
{
    close(vesc_fd);
}