#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  scalar_t__ u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct pci_dev {int dummy; } ;
struct config_field_entry {int /*<<< orphan*/  data; struct config_field* field; } ;
struct TYPE_7__ {int (* read ) (struct pci_dev*,int,scalar_t__*,int /*<<< orphan*/ ) ;} ;
struct TYPE_6__ {int (* read ) (struct pci_dev*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ;} ;
struct TYPE_5__ {int (* read ) (struct pci_dev*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ;} ;
struct TYPE_8__ {TYPE_3__ dw; TYPE_2__ w; TYPE_1__ b; } ;
struct config_field {int size; TYPE_4__ u; } ;

/* Variables and functions */
 int stub1 (struct pci_dev*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int stub2 (struct pci_dev*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int stub3 (struct pci_dev*,int,scalar_t__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int conf_space_read(struct pci_dev *dev,
			   const struct config_field_entry *entry,
			   int offset, u32 *value)
{
	int ret = 0;
	const struct config_field *field = entry->field;

	*value = 0;

	switch (field->size) {
	case 1:
		if (field->u.b.read)
			ret = field->u.b.read(dev, offset, (u8 *) value,
					      entry->data);
		break;
	case 2:
		if (field->u.w.read)
			ret = field->u.w.read(dev, offset, (u16 *) value,
					      entry->data);
		break;
	case 4:
		if (field->u.dw.read)
			ret = field->u.dw.read(dev, offset, value, entry->data);
		break;
	}
	return ret;
}