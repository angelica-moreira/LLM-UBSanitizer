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
typedef  int /*<<< orphan*/  u_long ;
struct scb {TYPE_1__* platform_data; } ;
struct TYPE_2__ {int /*<<< orphan*/  xfer_len; } ;

/* Variables and functions */

__attribute__((used)) static inline
u_long ahc_get_transfer_length(struct scb *scb)
{
	return (scb->platform_data->xfer_len);
}