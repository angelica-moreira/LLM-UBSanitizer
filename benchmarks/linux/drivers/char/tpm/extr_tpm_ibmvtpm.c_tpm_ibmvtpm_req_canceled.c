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
typedef  scalar_t__ u8 ;
struct tpm_chip {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static bool tpm_ibmvtpm_req_canceled(struct tpm_chip *chip, u8 status)
{
	return (status == 0);
}