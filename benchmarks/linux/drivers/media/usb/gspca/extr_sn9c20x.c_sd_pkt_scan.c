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
typedef  int u8 ;
struct sd {int fmt; int* jpeg_hdr; int pktsz; int /*<<< orphan*/  npkt; int /*<<< orphan*/  avg_lum; } ;
struct gspca_dev {scalar_t__ last_packet_type; } ;

/* Variables and functions */
 scalar_t__ FIRST_PACKET ; 
 scalar_t__ INTER_PACKET ; 
 int JPEG_HDR_SZ ; 
 scalar_t__ LAST_PACKET ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  gspca_frame_add (struct gspca_dev*,scalar_t__,int*,int) ; 
 scalar_t__ memcmp (int*,int const*,int) ; 
 int /*<<< orphan*/  transfer_check (struct gspca_dev*,int*) ; 

__attribute__((used)) static void sd_pkt_scan(struct gspca_dev *gspca_dev,
			u8 *data,			/* isoc packet */
			int len)			/* iso packet length */
{
	struct sd *sd = (struct sd *) gspca_dev;
	int avg_lum, is_jpeg;
	static const u8 frame_header[] = {
		0xff, 0xff, 0x00, 0xc4, 0xc4, 0x96
	};

	is_jpeg = (sd->fmt & 0x03) == 0;
	if (len >= 64 && memcmp(data, frame_header, 6) == 0) {
		avg_lum = ((data[35] >> 2) & 3) |
			   (data[20] << 2) |
			   (data[19] << 10);
		avg_lum += ((data[35] >> 4) & 3) |
			    (data[22] << 2) |
			    (data[21] << 10);
		avg_lum += ((data[35] >> 6) & 3) |
			    (data[24] << 2) |
			    (data[23] << 10);
		avg_lum += (data[36] & 3) |
			   (data[26] << 2) |
			   (data[25] << 10);
		avg_lum += ((data[36] >> 2) & 3) |
			    (data[28] << 2) |
			    (data[27] << 10);
		avg_lum += ((data[36] >> 4) & 3) |
			    (data[30] << 2) |
			    (data[29] << 10);
		avg_lum += ((data[36] >> 6) & 3) |
			    (data[32] << 2) |
			    (data[31] << 10);
		avg_lum += ((data[44] >> 4) & 3) |
			    (data[34] << 2) |
			    (data[33] << 10);
		avg_lum >>= 9;
		atomic_set(&sd->avg_lum, avg_lum);

		if (is_jpeg)
			transfer_check(gspca_dev, data);

		gspca_frame_add(gspca_dev, LAST_PACKET, NULL, 0);
		len -= 64;
		if (len == 0)
			return;
		data += 64;
	}
	if (gspca_dev->last_packet_type == LAST_PACKET) {
		if (is_jpeg) {
			gspca_frame_add(gspca_dev, FIRST_PACKET,
				sd->jpeg_hdr, JPEG_HDR_SZ);
			gspca_frame_add(gspca_dev, INTER_PACKET,
				data, len);
		} else {
			gspca_frame_add(gspca_dev, FIRST_PACKET,
				data, len);
		}
	} else {
		/* if JPEG, count the packets and their size */
		if (is_jpeg) {
			sd->npkt++;
			sd->pktsz += len;
		}
		gspca_frame_add(gspca_dev, INTER_PACKET, data, len);
	}
}