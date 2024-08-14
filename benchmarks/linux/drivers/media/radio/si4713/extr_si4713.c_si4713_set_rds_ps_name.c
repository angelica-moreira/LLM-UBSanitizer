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
struct si4713_device {scalar_t__ power_state; } ;

/* Variables and functions */
 int DEFAULT_RDS_PS_REPEAT_COUNT ; 
 int MAX_RDS_PS_NAME ; 
 int RDS_BLOCK ; 
 int /*<<< orphan*/  SI4713_TX_RDS_PS_MESSAGE_COUNT ; 
 int /*<<< orphan*/  SI4713_TX_RDS_PS_REPEAT_COUNT ; 
 int /*<<< orphan*/  memset (char*,int /*<<< orphan*/ ,int) ; 
 int rds_ps_nblocks (int) ; 
 int si4713_tx_rds_ps (struct si4713_device*,int,char*) ; 
 int si4713_write_property (struct si4713_device*,int /*<<< orphan*/ ,int) ; 
 int strlen (char*) ; 

__attribute__((used)) static int si4713_set_rds_ps_name(struct si4713_device *sdev, char *ps_name)
{
	int rval = 0, i;
	u8 len = 0;

	/* We want to clear the whole thing */
	if (!strlen(ps_name))
		memset(ps_name, 0, MAX_RDS_PS_NAME + 1);

	if (sdev->power_state) {
		/* Write the new ps name and clear the padding */
		for (i = 0; i < MAX_RDS_PS_NAME; i += (RDS_BLOCK / 2)) {
			rval = si4713_tx_rds_ps(sdev, (i / (RDS_BLOCK / 2)),
						ps_name + i);
			if (rval < 0)
				return rval;
		}

		/* Setup the size to be sent */
		if (strlen(ps_name))
			len = strlen(ps_name) - 1;
		else
			len = 1;

		rval = si4713_write_property(sdev,
				SI4713_TX_RDS_PS_MESSAGE_COUNT,
				rds_ps_nblocks(len));
		if (rval < 0)
			return rval;

		rval = si4713_write_property(sdev,
				SI4713_TX_RDS_PS_REPEAT_COUNT,
				DEFAULT_RDS_PS_REPEAT_COUNT * 2);
		if (rval < 0)
			return rval;
	}

	return rval;
}