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
typedef  size_t u16 ;
struct qib_devdata {int /*<<< orphan*/ * kregbase; } ;

/* Variables and functions */
 int /*<<< orphan*/  writeq (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void qib_write_kreg(const struct qib_devdata *dd,
				  const u16 regno, u64 value)
{
	if (dd->kregbase)
		writeq(value, &dd->kregbase[regno]);
}