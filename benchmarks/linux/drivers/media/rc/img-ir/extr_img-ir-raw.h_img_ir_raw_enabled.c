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
struct img_ir_priv_raw {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline bool img_ir_raw_enabled(struct img_ir_priv_raw *raw)
{
	return false;
}