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
struct w5300_priv {scalar_t__ base; } ;

/* Variables and functions */
 int CONFIG_WIZNET_BUS_SHIFT ; 
 int /*<<< orphan*/  iowrite16 (int,scalar_t__) ; 

__attribute__((used)) static inline void w5300_write_direct(struct w5300_priv *priv,
				      u16 addr, u16 data)
{
	iowrite16(data, priv->base + (addr << CONFIG_WIZNET_BUS_SHIFT));
}