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
struct crypto_authenc_key_param {int dummy; } ;
struct crypt_config {int dummy; } ;

/* Variables and functions */
 int RTA_SPACE (int) ; 
 int crypt_subkey_size (struct crypt_config*) ; 

__attribute__((used)) static unsigned crypt_authenckey_size(struct crypt_config *cc)
{
	return crypt_subkey_size(cc) + RTA_SPACE(sizeof(struct crypto_authenc_key_param));
}