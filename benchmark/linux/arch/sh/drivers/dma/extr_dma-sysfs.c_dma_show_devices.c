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
struct dma_info {char* name; } ;
struct dma_channel {int chan; char* dev_id; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 struct dma_channel* get_dma_channel (int) ; 
 struct dma_info* get_dma_info (int) ; 
 int sprintf (char*,char*,int,char*,char*) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static ssize_t dma_show_devices(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	ssize_t len = 0;
	int i;

	for (i = 0; i < 16; i++) {
		struct dma_info *info = get_dma_info(i);
		struct dma_channel *channel = get_dma_channel(i);

		if (unlikely(!info) || !channel)
			continue;

		len += sprintf(buf + len, "%2d: %14s    %s\n",
			       channel->chan, info->name,
			       channel->dev_id);
	}

	return len;
}