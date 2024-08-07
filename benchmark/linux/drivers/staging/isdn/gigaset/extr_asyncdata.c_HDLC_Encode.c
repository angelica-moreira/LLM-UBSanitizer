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
struct sk_buff {unsigned char* data; int len; scalar_t__ mac_len; } ;
typedef  int __u16 ;

/* Variables and functions */
 unsigned char PPP_ESCAPE ; 
 unsigned char PPP_FLAG ; 
 int PPP_INITFCS ; 
 unsigned char PPP_TRANS ; 
 int crc_ccitt_byte (int,int /*<<< orphan*/ ) ; 
 struct sk_buff* dev_alloc_skb (scalar_t__) ; 
 int /*<<< orphan*/  dev_kfree_skb_any (struct sk_buff*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ muststuff (unsigned char) ; 
 int /*<<< orphan*/  skb_mac_header (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_put_u8 (struct sk_buff*,unsigned char) ; 
 int /*<<< orphan*/  skb_reserve (struct sk_buff*,scalar_t__) ; 
 int /*<<< orphan*/  skb_reset_mac_header (struct sk_buff*) ; 

__attribute__((used)) static struct sk_buff *HDLC_Encode(struct sk_buff *skb)
{
	struct sk_buff *hdlc_skb;
	__u16 fcs;
	unsigned char c;
	unsigned char *cp;
	int len;
	unsigned int stuf_cnt;

	stuf_cnt = 0;
	fcs = PPP_INITFCS;
	cp = skb->data;
	len = skb->len;
	while (len--) {
		if (muststuff(*cp))
			stuf_cnt++;
		fcs = crc_ccitt_byte(fcs, *cp++);
	}
	fcs ^= 0xffff;			/* complement */

	/* size of new buffer: original size + number of stuffing bytes
	 * + 2 bytes FCS + 2 stuffing bytes for FCS (if needed) + 2 flag bytes
	 * + room for link layer header
	 */
	hdlc_skb = dev_alloc_skb(skb->len + stuf_cnt + 6 + skb->mac_len);
	if (!hdlc_skb) {
		dev_kfree_skb_any(skb);
		return NULL;
	}

	/* Copy link layer header into new skb */
	skb_reset_mac_header(hdlc_skb);
	skb_reserve(hdlc_skb, skb->mac_len);
	memcpy(skb_mac_header(hdlc_skb), skb_mac_header(skb), skb->mac_len);
	hdlc_skb->mac_len = skb->mac_len;

	/* Add flag sequence in front of everything.. */
	skb_put_u8(hdlc_skb, PPP_FLAG);

	/* Perform byte stuffing while copying data. */
	while (skb->len--) {
		if (muststuff(*skb->data)) {
			skb_put_u8(hdlc_skb, PPP_ESCAPE);
			skb_put_u8(hdlc_skb, (*skb->data++) ^ PPP_TRANS);
		} else
			skb_put_u8(hdlc_skb, *skb->data++);
	}

	/* Finally add FCS (byte stuffed) and flag sequence */
	c = (fcs & 0x00ff);	/* least significant byte first */
	if (muststuff(c)) {
		skb_put_u8(hdlc_skb, PPP_ESCAPE);
		c ^= PPP_TRANS;
	}
	skb_put_u8(hdlc_skb, c);

	c = ((fcs >> 8) & 0x00ff);
	if (muststuff(c)) {
		skb_put_u8(hdlc_skb, PPP_ESCAPE);
		c ^= PPP_TRANS;
	}
	skb_put_u8(hdlc_skb, c);

	skb_put_u8(hdlc_skb, PPP_FLAG);

	dev_kfree_skb_any(skb);
	return hdlc_skb;
}