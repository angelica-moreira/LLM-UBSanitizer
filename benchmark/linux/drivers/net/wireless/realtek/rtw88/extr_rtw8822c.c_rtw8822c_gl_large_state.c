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
typedef  int /*<<< orphan*/  u8 ;
struct rtw_dev {int dummy; } ;
struct rtw8822c_dpk_data {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  rtw8822c_gl_state (struct rtw_dev*,struct rtw8822c_dpk_data*,int) ; 

__attribute__((used)) static u8 rtw8822c_gl_large_state(struct rtw_dev *rtwdev,
				  struct rtw8822c_dpk_data *data)
{
	return rtw8822c_gl_state(rtwdev, data, 1);
}