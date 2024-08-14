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
 int FLG_ECB ; 
 int FLG_ENCRYPT ; 
 int FLG_TDES ; 
 int stm32_cryp_crypt (struct ablkcipher_request*,int) ; 

__attribute__((used)) static int stm32_cryp_tdes_ecb_encrypt(struct ablkcipher_request *req)
{
	return stm32_cryp_crypt(req, FLG_TDES | FLG_ECB | FLG_ENCRYPT);
}