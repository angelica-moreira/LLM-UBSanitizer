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
struct skcipher_request {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  GLUE_FUNC_CAST (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __serpent_encrypt ; 
 int glue_cbc_encrypt_req_128bit (int /*<<< orphan*/ ,struct skcipher_request*) ; 

__attribute__((used)) static int cbc_encrypt(struct skcipher_request *req)
{
	return glue_cbc_encrypt_req_128bit(GLUE_FUNC_CAST(__serpent_encrypt),
					   req);
}