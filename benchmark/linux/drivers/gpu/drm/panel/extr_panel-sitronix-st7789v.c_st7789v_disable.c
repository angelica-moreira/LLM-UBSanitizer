#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct st7789v {TYPE_2__* backlight; } ;
struct drm_panel {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  state; int /*<<< orphan*/  power; } ;
struct TYPE_4__ {TYPE_1__ props; } ;

/* Variables and functions */
 int /*<<< orphan*/  BL_CORE_FBBLANK ; 
 int /*<<< orphan*/  FB_BLANK_POWERDOWN ; 
 int /*<<< orphan*/  MIPI_DCS_SET_DISPLAY_OFF ; 
 int /*<<< orphan*/  ST7789V_TEST (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  backlight_update_status (TYPE_2__*) ; 
 struct st7789v* panel_to_st7789v (struct drm_panel*) ; 
 int /*<<< orphan*/  st7789v_write_command (struct st7789v*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int st7789v_disable(struct drm_panel *panel)
{
	struct st7789v *ctx = panel_to_st7789v(panel);
	int ret;

	ST7789V_TEST(ret, st7789v_write_command(ctx, MIPI_DCS_SET_DISPLAY_OFF));

	if (ctx->backlight) {
		ctx->backlight->props.power = FB_BLANK_POWERDOWN;
		ctx->backlight->props.state |= BL_CORE_FBBLANK;
		backlight_update_status(ctx->backlight);
	}

	return 0;
}