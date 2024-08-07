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
struct pvr2_hdw {TYPE_1__* hdw_desc; } ;
struct TYPE_2__ {char const* shortname; } ;

/* Variables and functions */

const char *pvr2_hdw_get_type(struct pvr2_hdw *hdw)
{
	return hdw->hdw_desc->shortname;
}