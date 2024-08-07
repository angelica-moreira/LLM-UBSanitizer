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
struct usbhs_priv {int dummy; } ;
struct usbhs_pipe {int dummy; } ;

/* Variables and functions */
 scalar_t__ DCPCTR ; 
 scalar_t__ PIPEnCTR ; 
 int /*<<< orphan*/  usbhs_bset (struct usbhs_priv*,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ usbhs_pipe_is_dcp (struct usbhs_pipe*) ; 
 struct usbhs_priv* usbhs_pipe_to_priv (struct usbhs_pipe*) ; 
 int usbhsp_addr_offset (struct usbhs_pipe*) ; 

__attribute__((used)) static void usbhsp_pipectrl_set(struct usbhs_pipe *pipe, u16 mask, u16 val)
{
	struct usbhs_priv *priv = usbhs_pipe_to_priv(pipe);
	int offset = usbhsp_addr_offset(pipe);

	if (usbhs_pipe_is_dcp(pipe))
		usbhs_bset(priv, DCPCTR, mask, val);
	else
		usbhs_bset(priv, PIPEnCTR + offset, mask, val);
}