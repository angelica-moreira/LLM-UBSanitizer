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
typedef  int /*<<< orphan*/  u8 ;
struct rtl8187_priv {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  rtl818x_iowrite8_idx (struct rtl8187_priv*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void rtl818x_iowrite8(struct rtl8187_priv *priv, u8 *addr, u8 val)
{
	rtl818x_iowrite8_idx(priv, addr, val, 0);
}