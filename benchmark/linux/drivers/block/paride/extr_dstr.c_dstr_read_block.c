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
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct TYPE_3__ {int mode; } ;
typedef  TYPE_1__ PIA ;

/* Variables and functions */
 int /*<<< orphan*/  P1 ; 
 int /*<<< orphan*/  P2 ; 
 int /*<<< orphan*/  P3 ; 
 char j44 (int,int) ; 
 char r0 () ; 
 int r1 () ; 
 char r4 () ; 
 int /*<<< orphan*/  r4l () ; 
 int /*<<< orphan*/  r4w () ; 
 int /*<<< orphan*/  w0 (int) ; 
 int /*<<< orphan*/  w2 (int) ; 

__attribute__((used)) static void dstr_read_block( PIA *pi, char * buf, int count )

{       int     k, a, b;

        w0(0x81); P1;
        if (pi->mode) { w0(0x19); } else { w0(9); }
	P2; w0(0x82); P1; P3; w0(0x20); P1;

        switch (pi->mode) {

        case 0: for (k=0;k<count;k++) {
                        w2(6); a = r1(); w2(4);
                        w2(6); b = r1(); w2(4);
                        buf[k] = j44(a,b);
                } 
                break;

        case 1: w0(0);
                for (k=0;k<count;k++) {
                        w2(0x26); buf[k] = r0(); w2(0x24);
                }
                w2(4);
                break;

        case 2: w2(0x24); 
                for (k=0;k<count;k++) buf[k] = r4();
                w2(4);
                break;

        case 3: w2(0x24); 
                for (k=0;k<count/2;k++) ((u16 *)buf)[k] = r4w();
                w2(4);
                break;

        case 4: w2(0x24); 
                for (k=0;k<count/4;k++) ((u32 *)buf)[k] = r4l();
                w2(4);
                break;

        }
}