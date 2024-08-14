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
struct vsc73xx_platform {int /*<<< orphan*/  vsc; } ;
struct platform_device {int dummy; } ;

/* Variables and functions */
 struct vsc73xx_platform* platform_get_drvdata (struct platform_device*) ; 
 int vsc73xx_remove (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int vsc73xx_platform_remove(struct platform_device *pdev)
{
	struct vsc73xx_platform *vsc_platform = platform_get_drvdata(pdev);

	return vsc73xx_remove(&vsc_platform->vsc);
}