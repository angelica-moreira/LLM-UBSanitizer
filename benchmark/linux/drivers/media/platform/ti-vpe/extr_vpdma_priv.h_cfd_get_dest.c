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
struct vpdma_cfd {int ctl_payload_len; } ;

/* Variables and functions */
 int CFD_DEST_MASK ; 
 int CFD_DEST_SHFT ; 

__attribute__((used)) static inline int cfd_get_dest(struct vpdma_cfd *cfd)
{
	return (cfd->ctl_payload_len >> CFD_DEST_SHFT) & CFD_DEST_MASK;
}