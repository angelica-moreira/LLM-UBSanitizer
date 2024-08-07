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
struct omap_sham_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SHA_REG_LENGTH (struct omap_sham_dev*) ; 
 int /*<<< orphan*/  omap_sham_write (struct omap_sham_dev*,int /*<<< orphan*/ ,size_t) ; 

__attribute__((used)) static void omap_sham_trigger_omap4(struct omap_sham_dev *dd, size_t length)
{
	omap_sham_write(dd, SHA_REG_LENGTH(dd), length);
}