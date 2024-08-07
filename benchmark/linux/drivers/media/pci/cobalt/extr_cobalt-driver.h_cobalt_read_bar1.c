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
typedef  scalar_t__ u32 ;
struct cobalt {scalar_t__ bar1; } ;

/* Variables and functions */
 scalar_t__ ioread32 (scalar_t__) ; 

__attribute__((used)) static inline u32 cobalt_read_bar1(struct cobalt *cobalt, u32 reg)
{
	return ioread32(cobalt->bar1 + reg);
}