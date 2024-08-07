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
struct scsi_qla_host {int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  AF_83XX_IOCB_INTR_ON ; 
 int /*<<< orphan*/  qla4_8xxx_intr_enable (struct scsi_qla_host*) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void qla4_83xx_enable_iocb_intrs(struct scsi_qla_host *ha)
{
	if (!test_bit(AF_83XX_IOCB_INTR_ON, &ha->flags)) {
		qla4_8xxx_intr_enable(ha);
		set_bit(AF_83XX_IOCB_INTR_ON, &ha->flags);
	}
}