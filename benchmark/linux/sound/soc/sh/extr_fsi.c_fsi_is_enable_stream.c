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
struct fsi_priv {int enable_stream; } ;

/* Variables and functions */

__attribute__((used)) static int fsi_is_enable_stream(struct fsi_priv *fsi)
{
	return fsi->enable_stream;
}