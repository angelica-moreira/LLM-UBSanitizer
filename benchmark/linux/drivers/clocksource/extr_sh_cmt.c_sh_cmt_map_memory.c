#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct sh_cmt_device {TYPE_1__* pdev; int /*<<< orphan*/ * mapbase; } ;
struct resource {int /*<<< orphan*/  start; } ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int ENXIO ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/ * ioremap_nocache (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  resource_size (struct resource*) ; 

__attribute__((used)) static int sh_cmt_map_memory(struct sh_cmt_device *cmt)
{
	struct resource *mem;

	mem = platform_get_resource(cmt->pdev, IORESOURCE_MEM, 0);
	if (!mem) {
		dev_err(&cmt->pdev->dev, "failed to get I/O memory\n");
		return -ENXIO;
	}

	cmt->mapbase = ioremap_nocache(mem->start, resource_size(mem));
	if (cmt->mapbase == NULL) {
		dev_err(&cmt->pdev->dev, "failed to remap I/O memory\n");
		return -ENXIO;
	}

	return 0;
}