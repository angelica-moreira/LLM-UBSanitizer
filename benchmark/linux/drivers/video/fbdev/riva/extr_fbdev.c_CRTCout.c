#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  PCIO; } ;
struct riva_par {TYPE_1__ riva; } ;

/* Variables and functions */
 int /*<<< orphan*/  VGA_WR08 (int /*<<< orphan*/ ,int,unsigned char) ; 

__attribute__((used)) static inline void CRTCout(struct riva_par *par, unsigned char index,
			   unsigned char val)
{
	VGA_WR08(par->riva.PCIO, 0x3d4, index);
	VGA_WR08(par->riva.PCIO, 0x3d5, val);
}