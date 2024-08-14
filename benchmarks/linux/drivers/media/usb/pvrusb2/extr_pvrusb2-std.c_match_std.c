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
typedef  int v4l2_std_id ;
struct v4l2_standard {int id; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (struct v4l2_standard*) ; 
 struct v4l2_standard* generic_standards ; 

__attribute__((used)) static struct v4l2_standard *match_std(v4l2_std_id id)
{
	unsigned int idx;
	for (idx = 0; idx < ARRAY_SIZE(generic_standards); idx++) {
		if (generic_standards[idx].id & id) {
			return generic_standards + idx;
		}
	}
	return NULL;
}