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

/* Variables and functions */
 int ENODEV ; 
 int EPERM ; 
 int /*<<< orphan*/  chip ; 
 int /*<<< orphan*/  dump_tpm_buf (unsigned char*) ; 
 int tpm_send (int /*<<< orphan*/ ,unsigned char*,size_t) ; 

int trusted_tpm_send(unsigned char *cmd, size_t buflen)
{
	int rc;

	if (!chip)
		return -ENODEV;

	dump_tpm_buf(cmd);
	rc = tpm_send(chip, cmd, buflen);
	dump_tpm_buf(cmd);
	if (rc > 0)
		/* Can't return positive return codes values to keyctl */
		rc = -EPERM;
	return rc;
}