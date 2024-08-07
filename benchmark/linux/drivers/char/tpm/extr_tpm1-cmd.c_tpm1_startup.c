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
struct tpm_chip {int /*<<< orphan*/  dev; } ;
struct tpm_buf {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  TPM_ORD_STARTUP ; 
 int /*<<< orphan*/  TPM_ST_CLEAR ; 
 int /*<<< orphan*/  TPM_TAG_RQU_COMMAND ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  tpm_buf_append_u16 (struct tpm_buf*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tpm_buf_destroy (struct tpm_buf*) ; 
 int tpm_buf_init (struct tpm_buf*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int tpm_transmit_cmd (struct tpm_chip*,struct tpm_buf*,int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static int tpm1_startup(struct tpm_chip *chip)
{
	struct tpm_buf buf;
	int rc;

	dev_info(&chip->dev, "starting up the TPM manually\n");

	rc = tpm_buf_init(&buf, TPM_TAG_RQU_COMMAND, TPM_ORD_STARTUP);
	if (rc < 0)
		return rc;

	tpm_buf_append_u16(&buf, TPM_ST_CLEAR);

	rc = tpm_transmit_cmd(chip, &buf, 0, "attempting to start the TPM");
	tpm_buf_destroy(&buf);
	return rc;
}