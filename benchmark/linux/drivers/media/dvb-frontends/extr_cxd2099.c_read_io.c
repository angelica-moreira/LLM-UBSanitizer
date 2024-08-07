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
typedef  int u16 ;
struct cxd {int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 int regmap_raw_write (int /*<<< orphan*/ ,int,int*,int) ; 
 int regmap_read (int /*<<< orphan*/ ,int,unsigned int*) ; 

__attribute__((used)) static int read_io(struct cxd *ci, u16 address, unsigned int *val)
{
	int status;
	u8 addr[2] = {address & 0xff, address >> 8};

	status = regmap_raw_write(ci->regmap, 2, addr, 2);
	if (!status)
		status = regmap_read(ci->regmap, 3, val);
	return status;
}