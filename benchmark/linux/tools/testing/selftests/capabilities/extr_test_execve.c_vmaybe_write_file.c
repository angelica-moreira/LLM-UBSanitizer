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
typedef  int /*<<< orphan*/  va_list ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
 scalar_t__ ENOENT ; 
 int /*<<< orphan*/  O_WRONLY ; 
 scalar_t__ close (int) ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  ksft_exit_fail_msg (char*,...) ; 
 int open (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strerror (scalar_t__) ; 
 int vsnprintf (char*,int,char*,int /*<<< orphan*/ ) ; 
 int write (int,char*,int) ; 

__attribute__((used)) static void vmaybe_write_file(bool enoent_ok, char *filename, char *fmt, va_list ap)
{
	char buf[4096];
	int fd;
	ssize_t written;
	int buf_len;

	buf_len = vsnprintf(buf, sizeof(buf), fmt, ap);
	if (buf_len < 0)
		ksft_exit_fail_msg("vsnprintf failed - %s\n", strerror(errno));

	if (buf_len >= sizeof(buf))
		ksft_exit_fail_msg("vsnprintf output truncated\n");


	fd = open(filename, O_WRONLY);
	if (fd < 0) {
		if ((errno == ENOENT) && enoent_ok)
			return;
		ksft_exit_fail_msg("open of %s failed - %s\n",
					filename, strerror(errno));
	}
	written = write(fd, buf, buf_len);
	if (written != buf_len) {
		if (written >= 0) {
			ksft_exit_fail_msg("short write to %s\n", filename);
		} else {
			ksft_exit_fail_msg("write to %s failed - %s\n",
						filename, strerror(errno));
		}
	}
	if (close(fd) != 0) {
		ksft_exit_fail_msg("close of %s failed - %s\n",
					filename, strerror(errno));
	}
}