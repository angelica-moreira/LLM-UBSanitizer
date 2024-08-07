#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_1__* scif_epd_t ;
struct TYPE_3__ {int /*<<< orphan*/  anon; } ;

/* Variables and functions */
 int PTR_ERR_OR_ZERO (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  anon_inode_getfile (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  scif_anon_fops ; 

__attribute__((used)) static inline int scif_anon_inode_getfile(scif_epd_t epd)
{
	epd->anon = anon_inode_getfile("scif", &scif_anon_fops, NULL, 0);

	return PTR_ERR_OR_ZERO(epd->anon);
}