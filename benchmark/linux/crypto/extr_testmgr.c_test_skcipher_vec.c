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
struct testvec_config {int dummy; } ;
struct skcipher_request {int dummy; } ;
struct cipher_testvec {scalar_t__ fips_skip; } ;
struct cipher_test_sglists {int dummy; } ;
typedef  int /*<<< orphan*/  cfgname ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (struct testvec_config*) ; 
 int TESTVEC_CONFIG_NAMELEN ; 
 int /*<<< orphan*/  cond_resched () ; 
 struct testvec_config* default_cipher_testvec_configs ; 
 scalar_t__ fips_enabled ; 
 unsigned int fuzz_iterations ; 
 int /*<<< orphan*/  generate_random_testvec_config (struct testvec_config*,char*,int) ; 
 int /*<<< orphan*/  noextratests ; 
 int /*<<< orphan*/  sprintf (char*,char*,unsigned int) ; 
 int test_skcipher_vec_cfg (char const*,int,struct cipher_testvec const*,char*,struct testvec_config*,struct skcipher_request*,struct cipher_test_sglists*) ; 

__attribute__((used)) static int test_skcipher_vec(const char *driver, int enc,
			     const struct cipher_testvec *vec,
			     unsigned int vec_num,
			     struct skcipher_request *req,
			     struct cipher_test_sglists *tsgls)
{
	char vec_name[16];
	unsigned int i;
	int err;

	if (fips_enabled && vec->fips_skip)
		return 0;

	sprintf(vec_name, "%u", vec_num);

	for (i = 0; i < ARRAY_SIZE(default_cipher_testvec_configs); i++) {
		err = test_skcipher_vec_cfg(driver, enc, vec, vec_name,
					    &default_cipher_testvec_configs[i],
					    req, tsgls);
		if (err)
			return err;
	}

#ifdef CONFIG_CRYPTO_MANAGER_EXTRA_TESTS
	if (!noextratests) {
		struct testvec_config cfg;
		char cfgname[TESTVEC_CONFIG_NAMELEN];

		for (i = 0; i < fuzz_iterations; i++) {
			generate_random_testvec_config(&cfg, cfgname,
						       sizeof(cfgname));
			err = test_skcipher_vec_cfg(driver, enc, vec, vec_name,
						    &cfg, req, tsgls);
			if (err)
				return err;
			cond_resched();
		}
	}
#endif
	return 0;
}