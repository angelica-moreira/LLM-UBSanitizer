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
#define  FLASH_AUTH 133 
#define  FLASH_IMG_BAD_LEN 132 
#define  FLASH_IMG_NULL_DATA 131 
#define  FLASH_IMG_READY 130 
#define  FLASH_IMG_SHORT 129 
#define  FLASH_NO_OP 128 
 int /*<<< orphan*/  memcpy (char*,char const*,size_t) ; 
 size_t sprintf (char*,char*,int) ; 
 size_t strlen (char const*) ; 

__attribute__((used)) static size_t get_flash_status_msg(int status, char *buf)
{
	const char *msg;
	size_t len;

	switch (status) {
	case FLASH_AUTH:
		msg = "error: this partition does not have service authority\n";
		break;
	case FLASH_NO_OP:
		msg = "info: no firmware image for flash\n";
		break;
	case FLASH_IMG_SHORT:
		msg = "error: flash image short\n";
		break;
	case FLASH_IMG_BAD_LEN:
		msg = "error: internal error bad length\n";
		break;
	case FLASH_IMG_NULL_DATA:
		msg = "error: internal error null data\n";
		break;
	case FLASH_IMG_READY:
		msg = "ready: firmware image ready for flash on reboot\n";
		break;
	default:
		return sprintf(buf, "error: unexpected status value %d\n",
			       status);
	}

	len = strlen(msg);
	memcpy(buf, msg, len + 1);
	return len;
}