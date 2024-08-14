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
struct tipc_media_addr {int dummy; } ;
struct tipc_bearer {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  TIPC_MEDIA_ADDR_OFFSET ; 
 int tipc_eth_raw2addr (struct tipc_bearer*,struct tipc_media_addr*,char*) ; 

__attribute__((used)) static int tipc_eth_msg2addr(struct tipc_bearer *b,
			     struct tipc_media_addr *addr,
			     char *msg)
{
	/* Skip past preamble: */
	msg += TIPC_MEDIA_ADDR_OFFSET;
	return tipc_eth_raw2addr(b, addr, msg);
}