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
struct scatterlist {int dummy; } ;
struct blkcipher_walk {int dummy; } ;
struct blkcipher_desc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CPACF_DECRYPT ; 
 int /*<<< orphan*/  blkcipher_walk_init (struct blkcipher_walk*,struct scatterlist*,struct scatterlist*,unsigned int) ; 
 int ctr_paes_crypt (struct blkcipher_desc*,int /*<<< orphan*/ ,struct blkcipher_walk*) ; 

__attribute__((used)) static int ctr_paes_decrypt(struct blkcipher_desc *desc,
			    struct scatterlist *dst, struct scatterlist *src,
			    unsigned int nbytes)
{
	struct blkcipher_walk walk;

	blkcipher_walk_init(&walk, dst, src, nbytes);
	return ctr_paes_crypt(desc, CPACF_DECRYPT, &walk);
}