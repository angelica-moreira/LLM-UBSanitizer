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
struct mddev {int /*<<< orphan*/  bitmap; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  isspace (char) ; 
 int /*<<< orphan*/  md_bitmap_dirty_bits (int /*<<< orphan*/ ,unsigned long,unsigned long) ; 
 int /*<<< orphan*/  md_bitmap_unplug (int /*<<< orphan*/ ) ; 
 int mddev_lock (struct mddev*) ; 
 int /*<<< orphan*/  mddev_unlock (struct mddev*) ; 
 unsigned long simple_strtoul (char const*,char**,int /*<<< orphan*/ ) ; 
 char* skip_spaces (char*) ; 

__attribute__((used)) static ssize_t
bitmap_store(struct mddev *mddev, const char *buf, size_t len)
{
	char *end;
	unsigned long chunk, end_chunk;
	int err;

	err = mddev_lock(mddev);
	if (err)
		return err;
	if (!mddev->bitmap)
		goto out;
	/* buf should be <chunk> <chunk> ... or <chunk>-<chunk> ... (range) */
	while (*buf) {
		chunk = end_chunk = simple_strtoul(buf, &end, 0);
		if (buf == end) break;
		if (*end == '-') { /* range */
			buf = end + 1;
			end_chunk = simple_strtoul(buf, &end, 0);
			if (buf == end) break;
		}
		if (*end && !isspace(*end)) break;
		md_bitmap_dirty_bits(mddev->bitmap, chunk, end_chunk);
		buf = skip_spaces(end);
	}
	md_bitmap_unplug(mddev->bitmap); /* flush the bits to disk */
out:
	mddev_unlock(mddev);
	return len;
}