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
 int mxs_dcp_aes_enqueue (struct ablkcipher_request*,int,int) ; 

__attribute__((used)) static int mxs_dcp_aes_ecb_encrypt(struct ablkcipher_request *req)
{
	return mxs_dcp_aes_enqueue(req, 1, 1);
}