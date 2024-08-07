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
struct rcar_drif_hwbuf {int status; } ;

/* Variables and functions */
 int RCAR_DRIF_BUF_OVERFLOW ; 

__attribute__((used)) static inline bool rcar_drif_bufs_overflow(struct rcar_drif_hwbuf **buf)
{
	return ((buf[0]->status | buf[1]->status) & RCAR_DRIF_BUF_OVERFLOW);
}