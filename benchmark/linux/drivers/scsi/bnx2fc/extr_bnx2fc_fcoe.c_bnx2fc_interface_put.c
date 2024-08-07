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
struct bnx2fc_interface {int /*<<< orphan*/  kref; } ;

/* Variables and functions */
 int /*<<< orphan*/  bnx2fc_interface_release ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void bnx2fc_interface_put(struct bnx2fc_interface *interface)
{
	kref_put(&interface->kref, bnx2fc_interface_release);
}