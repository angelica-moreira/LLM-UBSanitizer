#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int mode; } ;
typedef  TYPE_1__ PIA ;

/* Variables and functions */
 int /*<<< orphan*/  w0 (int) ; 
 int /*<<< orphan*/  w2 (int) ; 
 int /*<<< orphan*/  w4 (int) ; 

__attribute__((used)) static void  fit3_write_regr( PIA *pi, int cont, int regr, int val)

{	if (cont == 1) return;

	switch (pi->mode) {

	case 0:
	case 1: w2(0xc); w0(regr); w2(0x8); w2(0xc); 
		w0(val); w2(0xd); 
		w0(0);   w2(0xc);
		break;

	case 2: w2(0xc); w0(regr); w2(0x8); w2(0xc);
		w4(val); w4(0);
		w2(0xc);
		break;

	}
}