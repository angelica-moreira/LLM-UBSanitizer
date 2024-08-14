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
struct vivid_dev {scalar_t__* input_type; size_t input; } ;

/* Variables and functions */
 scalar_t__ TV ; 

__attribute__((used)) static inline bool vivid_is_tv_cap(const struct vivid_dev *dev)
{
	return dev->input_type[dev->input] == TV;
}