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
typedef  int u64 ;
typedef  int u32 ;
struct pci_dev {int /*<<< orphan*/  devfn; int /*<<< orphan*/  bus; } ;
struct fam15h_power_data {int tdp_to_watts; scalar_t__ base_tdp; struct pci_dev* pdev; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;
typedef  int s32 ;

/* Variables and functions */
 int /*<<< orphan*/  PCI_DEVFN (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  PCI_SLOT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REG_TDP_LIMIT3 ; 
 int /*<<< orphan*/  REG_TDP_RUNNING_AVERAGE ; 
 struct fam15h_power_data* dev_get_drvdata (struct device*) ; 
 scalar_t__ is_carrizo_or_later () ; 
 int /*<<< orphan*/  pci_bus_read_config_dword (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int sign_extend32 (int,int) ; 
 int /*<<< orphan*/  sprintf (char*,char*,unsigned int) ; 

__attribute__((used)) static ssize_t power1_input_show(struct device *dev,
				 struct device_attribute *attr, char *buf)
{
	u32 val, tdp_limit, running_avg_range;
	s32 running_avg_capture;
	u64 curr_pwr_watts;
	struct fam15h_power_data *data = dev_get_drvdata(dev);
	struct pci_dev *f4 = data->pdev;

	pci_bus_read_config_dword(f4->bus, PCI_DEVFN(PCI_SLOT(f4->devfn), 5),
				  REG_TDP_RUNNING_AVERAGE, &val);

	/*
	 * On Carrizo and later platforms, TdpRunAvgAccCap bit field
	 * is extended to 4:31 from 4:25.
	 */
	if (is_carrizo_or_later()) {
		running_avg_capture = val >> 4;
		running_avg_capture = sign_extend32(running_avg_capture, 27);
	} else {
		running_avg_capture = (val >> 4) & 0x3fffff;
		running_avg_capture = sign_extend32(running_avg_capture, 21);
	}

	running_avg_range = (val & 0xf) + 1;

	pci_bus_read_config_dword(f4->bus, PCI_DEVFN(PCI_SLOT(f4->devfn), 5),
				  REG_TDP_LIMIT3, &val);

	/*
	 * On Carrizo and later platforms, ApmTdpLimit bit field
	 * is extended to 16:31 from 16:28.
	 */
	if (is_carrizo_or_later())
		tdp_limit = val >> 16;
	else
		tdp_limit = (val >> 16) & 0x1fff;

	curr_pwr_watts = ((u64)(tdp_limit +
				data->base_tdp)) << running_avg_range;
	curr_pwr_watts -= running_avg_capture;
	curr_pwr_watts *= data->tdp_to_watts;

	/*
	 * Convert to microWatt
	 *
	 * power is in Watt provided as fixed point integer with
	 * scaling factor 1/(2^16).  For conversion we use
	 * (10^6)/(2^16) = 15625/(2^10)
	 */
	curr_pwr_watts = (curr_pwr_watts * 15625) >> (10 + running_avg_range);
	return sprintf(buf, "%u\n", (unsigned int) curr_pwr_watts);
}