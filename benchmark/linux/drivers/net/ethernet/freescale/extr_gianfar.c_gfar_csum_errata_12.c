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
struct gfar_private {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFAR_ERRATA_12 ; 
 scalar_t__ gfar_has_errata (struct gfar_private*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline bool gfar_csum_errata_12(struct gfar_private *priv,
				       unsigned long fcb_addr)
{
	return (gfar_has_errata(priv, GFAR_ERRATA_12) &&
	       (fcb_addr % 0x20) > 0x18);
}