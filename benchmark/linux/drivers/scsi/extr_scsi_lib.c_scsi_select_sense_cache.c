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
struct kmem_cache {int dummy; } ;

/* Variables and functions */
 struct kmem_cache* scsi_sense_cache ; 
 struct kmem_cache* scsi_sense_isadma_cache ; 

__attribute__((used)) static inline struct kmem_cache *
scsi_select_sense_cache(bool unchecked_isa_dma)
{
	return unchecked_isa_dma ? scsi_sense_isadma_cache : scsi_sense_cache;
}