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
typedef  scalar_t__ u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct atp_unit {scalar_t__ baseport; } ;

/* Variables and functions */
 int /*<<< orphan*/  inw (scalar_t__) ; 

__attribute__((used)) static inline u16 atp_readw_base(struct atp_unit *atp, u8 reg)
{
	return inw(atp->baseport + reg);
}