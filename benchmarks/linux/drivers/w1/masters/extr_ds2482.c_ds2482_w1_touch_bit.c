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
struct ds2482_w1_chan {int /*<<< orphan*/  channel; struct ds2482_data* pdev; } ;
struct ds2482_data {int w1_count; int /*<<< orphan*/  access_lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  DS2482_CMD_1WIRE_SINGLE_BIT ; 
 int DS2482_REG_STS_SBR ; 
 int /*<<< orphan*/  ds2482_send_cmd_data (struct ds2482_data*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ds2482_set_channel (struct ds2482_data*,int /*<<< orphan*/ ) ; 
 int ds2482_wait_1wire_idle (struct ds2482_data*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static u8 ds2482_w1_touch_bit(void *data, u8 bit)
{
	struct ds2482_w1_chan *pchan = data;
	struct ds2482_data    *pdev = pchan->pdev;
	int status = -1;

	mutex_lock(&pdev->access_lock);

	/* Select the channel */
	ds2482_wait_1wire_idle(pdev);
	if (pdev->w1_count > 1)
		ds2482_set_channel(pdev, pchan->channel);

	/* Send the touch command, wait until 1WB == 0, return the status */
	if (!ds2482_send_cmd_data(pdev, DS2482_CMD_1WIRE_SINGLE_BIT,
				  bit ? 0xFF : 0))
		status = ds2482_wait_1wire_idle(pdev);

	mutex_unlock(&pdev->access_lock);

	return (status & DS2482_REG_STS_SBR) ? 1 : 0;
}