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
typedef  int /*<<< orphan*/  u64 ;
struct cxl {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CXL_PSL9_Timebase ; 
 int /*<<< orphan*/  cxl_p1_read (struct cxl*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static u64 timebase_read_psl9(struct cxl *adapter)
{
	return cxl_p1_read(adapter, CXL_PSL9_Timebase);
}