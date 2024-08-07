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
typedef  int /*<<< orphan*/  u8 ;
struct dm_crypt_request {int dummy; } ;
struct crypt_config {int iv_size; } ;
typedef  int /*<<< orphan*/  __le64 ;

/* Variables and functions */
 int /*<<< orphan*/ * iv_of_dmreq (struct crypt_config*,struct dm_crypt_request*) ; 

__attribute__((used)) static __le64 *org_sector_of_dmreq(struct crypt_config *cc,
		       struct dm_crypt_request *dmreq)
{
	u8 *ptr = iv_of_dmreq(cc, dmreq) + cc->iv_size + cc->iv_size;
	return (__le64 *) ptr;
}