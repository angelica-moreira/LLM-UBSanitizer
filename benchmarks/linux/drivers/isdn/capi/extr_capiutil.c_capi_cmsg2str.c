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
typedef  int /*<<< orphan*/  _cmsg ;
typedef  int /*<<< orphan*/  _cdebbuf ;

/* Variables and functions */
 int /*<<< orphan*/  g_debbuf ; 

_cdebbuf *capi_cmsg2str(_cmsg *cmsg)
{
	return &g_debbuf;
}