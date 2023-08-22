#include "main.h"
#include <stdio.h>

/**
  * init_buffer - initiates a buffer
  * @buff_size: buffer size
  */
void init_buffer(char *buff_size[])
{
	int b;

	for (b = 0; b < 1024; b++)
	{
		buff_size[b] = 0;
	}
	buff_size[b] = '\0';
}
