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
struct si_sm_data {TYPE_1__* io; } ;
struct TYPE_2__ {unsigned char (* inputb ) (TYPE_1__*,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 unsigned char stub1 (TYPE_1__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline unsigned char read_smic_data(struct si_sm_data *smic)
{
	return smic->io->inputb(smic->io, 0);
}