#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  buf ;
typedef  int /*<<< orphan*/  __u64 ;
struct TYPE_3__ {scalar_t__ reseed_counter; scalar_t__ parm_block; } ;
struct TYPE_4__ {TYPE_1__ prngws; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  get_random_bytes (char*,int) ; 
 TYPE_2__* prng_data ; 
 int /*<<< orphan*/  prng_tdes_add_entropy () ; 

__attribute__((used)) static void prng_tdes_seed(int nbytes)
{
	char buf[16];
	int i = 0;

	BUG_ON(nbytes > sizeof(buf));

	get_random_bytes(buf, nbytes);

	/* Add the entropy */
	while (nbytes >= 8) {
		*((__u64 *)prng_data->prngws.parm_block) ^= *((__u64 *)(buf+i));
		prng_tdes_add_entropy();
		i += 8;
		nbytes -= 8;
	}
	prng_tdes_add_entropy();
	prng_data->prngws.reseed_counter = 0;
}