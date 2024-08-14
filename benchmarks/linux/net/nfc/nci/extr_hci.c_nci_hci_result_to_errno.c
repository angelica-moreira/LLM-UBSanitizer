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
typedef  int u8 ;

/* Variables and functions */
 int EOPNOTSUPP ; 
 int ETIME ; 
#define  NCI_HCI_ANY_E_REG_PAR_UNKNOWN 130 
#define  NCI_HCI_ANY_E_TIMEOUT 129 
#define  NCI_HCI_ANY_OK 128 

__attribute__((used)) static int nci_hci_result_to_errno(u8 result)
{
	switch (result) {
	case NCI_HCI_ANY_OK:
		return 0;
	case NCI_HCI_ANY_E_REG_PAR_UNKNOWN:
		return -EOPNOTSUPP;
	case NCI_HCI_ANY_E_TIMEOUT:
		return -ETIME;
	default:
		return -1;
	}
}