#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct sk_buff {int /*<<< orphan*/  len; int /*<<< orphan*/  data; } ;
struct TYPE_4__ {int /*<<< orphan*/  fd; } ;
struct TYPE_5__ {TYPE_1__ tuntap; } ;
struct TYPE_6__ {TYPE_2__ info; } ;
struct iss_net_private {TYPE_3__ tp; } ;

/* Variables and functions */
 int simc_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int tuntap_write(struct iss_net_private *lp, struct sk_buff **skb)
{
	return simc_write(lp->tp.info.tuntap.fd, (*skb)->data, (*skb)->len);
}