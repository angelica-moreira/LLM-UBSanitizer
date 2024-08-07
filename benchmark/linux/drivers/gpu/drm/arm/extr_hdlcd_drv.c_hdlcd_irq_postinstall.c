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
struct hdlcd_drm_private {int dummy; } ;
struct drm_device {struct hdlcd_drm_private* dev_private; } ;

/* Variables and functions */
 unsigned long HDLCD_DEBUG_INT_MASK ; 
 int /*<<< orphan*/  HDLCD_REG_INT_MASK ; 
 unsigned long hdlcd_read (struct hdlcd_drm_private*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hdlcd_write (struct hdlcd_drm_private*,int /*<<< orphan*/ ,unsigned long) ; 

__attribute__((used)) static int hdlcd_irq_postinstall(struct drm_device *drm)
{
#ifdef CONFIG_DEBUG_FS
	struct hdlcd_drm_private *hdlcd = drm->dev_private;
	unsigned long irq_mask = hdlcd_read(hdlcd, HDLCD_REG_INT_MASK);

	/* enable debug interrupts */
	irq_mask |= HDLCD_DEBUG_INT_MASK;

	hdlcd_write(hdlcd, HDLCD_REG_INT_MASK, irq_mask);
#endif
	return 0;
}