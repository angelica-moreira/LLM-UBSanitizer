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
struct counter_device {int dummy; } ;
struct counter_count {int dummy; } ;

/* Variables and functions */
 size_t FTM_QUADDEC_COUNT_ENCODER_MODE_1 ; 

__attribute__((used)) static int ftm_quaddec_count_function_get(struct counter_device *counter,
					  struct counter_count *count,
					  size_t *function)
{
	*function = FTM_QUADDEC_COUNT_ENCODER_MODE_1;

	return 0;
}