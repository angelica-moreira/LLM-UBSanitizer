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
struct panel_drv_data {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  acx565akm_transfer (struct panel_drv_data*,int,int /*<<< orphan*/  const*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void acx565akm_write(struct panel_drv_data *ddata,
			       int reg, const u8 *buf, int len)
{
	acx565akm_transfer(ddata, reg, buf, len, NULL, 0);
}