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
typedef  int U32 ;
typedef  int /*<<< orphan*/  BYTE ;

/* Variables and functions */
 size_t ERROR (int /*<<< orphan*/ ) ; 
 int FSE_MIN_TABLELOG ; 
 int FSE_TABLELOG_ABSOLUTE_MAX ; 
 int ZSTD_readLE32 (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  corruption_detected ; 
 int /*<<< orphan*/  maxSymbolValue_tooSmall ; 
 int /*<<< orphan*/  srcSize_wrong ; 
 int /*<<< orphan*/  tableLog_tooLarge ; 

size_t FSE_readNCount(short *normalizedCounter, unsigned *maxSVPtr, unsigned *tableLogPtr, const void *headerBuffer, size_t hbSize)
{
	const BYTE *const istart = (const BYTE *)headerBuffer;
	const BYTE *const iend = istart + hbSize;
	const BYTE *ip = istart;
	int nbBits;
	int remaining;
	int threshold;
	U32 bitStream;
	int bitCount;
	unsigned charnum = 0;
	int previous0 = 0;

	if (hbSize < 4)
		return ERROR(srcSize_wrong);
	bitStream = ZSTD_readLE32(ip);
	nbBits = (bitStream & 0xF) + FSE_MIN_TABLELOG; /* extract tableLog */
	if (nbBits > FSE_TABLELOG_ABSOLUTE_MAX)
		return ERROR(tableLog_tooLarge);
	bitStream >>= 4;
	bitCount = 4;
	*tableLogPtr = nbBits;
	remaining = (1 << nbBits) + 1;
	threshold = 1 << nbBits;
	nbBits++;

	while ((remaining > 1) & (charnum <= *maxSVPtr)) {
		if (previous0) {
			unsigned n0 = charnum;
			while ((bitStream & 0xFFFF) == 0xFFFF) {
				n0 += 24;
				if (ip < iend - 5) {
					ip += 2;
					bitStream = ZSTD_readLE32(ip) >> bitCount;
				} else {
					bitStream >>= 16;
					bitCount += 16;
				}
			}
			while ((bitStream & 3) == 3) {
				n0 += 3;
				bitStream >>= 2;
				bitCount += 2;
			}
			n0 += bitStream & 3;
			bitCount += 2;
			if (n0 > *maxSVPtr)
				return ERROR(maxSymbolValue_tooSmall);
			while (charnum < n0)
				normalizedCounter[charnum++] = 0;
			if ((ip <= iend - 7) || (ip + (bitCount >> 3) <= iend - 4)) {
				ip += bitCount >> 3;
				bitCount &= 7;
				bitStream = ZSTD_readLE32(ip) >> bitCount;
			} else {
				bitStream >>= 2;
			}
		}
		{
			int const max = (2 * threshold - 1) - remaining;
			int count;

			if ((bitStream & (threshold - 1)) < (U32)max) {
				count = bitStream & (threshold - 1);
				bitCount += nbBits - 1;
			} else {
				count = bitStream & (2 * threshold - 1);
				if (count >= threshold)
					count -= max;
				bitCount += nbBits;
			}

			count--;				 /* extra accuracy */
			remaining -= count < 0 ? -count : count; /* -1 means +1 */
			normalizedCounter[charnum++] = (short)count;
			previous0 = !count;
			while (remaining < threshold) {
				nbBits--;
				threshold >>= 1;
			}

			if ((ip <= iend - 7) || (ip + (bitCount >> 3) <= iend - 4)) {
				ip += bitCount >> 3;
				bitCount &= 7;
			} else {
				bitCount -= (int)(8 * (iend - 4 - ip));
				ip = iend - 4;
			}
			bitStream = ZSTD_readLE32(ip) >> (bitCount & 31);
		}
	} /* while ((remaining>1) & (charnum<=*maxSVPtr)) */
	if (remaining != 1)
		return ERROR(corruption_detected);
	if (bitCount > 32)
		return ERROR(corruption_detected);
	*maxSVPtr = charnum - 1;

	ip += (bitCount + 7) >> 3;
	return ip - istart;
}