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
typedef  int /*<<< orphan*/  u8 ;
struct sock {int dummy; } ;
typedef  int /*<<< orphan*/  gfp_t ;

/* Variables and functions */
 int /*<<< orphan*/  PAD ; 
 int /*<<< orphan*/  PNS_PEP_STATUS_IND ; 
 int /*<<< orphan*/  PN_PEP_TYPE_COMMON ; 
 int pep_indicate (struct sock*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int pipe_snd_status(struct sock *sk, u8 type, u8 status, gfp_t priority)
{
	u8 data[4] = { type, PAD, PAD, status };

	return pep_indicate(sk, PNS_PEP_STATUS_IND, PN_PEP_TYPE_COMMON,
				data, 4, priority);
}