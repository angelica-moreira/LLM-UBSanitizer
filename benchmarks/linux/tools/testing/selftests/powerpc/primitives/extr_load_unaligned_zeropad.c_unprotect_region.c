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
 int PROT_READ ; 
 int PROT_WRITE ; 
 scalar_t__ mem_region ; 
 scalar_t__ mprotect (scalar_t__,scalar_t__,int) ; 
 scalar_t__ page_size ; 
 int /*<<< orphan*/  perror (char*) ; 

__attribute__((used)) static int unprotect_region(void)
{
	if (mprotect(mem_region + page_size, page_size, PROT_READ|PROT_WRITE)) {
		perror("mprotect");
		return 1;
	}

	return 0;
}