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
typedef  unsigned char u_char ;
struct spk_synth {int dummy; } ;

/* Variables and functions */
 unsigned char lastind ; 

__attribute__((used)) static unsigned char get_index(struct spk_synth *synth)
{
	u_char rv;

	rv = lastind;
	lastind = 0;
	return rv;
}