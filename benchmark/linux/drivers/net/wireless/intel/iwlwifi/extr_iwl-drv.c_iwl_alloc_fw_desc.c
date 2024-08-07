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
struct iwl_drv {int dummy; } ;
struct fw_sec {int /*<<< orphan*/  data; int /*<<< orphan*/  offset; int /*<<< orphan*/  size; } ;
struct fw_desc {int /*<<< orphan*/ * data; int /*<<< orphan*/  len; int /*<<< orphan*/  offset; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  memcpy (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* vmalloc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int iwl_alloc_fw_desc(struct iwl_drv *drv, struct fw_desc *desc,
			     struct fw_sec *sec)
{
	void *data;

	desc->data = NULL;

	if (!sec || !sec->size)
		return -EINVAL;

	data = vmalloc(sec->size);
	if (!data)
		return -ENOMEM;

	desc->len = sec->size;
	desc->offset = sec->offset;
	memcpy(data, sec->data, desc->len);
	desc->data = data;

	return 0;
}