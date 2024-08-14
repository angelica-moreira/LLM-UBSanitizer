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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;

/* Variables and functions */
 int /*<<< orphan*/  drm_hdcp_be24_to_cpu (int /*<<< orphan*/  const*) ; 

__attribute__((used)) static inline u32 get_vrl_length(const u8 *buf)
{
	return drm_hdcp_be24_to_cpu(buf);
}