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
struct afu {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SISL_INTVER_CAP_SQ_CMD_MODE ; 
 int afu_has_cap (struct afu*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline bool afu_is_sq_cmd_mode(struct afu *afu)
{
	return afu_has_cap(afu, SISL_INTVER_CAP_SQ_CMD_MODE);
}