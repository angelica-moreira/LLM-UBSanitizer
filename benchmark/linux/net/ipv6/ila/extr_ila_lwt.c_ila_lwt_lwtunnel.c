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
struct lwtunnel_state {scalar_t__ data; } ;
struct ila_lwt {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline struct ila_lwt *ila_lwt_lwtunnel(
	struct lwtunnel_state *lwt)
{
	return (struct ila_lwt *)lwt->data;
}