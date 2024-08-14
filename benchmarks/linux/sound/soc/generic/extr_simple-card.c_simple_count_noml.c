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
struct link_info {int /*<<< orphan*/  link; int /*<<< orphan*/  dais; } ;
struct device_node {int dummy; } ;
struct asoc_simple_priv {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static int simple_count_noml(struct asoc_simple_priv *priv,
			     struct device_node *np,
			     struct device_node *codec,
			     struct link_info *li, bool is_top)
{
	li->dais++; /* CPU or Codec */
	if (np != codec)
		li->link++; /* CPU-Codec */

	return 0;
}