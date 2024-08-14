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
struct hdsp {int dummy; } ;

/* Variables and functions */
 int HDSP_TimecodeLock ; 
 int HDSP_TimecodeSync ; 
 int /*<<< orphan*/  HDSP_statusRegister ; 
 int hdsp_read (struct hdsp*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int hdsp_adatsync_sync_check(struct hdsp *hdsp)
{
	int status = hdsp_read(hdsp, HDSP_statusRegister);
	if (status & HDSP_TimecodeLock) {
		if (status & HDSP_TimecodeSync)
			return 2;
		else
			return 1;
	} else
		return 0;
}