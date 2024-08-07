#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {scalar_t__ rxkey; } ;
struct chtls_sock {TYPE_1__ tlshws; } ;

/* Variables and functions */

__attribute__((used)) static bool is_tls_rx(struct chtls_sock *csk)
{
	return csk->tlshws.rxkey >= 0;
}