#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
struct TYPE_3__ {scalar_t__ cmd; char const* name; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 TYPE_1__* sdvo_cmd_names ; 

__attribute__((used)) static const char *sdvo_cmd_name(u8 cmd)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(sdvo_cmd_names); i++) {
		if (cmd == sdvo_cmd_names[i].cmd)
			return sdvo_cmd_names[i].name;
	}

	return NULL;
}