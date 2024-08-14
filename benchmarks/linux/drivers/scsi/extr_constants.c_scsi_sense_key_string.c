#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */

/* Variables and functions */
 unsigned char ARRAY_SIZE (char const**) ; 
 char const** snstext ; 

const char *
scsi_sense_key_string(unsigned char key)
{
	if (key < ARRAY_SIZE(snstext))
		return snstext[key];
	return NULL;
}