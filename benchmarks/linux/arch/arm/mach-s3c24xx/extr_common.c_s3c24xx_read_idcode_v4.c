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
 int /*<<< orphan*/  S3C2410_GSTATUS1 ; 
 unsigned long __raw_readl (int /*<<< orphan*/ ) ; 

__attribute__((used)) static unsigned long s3c24xx_read_idcode_v4(void)
{
	return __raw_readl(S3C2410_GSTATUS1);
}