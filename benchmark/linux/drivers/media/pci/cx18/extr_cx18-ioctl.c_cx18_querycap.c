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
struct v4l2_capability {int capabilities; int /*<<< orphan*/  bus_info; int /*<<< orphan*/  card; int /*<<< orphan*/  driver; } ;
struct file {int dummy; } ;
struct cx18_open_id {struct cx18* cx; } ;
struct cx18 {int v4l2_cap; int /*<<< orphan*/  pci_dev; int /*<<< orphan*/  card_name; } ;

/* Variables and functions */
 int /*<<< orphan*/  CX18_DRIVER_NAME ; 
 int V4L2_CAP_DEVICE_CAPS ; 
 struct cx18_open_id* fh2id (void*) ; 
 char* pci_name (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,char*) ; 
 int /*<<< orphan*/  strscpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int cx18_querycap(struct file *file, void *fh,
				struct v4l2_capability *vcap)
{
	struct cx18_open_id *id = fh2id(fh);
	struct cx18 *cx = id->cx;

	strscpy(vcap->driver, CX18_DRIVER_NAME, sizeof(vcap->driver));
	strscpy(vcap->card, cx->card_name, sizeof(vcap->card));
	snprintf(vcap->bus_info, sizeof(vcap->bus_info),
		 "PCI:%s", pci_name(cx->pci_dev));
	vcap->capabilities = cx->v4l2_cap | V4L2_CAP_DEVICE_CAPS;
	return 0;
}