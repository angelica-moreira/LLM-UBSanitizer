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
struct ablkcipher_request {int dummy; } ;

/* Variables and functions */
 int omap_des_crypt (struct ablkcipher_request*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int omap_des_ecb_decrypt(struct ablkcipher_request *req)
{
	return omap_des_crypt(req, 0);
}