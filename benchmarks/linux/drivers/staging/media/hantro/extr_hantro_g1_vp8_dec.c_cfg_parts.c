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
typedef  int u32 ;
struct vb2_v4l2_buffer {int /*<<< orphan*/  vb2_buf; } ;
struct v4l2_ctrl_vp8_frame_header {int first_part_header_bits; int first_part_size; int num_dct_parts; int* dct_part_sizes; } ;
struct hantro_reg {int mask; int shift; void* base; } ;
struct hantro_dev {int dummy; } ;
struct hantro_ctx {struct hantro_dev* dev; } ;
typedef  int dma_addr_t ;

/* Variables and functions */
 int DEC_8190_ALIGN_MASK ; 
 int /*<<< orphan*/  G1_REG_ADDR_REF (int) ; 
 void* G1_REG_DEC_CTRL2 ; 
 int /*<<< orphan*/  G1_REG_DEC_CTRL3 ; 
 int G1_REG_DEC_CTRL3_STREAM_LEN (int) ; 
 void* G1_REG_DEC_CTRL6 ; 
 scalar_t__ VP8_FRAME_IS_KEY_FRAME (struct v4l2_ctrl_vp8_frame_header const*) ; 
 struct vb2_v4l2_buffer* hantro_get_src_buf (struct hantro_ctx*) ; 
 int /*<<< orphan*/  hantro_reg_write (struct hantro_dev*,struct hantro_reg*,int) ; 
 int vb2_dma_contig_plane_dma_addr (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vdpu_write_relaxed (struct hantro_dev*,int,int /*<<< orphan*/ ) ; 
 struct hantro_reg* vp8_dec_dct_base ; 
 struct hantro_reg* vp8_dec_dct_start_bits ; 

__attribute__((used)) static void cfg_parts(struct hantro_ctx *ctx,
		      const struct v4l2_ctrl_vp8_frame_header *hdr)
{
	struct hantro_dev *vpu = ctx->dev;
	struct vb2_v4l2_buffer *vb2_src;
	u32 first_part_offset = VP8_FRAME_IS_KEY_FRAME(hdr) ? 10 : 3;
	u32 mb_size, mb_offset_bytes, mb_offset_bits, mb_start_bits;
	u32 dct_size_part_size, dct_part_offset;
	struct hantro_reg reg;
	dma_addr_t src_dma;
	u32 dct_part_total_len = 0;
	u32 count = 0;
	unsigned int i;

	vb2_src = hantro_get_src_buf(ctx);
	src_dma = vb2_dma_contig_plane_dma_addr(&vb2_src->vb2_buf, 0);

	/*
	 * Calculate control partition mb data info
	 * @first_part_header_bits:	bits offset of mb data from first
	 *				part start pos
	 * @mb_offset_bits:		bits offset of mb data from src_dma
	 *				base addr
	 * @mb_offset_byte:		bytes offset of mb data from src_dma
	 *				base addr
	 * @mb_start_bits:		bits offset of mb data from mb data
	 *				64bits alignment addr
	 */
	mb_offset_bits = first_part_offset * 8 +
			 hdr->first_part_header_bits + 8;
	mb_offset_bytes = mb_offset_bits / 8;
	mb_start_bits = mb_offset_bits -
			(mb_offset_bytes & (~DEC_8190_ALIGN_MASK)) * 8;
	mb_size = hdr->first_part_size -
		  (mb_offset_bytes - first_part_offset) +
		  (mb_offset_bytes & DEC_8190_ALIGN_MASK);

	/* Macroblock data aligned base addr */
	vdpu_write_relaxed(vpu, (mb_offset_bytes & (~DEC_8190_ALIGN_MASK))
				+ src_dma, G1_REG_ADDR_REF(13));

	/* Macroblock data start bits */
	reg.base = G1_REG_DEC_CTRL2;
	reg.mask = 0x3f;
	reg.shift = 18;
	hantro_reg_write(vpu, &reg, mb_start_bits);

	/* Macroblock aligned data length */
	reg.base = G1_REG_DEC_CTRL6;
	reg.mask = 0x3fffff;
	reg.shift = 0;
	hantro_reg_write(vpu, &reg, mb_size + 1);

	/*
	 * Calculate DCT partition info
	 * @dct_size_part_size: Containing sizes of DCT part, every DCT part
	 *			has 3 bytes to store its size, except the last
	 *			DCT part
	 * @dct_part_offset:	bytes offset of DCT parts from src_dma base addr
	 * @dct_part_total_len: total size of all DCT parts
	 */
	dct_size_part_size = (hdr->num_dct_parts - 1) * 3;
	dct_part_offset = first_part_offset + hdr->first_part_size;
	for (i = 0; i < hdr->num_dct_parts; i++)
		dct_part_total_len += hdr->dct_part_sizes[i];
	dct_part_total_len += dct_size_part_size;
	dct_part_total_len += (dct_part_offset & DEC_8190_ALIGN_MASK);

	/* Number of DCT partitions */
	reg.base = G1_REG_DEC_CTRL6;
	reg.mask = 0xf;
	reg.shift = 24;
	hantro_reg_write(vpu, &reg, hdr->num_dct_parts - 1);

	/* DCT partition length */
	vdpu_write_relaxed(vpu,
			   G1_REG_DEC_CTRL3_STREAM_LEN(dct_part_total_len),
			   G1_REG_DEC_CTRL3);

	/* DCT partitions base address */
	for (i = 0; i < hdr->num_dct_parts; i++) {
		u32 byte_offset = dct_part_offset + dct_size_part_size + count;
		u32 base_addr = byte_offset + src_dma;

		hantro_reg_write(vpu, &vp8_dec_dct_base[i],
				 base_addr & (~DEC_8190_ALIGN_MASK));

		hantro_reg_write(vpu, &vp8_dec_dct_start_bits[i],
				 (byte_offset & DEC_8190_ALIGN_MASK) * 8);

		count += hdr->dct_part_sizes[i];
	}
}