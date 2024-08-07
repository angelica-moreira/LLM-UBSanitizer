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
 int TDES_FLAGS_CFB ; 
 int TDES_FLAGS_ENCRYPT ; 
 int atmel_tdes_crypt (struct ablkcipher_request*,int) ; 

__attribute__((used)) static int atmel_tdes_cfb_encrypt(struct ablkcipher_request *req)
{
	return atmel_tdes_crypt(req, TDES_FLAGS_ENCRYPT | TDES_FLAGS_CFB);
}