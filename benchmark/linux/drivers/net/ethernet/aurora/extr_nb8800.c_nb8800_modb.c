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
struct nb8800_priv {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  nb8800_maskb (struct nb8800_priv*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void nb8800_modb(struct nb8800_priv *priv, int reg, u8 bits,
			       bool set)
{
	nb8800_maskb(priv, reg, bits, set ? bits : 0);
}