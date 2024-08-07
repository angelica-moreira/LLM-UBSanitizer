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
struct cxgbit_np {int dummy; } ;

/* Variables and functions */
 int NP_INFO_HASH_SIZE ; 

__attribute__((used)) static int cxgbit_np_hashfn(const struct cxgbit_np *cnp)
{
	return ((unsigned long)cnp >> 10) & (NP_INFO_HASH_SIZE - 1);
}