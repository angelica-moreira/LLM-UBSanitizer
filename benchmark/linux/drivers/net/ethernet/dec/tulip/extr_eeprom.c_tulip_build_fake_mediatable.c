#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct tulip_private {int flags; int csr12_shadow; TYPE_2__* mtable; } ;
struct mediatable {int dummy; } ;
struct medialeaf {int dummy; } ;
struct TYPE_4__ {int defaultmedia; int leafcount; int csr12dir; int has_mii; TYPE_1__* mleaf; scalar_t__ csr15val; scalar_t__ csr15dir; scalar_t__ has_reset; scalar_t__ has_nonmii; } ;
struct TYPE_3__ {int type; int media; unsigned char* leafdata; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HAS_PHY_IRQ ; 
 int NEEDS_FAKE_MEDIA_TABLE ; 
 TYPE_2__* kmalloc (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void tulip_build_fake_mediatable(struct tulip_private *tp)
{
#ifdef CONFIG_GSC
	if (tp->flags & NEEDS_FAKE_MEDIA_TABLE) {
		static unsigned char leafdata[] =
			{ 0x01,       /* phy number */
			  0x02,       /* gpr setup sequence length */
			  0x02, 0x00, /* gpr setup sequence */
			  0x02,       /* phy reset sequence length */
			  0x01, 0x00, /* phy reset sequence */
			  0x00, 0x78, /* media capabilities */
			  0x00, 0xe0, /* nway advertisement */
			  0x00, 0x05, /* fdx bit map */
			  0x00, 0x06  /* ttm bit map */
			};

		tp->mtable = kmalloc(sizeof(struct mediatable) +
				     sizeof(struct medialeaf), GFP_KERNEL);

		if (tp->mtable == NULL)
			return; /* Horrible, impossible failure. */

		tp->mtable->defaultmedia = 0x800;
		tp->mtable->leafcount = 1;
		tp->mtable->csr12dir = 0x3f; /* inputs on bit7 for hsc-pci, bit6 for pci-fx */
		tp->mtable->has_nonmii = 0;
		tp->mtable->has_reset = 0;
		tp->mtable->has_mii = 1;
		tp->mtable->csr15dir = tp->mtable->csr15val = 0;
		tp->mtable->mleaf[0].type = 1;
		tp->mtable->mleaf[0].media = 11;
		tp->mtable->mleaf[0].leafdata = &leafdata[0];
		tp->flags |= HAS_PHY_IRQ;
		tp->csr12_shadow = -1;
	}
#endif
}