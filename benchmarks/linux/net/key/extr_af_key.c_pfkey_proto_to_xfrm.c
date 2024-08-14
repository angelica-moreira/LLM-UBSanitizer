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
typedef  scalar_t__ uint8_t ;

/* Variables and functions */
 scalar_t__ IPSEC_PROTO_ANY ; 

__attribute__((used)) static uint8_t pfkey_proto_to_xfrm(uint8_t proto)
{
	return proto == IPSEC_PROTO_ANY ? 0 : proto;
}