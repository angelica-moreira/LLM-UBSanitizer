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
struct wil_fw_record_data {int /*<<< orphan*/  addr; } ;
struct wil6210_priv {int dummy; } ;

/* Variables and functions */
 int __fw_handle_data (struct wil6210_priv*,void const*,size_t,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int fw_handle_data(struct wil6210_priv *wil, const void *data,
			  size_t size)
{
	const struct wil_fw_record_data *d = data;

	return __fw_handle_data(wil, data, size, d->addr);
}