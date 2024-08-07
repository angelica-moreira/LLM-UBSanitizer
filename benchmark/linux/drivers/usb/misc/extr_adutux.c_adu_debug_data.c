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
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  dev_dbg (struct device*,char*,char const*,int,int,unsigned char const*) ; 

__attribute__((used)) static inline void adu_debug_data(struct device *dev, const char *function,
				  int size, const unsigned char *data)
{
	dev_dbg(dev, "%s - length = %d, data = %*ph\n",
		function, size, size, data);
}