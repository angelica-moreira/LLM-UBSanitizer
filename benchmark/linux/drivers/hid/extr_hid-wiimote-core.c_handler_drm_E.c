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
struct wiimote_data {int dummy; } ;
typedef  int /*<<< orphan*/  __u8 ;

/* Variables and functions */
 int /*<<< orphan*/  handler_ext (struct wiimote_data*,int /*<<< orphan*/  const*,int) ; 

__attribute__((used)) static void handler_drm_E(struct wiimote_data *wdata, const __u8 *payload)
{
	handler_ext(wdata, payload, 21);
}