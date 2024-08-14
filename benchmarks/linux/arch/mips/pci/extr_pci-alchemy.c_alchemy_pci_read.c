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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct pci_bus {int dummy; } ;

/* Variables and functions */
 int read_config_byte (struct pci_bus*,unsigned int,int,int /*<<< orphan*/ *) ; 
 int read_config_dword (struct pci_bus*,unsigned int,int,int /*<<< orphan*/ *) ; 
 int read_config_word (struct pci_bus*,unsigned int,int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int alchemy_pci_read(struct pci_bus *bus, unsigned int devfn,
		       int where, int size, u32 *val)
{
	switch (size) {
	case 1: {
			u8 _val;
			int rc = read_config_byte(bus, devfn, where, &_val);

			*val = _val;
			return rc;
		}
	case 2: {
			u16 _val;
			int rc = read_config_word(bus, devfn, where, &_val);

			*val = _val;
			return rc;
		}
	default:
		return read_config_dword(bus, devfn, where, val);
	}
}