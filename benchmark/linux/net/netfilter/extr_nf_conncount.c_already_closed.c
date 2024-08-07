#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {scalar_t__ state; } ;
struct TYPE_4__ {TYPE_1__ tcp; } ;
struct nf_conn {TYPE_2__ proto; } ;

/* Variables and functions */
 scalar_t__ IPPROTO_TCP ; 
 scalar_t__ TCP_CONNTRACK_CLOSE ; 
 scalar_t__ TCP_CONNTRACK_TIME_WAIT ; 
 scalar_t__ nf_ct_protonum (struct nf_conn const*) ; 

__attribute__((used)) static inline bool already_closed(const struct nf_conn *conn)
{
	if (nf_ct_protonum(conn) == IPPROTO_TCP)
		return conn->proto.tcp.state == TCP_CONNTRACK_TIME_WAIT ||
		       conn->proto.tcp.state == TCP_CONNTRACK_CLOSE;
	else
		return false;
}