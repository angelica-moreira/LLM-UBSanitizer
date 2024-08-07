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
typedef  int u16 ;
struct sk_buff {int dummy; } ;
struct jme_adapter {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int RXWBFLAG_IPCS ; 
 int RXWBFLAG_IPV4 ; 
 int RXWBFLAG_MF ; 
 int RXWBFLAG_TCPCS ; 
 int RXWBFLAG_TCPON ; 
 int RXWBFLAG_UDPCS ; 
 int RXWBFLAG_UDPON ; 
 scalar_t__ jme_udpsum (struct sk_buff*) ; 
 int /*<<< orphan*/  netif_err (struct jme_adapter*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  rx_err ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static int
jme_rxsum_ok(struct jme_adapter *jme, u16 flags, struct sk_buff *skb)
{
	if (!(flags & (RXWBFLAG_TCPON | RXWBFLAG_UDPON | RXWBFLAG_IPV4)))
		return false;

	if (unlikely((flags & (RXWBFLAG_MF | RXWBFLAG_TCPON | RXWBFLAG_TCPCS))
			== RXWBFLAG_TCPON)) {
		if (flags & RXWBFLAG_IPV4)
			netif_err(jme, rx_err, jme->dev, "TCP Checksum error\n");
		return false;
	}

	if (unlikely((flags & (RXWBFLAG_MF | RXWBFLAG_UDPON | RXWBFLAG_UDPCS))
			== RXWBFLAG_UDPON) && jme_udpsum(skb)) {
		if (flags & RXWBFLAG_IPV4)
			netif_err(jme, rx_err, jme->dev, "UDP Checksum error\n");
		return false;
	}

	if (unlikely((flags & (RXWBFLAG_IPV4 | RXWBFLAG_IPCS))
			== RXWBFLAG_IPV4)) {
		netif_err(jme, rx_err, jme->dev, "IPv4 Checksum error\n");
		return false;
	}

	return true;
}