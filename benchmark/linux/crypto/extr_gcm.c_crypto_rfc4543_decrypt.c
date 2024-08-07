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
 scalar_t__ crypto_ipsec_check_assoclen (int /*<<< orphan*/ ) ; 
 int crypto_rfc4543_crypt (struct aead_request*,int) ; 

__attribute__((used)) static int crypto_rfc4543_decrypt(struct aead_request *req)
{
	return crypto_ipsec_check_assoclen(req->assoclen) ?:
	       crypto_rfc4543_crypt(req, false);
}