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
struct scsi_pointer {unsigned char* ptr; int this_residual; } ;

/* Variables and functions */

__attribute__((used)) static inline void put_next_SCp_byte(struct scsi_pointer *SCp, unsigned char c)
{
	*SCp->ptr = c;
	SCp->ptr += 1;
	SCp->this_residual -= 1;
}