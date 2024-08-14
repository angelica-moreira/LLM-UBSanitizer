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
typedef  int u16 ;
struct card_info {int dummy; } ;
struct atom_context {int cmd_table; int data_table; int /*<<< orphan*/  vbios_version; int /*<<< orphan*/  iio; void* bios; struct card_info* card; } ;

/* Variables and functions */
 int /*<<< orphan*/  ATOM_ATI_MAGIC ; 
 int ATOM_ATI_MAGIC_PTR ; 
 int ATOM_BIOS_MAGIC ; 
 scalar_t__ ATOM_DATA_IIO_PTR ; 
 scalar_t__ ATOM_ROM_CMD_PTR ; 
 scalar_t__ ATOM_ROM_DATA_PTR ; 
 int /*<<< orphan*/  ATOM_ROM_MAGIC ; 
 int ATOM_ROM_MAGIC_PTR ; 
 scalar_t__ ATOM_ROM_PART_NUMBER_PTR ; 
 scalar_t__ ATOM_ROM_TABLE_PTR ; 
 char* CSTR (int) ; 
 int CU16 (scalar_t__) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  amdgpu_atom_destroy (struct atom_context*) ; 
 int /*<<< orphan*/  atom_index_iio (struct atom_context*,int) ; 
 int /*<<< orphan*/  kfree (struct atom_context*) ; 
 struct atom_context* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_info (char*,...) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  strlen (int /*<<< orphan*/ ) ; 
 scalar_t__ strncmp (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

struct atom_context *amdgpu_atom_parse(struct card_info *card, void *bios)
{
	int base;
	struct atom_context *ctx =
	    kzalloc(sizeof(struct atom_context), GFP_KERNEL);
	char *str;
	u16 idx;

	if (!ctx)
		return NULL;

	ctx->card = card;
	ctx->bios = bios;

	if (CU16(0) != ATOM_BIOS_MAGIC) {
		pr_info("Invalid BIOS magic\n");
		kfree(ctx);
		return NULL;
	}
	if (strncmp
	    (CSTR(ATOM_ATI_MAGIC_PTR), ATOM_ATI_MAGIC,
	     strlen(ATOM_ATI_MAGIC))) {
		pr_info("Invalid ATI magic\n");
		kfree(ctx);
		return NULL;
	}

	base = CU16(ATOM_ROM_TABLE_PTR);
	if (strncmp
	    (CSTR(base + ATOM_ROM_MAGIC_PTR), ATOM_ROM_MAGIC,
	     strlen(ATOM_ROM_MAGIC))) {
		pr_info("Invalid ATOM magic\n");
		kfree(ctx);
		return NULL;
	}

	ctx->cmd_table = CU16(base + ATOM_ROM_CMD_PTR);
	ctx->data_table = CU16(base + ATOM_ROM_DATA_PTR);
	atom_index_iio(ctx, CU16(ctx->data_table + ATOM_DATA_IIO_PTR) + 4);
	if (!ctx->iio) {
		amdgpu_atom_destroy(ctx);
		return NULL;
	}

	idx = CU16(ATOM_ROM_PART_NUMBER_PTR);
	if (idx == 0)
		idx = 0x80;

	str = CSTR(idx);
	if (*str != '\0') {
		pr_info("ATOM BIOS: %s\n", str);
		strlcpy(ctx->vbios_version, str, sizeof(ctx->vbios_version));
	}


	return ctx;
}