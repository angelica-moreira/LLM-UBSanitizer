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
typedef  int /*<<< orphan*/  drm_via_private_t ;

/* Variables and functions */
 int /*<<< orphan*/  HC_HAGPBpID_PAUSE ; 
 int /*<<< orphan*/  via_cmdbuf_flush (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void via_cmdbuf_pause(drm_via_private_t *dev_priv)
{
	via_cmdbuf_flush(dev_priv, HC_HAGPBpID_PAUSE);
}