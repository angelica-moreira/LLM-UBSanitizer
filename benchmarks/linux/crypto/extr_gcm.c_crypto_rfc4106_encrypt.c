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
struct aead_request {int /*<<< orphan*/  assoclen; } ;

/* Variables and functions */
 int crypto_aead_encrypt (struct aead_request*) ; 
 int crypto_ipsec_check_assoclen (int /*<<< orphan*/ ) ; 
 struct aead_request* crypto_rfc4106_crypt (struct aead_request*) ; 

__attribute__((used)) static int crypto_rfc4106_encrypt(struct aead_request *req)
{
	int err;

	err = crypto_ipsec_check_assoclen(req->assoclen);
	if (err)
		return err;

	req = crypto_rfc4106_crypt(req);

	return crypto_aead_encrypt(req);
}