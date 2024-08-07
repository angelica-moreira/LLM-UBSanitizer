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
struct aead_request {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CCP_AES_ACTION_ENCRYPT ; 
 int ccp_aes_gcm_crypt (struct aead_request*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ccp_aes_gcm_encrypt(struct aead_request *req)
{
	return ccp_aes_gcm_crypt(req, CCP_AES_ACTION_ENCRYPT);
}