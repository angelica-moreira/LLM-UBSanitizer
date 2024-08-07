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
struct st7701 {int /*<<< orphan*/  dsi; } ;

/* Variables and functions */
 int mipi_dsi_dcs_write_buffer (int /*<<< orphan*/ ,void const*,size_t) ; 

__attribute__((used)) static inline int st7701_dsi_write(struct st7701 *st7701, const void *seq,
				   size_t len)
{
	return mipi_dsi_dcs_write_buffer(st7701->dsi, seq, len);
}