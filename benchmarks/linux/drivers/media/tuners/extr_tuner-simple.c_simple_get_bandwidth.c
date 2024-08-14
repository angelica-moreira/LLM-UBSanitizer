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
typedef  int /*<<< orphan*/  u32 ;
struct tuner_simple_priv {int /*<<< orphan*/  bandwidth; } ;
struct dvb_frontend {struct tuner_simple_priv* tuner_priv; } ;

/* Variables and functions */

__attribute__((used)) static int simple_get_bandwidth(struct dvb_frontend *fe, u32 *bandwidth)
{
	struct tuner_simple_priv *priv = fe->tuner_priv;
	*bandwidth = priv->bandwidth;
	return 0;
}