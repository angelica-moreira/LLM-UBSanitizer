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
 char* hex_byte_pack (char*,int /*<<< orphan*/ ) ; 

void qword_addhex(char **bpp, int *lp, char *buf, int blen)
{
	char *bp = *bpp;
	int len = *lp;

	if (len < 0) return;

	if (len > 2) {
		*bp++ = '\\';
		*bp++ = 'x';
		len -= 2;
		while (blen && len >= 2) {
			bp = hex_byte_pack(bp, *buf++);
			len -= 2;
			blen--;
		}
	}
	if (blen || len<1) len = -1;
	else {
		*bp++ = ' ';
		len--;
	}
	*bpp = bp;
	*lp = len;
}