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
typedef  int u8 ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 char* kstrdup (char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static char *ipaq_micro_str(u8 *wchar, u8 len)
{
	char retstr[256];
	u8 i;

	for (i = 0; i < len / 2; i++)
		retstr[i] = wchar[i * 2];
	return kstrdup(retstr, GFP_KERNEL);
}