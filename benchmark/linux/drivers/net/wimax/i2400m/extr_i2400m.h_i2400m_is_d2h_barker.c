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
typedef  int /*<<< orphan*/  __le32 ;

/* Variables and functions */
 scalar_t__ I2400M_D2H_MSG_BARKER ; 
 scalar_t__ le32_to_cpu (int /*<<< orphan*/  const) ; 

__attribute__((used)) static inline
int i2400m_is_d2h_barker(const void *buf)
{
	const __le32 *barker = buf;
	return le32_to_cpu(*barker) == I2400M_D2H_MSG_BARKER;
}