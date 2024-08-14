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
struct inbuf_t {struct cardstate* cs; } ;
struct cardstate {unsigned int cbytes; char* respdata; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  DEBUG_TRANSCMD ; 
 unsigned int MAX_RESP_SIZE ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*,unsigned int) ; 
 int /*<<< orphan*/  gigaset_dbg_buffer (int /*<<< orphan*/ ,char*,unsigned int,char*) ; 
 int /*<<< orphan*/  gigaset_handle_modem_response (struct cardstate*) ; 

__attribute__((used)) static void cmd_loop(unsigned char *src, int numbytes, struct inbuf_t *inbuf)
{
	struct cardstate *cs = inbuf->cs;
	unsigned cbytes      = cs->cbytes;
	unsigned char c;

	while (numbytes--) {
		c = *src++;
		switch (c) {
		case '\n':
			if (cbytes == 0 && cs->respdata[0] == '\r') {
				/* collapse LF with preceding CR */
				cs->respdata[0] = 0;
				break;
			}
			/* fall through */
		case '\r':
			/* end of message line, pass to response handler */
			if (cbytes >= MAX_RESP_SIZE) {
				dev_warn(cs->dev, "response too large (%d)\n",
					 cbytes);
				cbytes = MAX_RESP_SIZE;
			}
			cs->cbytes = cbytes;
			gigaset_dbg_buffer(DEBUG_TRANSCMD, "received response",
					   cbytes, cs->respdata);
			gigaset_handle_modem_response(cs);
			cbytes = 0;

			/* store EOL byte for CRLF collapsing */
			cs->respdata[0] = c;
			break;
		default:
			/* append to line buffer if possible */
			if (cbytes < MAX_RESP_SIZE)
				cs->respdata[cbytes] = c;
			cbytes++;
		}
	}

	/* save state */
	cs->cbytes = cbytes;
}