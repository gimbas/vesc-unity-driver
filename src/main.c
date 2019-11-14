#include <errno.h>
#include <fcntl.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#include "commands.h"
#include "vesc.h"



int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    vesc_connect("/dev/ttyACM0");

    /* simple output */
    int repeat = 1;
    
    while(repeat--)
    {
        unity_set_current(2, 0);
        sleep(1);
        unity_set_current(0, 2);
        sleep(1);
        unity_set_current(0, 0);
        sleep(1);
        unity_set_current(2, 2);
        sleep(1);
    }
    unity_set_current(0, 0);

    vesc_disconnect();
}