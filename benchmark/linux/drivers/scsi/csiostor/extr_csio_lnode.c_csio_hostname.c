#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
struct TYPE_2__ {char* nodename; } ;

/* Variables and functions */
 TYPE_1__* init_utsname () ; 
 scalar_t__ snprintf (int /*<<< orphan*/ *,size_t,char*,char*) ; 

__attribute__((used)) static int
csio_hostname(uint8_t *buf, size_t buf_len)
{
	if (snprintf(buf, buf_len, "%s", init_utsname()->nodename) > 0)
		return 0;
	return -1;
}