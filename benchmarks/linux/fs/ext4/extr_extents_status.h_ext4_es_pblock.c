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
struct extent_status {int es_pblk; } ;
typedef  int ext4_fsblk_t ;

/* Variables and functions */
 int ES_MASK ; 

__attribute__((used)) static inline ext4_fsblk_t ext4_es_pblock(struct extent_status *es)
{
	return es->es_pblk & ~ES_MASK;
}