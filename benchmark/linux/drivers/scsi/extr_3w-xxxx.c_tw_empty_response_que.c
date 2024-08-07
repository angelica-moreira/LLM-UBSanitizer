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
typedef  int u32 ;
typedef  int /*<<< orphan*/  TW_Device_Extension ;

/* Variables and functions */
 int /*<<< orphan*/  TW_RESPONSE_QUEUE_REG_ADDR (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TW_STATUS_REG_ADDR (int /*<<< orphan*/ *) ; 
 int TW_STATUS_RESPONSE_QUEUE_EMPTY ; 
 int inl (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void tw_empty_response_que(TW_Device_Extension *tw_dev) 
{
	u32 status_reg_value, response_que_value;

	status_reg_value = inl(TW_STATUS_REG_ADDR(tw_dev));

	while ((status_reg_value & TW_STATUS_RESPONSE_QUEUE_EMPTY) == 0) {
		response_que_value = inl(TW_RESPONSE_QUEUE_REG_ADDR(tw_dev));
		status_reg_value = inl(TW_STATUS_REG_ADDR(tw_dev));
	}
}