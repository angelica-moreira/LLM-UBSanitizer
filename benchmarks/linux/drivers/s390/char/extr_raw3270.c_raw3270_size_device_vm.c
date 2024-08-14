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
struct raw3270 {int model; int rows; int cols; int /*<<< orphan*/  cdev; } ;
struct diag210 {int vrdclen; int vrdccrmd; int /*<<< orphan*/  vrdcdvno; } ;
struct ccw_dev_id {int /*<<< orphan*/  devno; } ;

/* Variables and functions */
 int /*<<< orphan*/  ccw_device_get_id (int /*<<< orphan*/ ,struct ccw_dev_id*) ; 
 int diag210 (struct diag210*) ; 

__attribute__((used)) static void
raw3270_size_device_vm(struct raw3270 *rp)
{
	int rc, model;
	struct ccw_dev_id dev_id;
	struct diag210 diag_data;

	ccw_device_get_id(rp->cdev, &dev_id);
	diag_data.vrdcdvno = dev_id.devno;
	diag_data.vrdclen = sizeof(struct diag210);
	rc = diag210(&diag_data);
	model = diag_data.vrdccrmd;
	/* Use default model 2 if the size could not be detected */
	if (rc || model < 2 || model > 5)
		model = 2;
	switch (model) {
	case 2:
		rp->model = model;
		rp->rows = 24;
		rp->cols = 80;
		break;
	case 3:
		rp->model = model;
		rp->rows = 32;
		rp->cols = 80;
		break;
	case 4:
		rp->model = model;
		rp->rows = 43;
		rp->cols = 80;
		break;
	case 5:
		rp->model = model;
		rp->rows = 27;
		rp->cols = 132;
		break;
	}
}