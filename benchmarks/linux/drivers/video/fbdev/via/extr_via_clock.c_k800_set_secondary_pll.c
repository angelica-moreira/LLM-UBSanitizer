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
struct via_pll_config {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  k800_encode_pll (struct via_pll_config) ; 
 int /*<<< orphan*/  k800_set_secondary_pll_encoded (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void k800_set_secondary_pll(struct via_pll_config config)
{
	k800_set_secondary_pll_encoded(k800_encode_pll(config));
}