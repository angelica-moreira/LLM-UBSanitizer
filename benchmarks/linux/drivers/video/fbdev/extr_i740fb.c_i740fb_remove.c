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
struct pci_dev {int dummy; } ;
struct i740fb_par {int /*<<< orphan*/  regs; int /*<<< orphan*/  ddc_adapter; scalar_t__ ddc_registered; int /*<<< orphan*/  wc_cookie; } ;
struct fb_info {int /*<<< orphan*/  screen_base; int /*<<< orphan*/  cmap; struct i740fb_par* par; } ;

/* Variables and functions */
 int /*<<< orphan*/  arch_phys_wc_del (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fb_dealloc_cmap (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  framebuffer_release (struct fb_info*) ; 
 int /*<<< orphan*/  i2c_del_adapter (int /*<<< orphan*/ *) ; 
 struct fb_info* pci_get_drvdata (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_iounmap (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_release_regions (struct pci_dev*) ; 
 int /*<<< orphan*/  unregister_framebuffer (struct fb_info*) ; 

__attribute__((used)) static void i740fb_remove(struct pci_dev *dev)
{
	struct fb_info *info = pci_get_drvdata(dev);

	if (info) {
		struct i740fb_par *par = info->par;
		arch_phys_wc_del(par->wc_cookie);
		unregister_framebuffer(info);
		fb_dealloc_cmap(&info->cmap);
		if (par->ddc_registered)
			i2c_del_adapter(&par->ddc_adapter);
		pci_iounmap(dev, par->regs);
		pci_iounmap(dev, info->screen_base);
		pci_release_regions(dev);
/*		pci_disable_device(dev); */
		framebuffer_release(info);
	}
}