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
typedef  int /*<<< orphan*/  u32 ;
struct scaler_context {int dummy; } ;
struct drm_exynos_ipp_task_rect {int /*<<< orphan*/  y; int /*<<< orphan*/  x; } ;

/* Variables and functions */
 int /*<<< orphan*/  SCALER_DST_POS ; 
 int /*<<< orphan*/  SCALER_DST_POS_SET_H_POS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SCALER_DST_POS_SET_V_POS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  scaler_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void scaler_set_dst_wh(struct scaler_context *scaler,
	struct drm_exynos_ipp_task_rect *dst_pos)
{
	u32 val;

	val = SCALER_DST_POS_SET_H_POS(dst_pos->x);
	val |= SCALER_DST_POS_SET_V_POS(dst_pos->y);
	scaler_write(val, SCALER_DST_POS);
}