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

/* Variables and functions */
 int /*<<< orphan*/  swap_copy32 (void*,void*,unsigned int) ; 

__attribute__((used)) static void most_to_alsa_copy32(void *alsa, void *most, unsigned int bytes)
{
	swap_copy32(alsa, most, bytes);
}