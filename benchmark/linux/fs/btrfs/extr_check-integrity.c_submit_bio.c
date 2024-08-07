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
struct bio {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __btrfsic_submit_bio (struct bio*) ; 
 int /*<<< orphan*/  submit_bio (struct bio*) ; 

void btrfsic_submit_bio(struct bio *bio)
{
	__btrfsic_submit_bio(bio);
	submit_bio(bio);
}