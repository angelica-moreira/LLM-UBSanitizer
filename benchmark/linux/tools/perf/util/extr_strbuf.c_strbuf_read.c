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
struct strbuf {size_t len; size_t alloc; char* buf; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int read (int,char*,size_t) ; 
 int strbuf_grow (struct strbuf*,int) ; 
 int /*<<< orphan*/  strbuf_release (struct strbuf*) ; 
 int /*<<< orphan*/  strbuf_setlen (struct strbuf*,size_t) ; 

ssize_t strbuf_read(struct strbuf *sb, int fd, ssize_t hint)
{
	size_t oldlen = sb->len;
	size_t oldalloc = sb->alloc;
	int ret;

	ret = strbuf_grow(sb, hint ? hint : 8192);
	if (ret)
		return ret;

	for (;;) {
		ssize_t cnt;

		cnt = read(fd, sb->buf + sb->len, sb->alloc - sb->len - 1);
		if (cnt < 0) {
			if (oldalloc == 0)
				strbuf_release(sb);
			else
				strbuf_setlen(sb, oldlen);
			return cnt;
		}
		if (!cnt)
			break;
		sb->len += cnt;
		ret = strbuf_grow(sb, 8192);
		if (ret)
			return ret;
	}

	sb->buf[sb->len] = '\0';
	return sb->len - oldlen;
}