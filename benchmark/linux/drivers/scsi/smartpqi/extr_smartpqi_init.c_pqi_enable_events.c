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
struct pqi_ctrl_info {int dummy; } ;

/* Variables and functions */
 int pqi_configure_events (struct pqi_ctrl_info*,int) ; 

__attribute__((used)) static inline int pqi_enable_events(struct pqi_ctrl_info *ctrl_info)
{
	return pqi_configure_events(ctrl_info, true);
}