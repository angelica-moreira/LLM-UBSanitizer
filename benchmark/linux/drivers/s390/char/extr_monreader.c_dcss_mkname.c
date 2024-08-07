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
 int /*<<< orphan*/  ASCEBC (char*,int) ; 
 char toupper (char) ; 

__attribute__((used)) static void dcss_mkname(char *ascii_name, char *ebcdic_name)
{
	int i;

	for (i = 0; i < 8; i++) {
		if (ascii_name[i] == '\0')
			break;
		ebcdic_name[i] = toupper(ascii_name[i]);
	}
	for (; i < 8; i++)
		ebcdic_name[i] = ' ';
	ASCEBC(ebcdic_name, 8);
}