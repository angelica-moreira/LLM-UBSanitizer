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
 int ARRAY_SIZE (int*) ; 
 int* mt2701_m4u_in_larb ; 

__attribute__((used)) static inline int mt2701_m4u_to_larb(int id)
{
	int i;

	for (i = ARRAY_SIZE(mt2701_m4u_in_larb) - 1; i >= 0; i--)
		if ((id) >= mt2701_m4u_in_larb[i])
			return i;

	return 0;
}