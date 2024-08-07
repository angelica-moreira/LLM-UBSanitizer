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
struct drm_i915_private {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  I915_WRITE (int /*<<< orphan*/ ,int) ; 
 int MBUS_ABOX_BT_CREDIT_POOL1 (int) ; 
 int MBUS_ABOX_BT_CREDIT_POOL2 (int) ; 
 int MBUS_ABOX_BW_CREDIT (int) ; 
 int MBUS_ABOX_B_CREDIT (int) ; 
 int /*<<< orphan*/  MBUS_ABOX_CTL ; 

__attribute__((used)) static void icl_mbus_init(struct drm_i915_private *dev_priv)
{
	u32 val;

	val = MBUS_ABOX_BT_CREDIT_POOL1(16) |
	      MBUS_ABOX_BT_CREDIT_POOL2(16) |
	      MBUS_ABOX_B_CREDIT(1) |
	      MBUS_ABOX_BW_CREDIT(1);

	I915_WRITE(MBUS_ABOX_CTL, val);
}