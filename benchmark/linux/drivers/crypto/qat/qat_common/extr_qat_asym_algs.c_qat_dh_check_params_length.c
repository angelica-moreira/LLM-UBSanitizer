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
 int EINVAL ; 

__attribute__((used)) static int qat_dh_check_params_length(unsigned int p_len)
{
	switch (p_len) {
	case 1536:
	case 2048:
	case 3072:
	case 4096:
		return 0;
	}
	return -EINVAL;
}