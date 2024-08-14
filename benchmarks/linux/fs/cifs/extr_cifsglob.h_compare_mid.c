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
struct smb_hdr {int /*<<< orphan*/  Mid; } ;
typedef  scalar_t__ __u16 ;

/* Variables and functions */
 scalar_t__ le16_to_cpu (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline bool
compare_mid(__u16 mid, const struct smb_hdr *smb)
{
	return mid == le16_to_cpu(smb->Mid);
}