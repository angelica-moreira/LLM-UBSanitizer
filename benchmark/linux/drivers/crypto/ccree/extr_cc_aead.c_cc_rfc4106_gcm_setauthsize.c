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
struct device {int dummy; } ;
struct crypto_aead {int dummy; } ;
struct cc_aead_ctx {int /*<<< orphan*/  drvdata; } ;

/* Variables and functions */
 int EINVAL ; 
 int cc_aead_setauthsize (struct crypto_aead*,unsigned int) ; 
 struct cc_aead_ctx* crypto_aead_ctx (struct crypto_aead*) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,unsigned int) ; 
 struct device* drvdata_to_dev (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int cc_rfc4106_gcm_setauthsize(struct crypto_aead *authenc,
				      unsigned int authsize)
{
	struct cc_aead_ctx *ctx = crypto_aead_ctx(authenc);
	struct device *dev = drvdata_to_dev(ctx->drvdata);

	dev_dbg(dev, "authsize %d\n", authsize);

	switch (authsize) {
	case 8:
	case 12:
	case 16:
		break;
	default:
		return -EINVAL;
	}

	return cc_aead_setauthsize(authenc, authsize);
}