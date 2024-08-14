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
typedef  int /*<<< orphan*/  u16 ;
struct ssb_gige {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  ssb_read16 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline u16 gige_read16(struct ssb_gige *dev, u16 offset)
{
	return ssb_read16(dev->dev, offset);
}