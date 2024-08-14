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
 int clamp (int,int /*<<< orphan*/ ,int) ; 
 int* tpg_rec709_to_linear ; 

__attribute__((used)) static inline int rec709_to_linear(int v)
{
	v = clamp(v, 0, 0xff0);
	return tpg_rec709_to_linear[v];
}