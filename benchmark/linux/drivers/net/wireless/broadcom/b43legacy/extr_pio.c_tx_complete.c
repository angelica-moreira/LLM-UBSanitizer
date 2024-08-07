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
struct sk_buff {int* data; int len; } ;
struct b43legacy_pioqueue {scalar_t__ need_workarounds; } ;

/* Variables and functions */
 int /*<<< orphan*/  B43legacy_PIO_TXCTL ; 
 int B43legacy_PIO_TXCTL_COMPLETE ; 
 int B43legacy_PIO_TXCTL_WRITELO ; 
 int /*<<< orphan*/  B43legacy_PIO_TXDATA ; 
 int /*<<< orphan*/  b43legacy_pio_write (struct b43legacy_pioqueue*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void tx_complete(struct b43legacy_pioqueue *queue,
			struct sk_buff *skb)
{
	if (queue->need_workarounds) {
		b43legacy_pio_write(queue, B43legacy_PIO_TXDATA,
				    skb->data[skb->len - 1]);
		b43legacy_pio_write(queue, B43legacy_PIO_TXCTL,
				    B43legacy_PIO_TXCTL_WRITELO |
				    B43legacy_PIO_TXCTL_COMPLETE);
	} else
		b43legacy_pio_write(queue, B43legacy_PIO_TXCTL,
				    B43legacy_PIO_TXCTL_COMPLETE);
}