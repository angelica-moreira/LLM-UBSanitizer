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
struct shash_desc {int dummy; } ;

/* Variables and functions */
 int sha224_init (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  shash_desc_ctx (struct shash_desc*) ; 

__attribute__((used)) static int crypto_sha224_init(struct shash_desc *desc)
{
	return sha224_init(shash_desc_ctx(desc));
}