#include <sys/ioctl.h>
#include <errno.h>                                                              
#include <string.h>                                                             
#include <stdio.h>                                                              
#include <stdlib.h>                                                             
#include <unistd.h>                                                             
#include <fcntl.h>                                                              
#include <time.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>




int main ()
{
	char buf[2]={0x0,0x0};
	int file;
	
	struct i2c_msg msg[2];
		
	struct I2C_2BYTE struc;

	struc.offset = 0x50;

	file = open("/dev/i2c-0", O_RDWR);
	if (file < 0) {
		printf("Error open /dev/i2c-0\n");
		exit(1);
	}

	
	unlocked_ioctl(file, I2C_2BYTERD, &struc);
	printf("my buffer:%d, %d\n", buf[0], buf[1]);

	return 0;
}
