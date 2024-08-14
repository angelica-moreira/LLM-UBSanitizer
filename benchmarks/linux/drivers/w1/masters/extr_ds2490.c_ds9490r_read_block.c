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
struct ds_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 int ds_read_block (struct ds_device*,int*,int) ; 
 int /*<<< orphan*/  kfree (int*) ; 
 int* kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 

__attribute__((used)) static u8 ds9490r_read_block(void *data, u8 *buf, int len)
{
	struct ds_device *dev = data;
	int err;
	u8 *tbuf;

	if (len <= 0)
		return 0;

	tbuf = kmalloc(len, GFP_KERNEL);
	if (!tbuf)
		return 0;

	err = ds_read_block(dev, tbuf, len);
	if (err >= 0)
		memcpy(buf, tbuf, len);

	kfree(tbuf);

	return err >= 0 ? len : 0;
}