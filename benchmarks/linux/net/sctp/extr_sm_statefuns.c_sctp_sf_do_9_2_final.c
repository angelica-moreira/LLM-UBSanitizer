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
typedef  union sctp_subtype {int dummy; } sctp_subtype ;
struct sctp_ulpevent {int dummy; } ;
struct sctp_endpoint {int dummy; } ;
struct sctp_cmd_seq {int dummy; } ;
struct sctp_chunkhdr {int dummy; } ;
struct sctp_chunk {int dummy; } ;
struct sctp_association {int dummy; } ;
struct net {int dummy; } ;
typedef  enum sctp_disposition { ____Placeholder_sctp_disposition } sctp_disposition ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  SCTP_CHUNK (struct sctp_chunk*) ; 
 int /*<<< orphan*/  SCTP_CMD_DELETE_TCB ; 
 int /*<<< orphan*/  SCTP_CMD_EVENT_ULP ; 
 int /*<<< orphan*/  SCTP_CMD_NEW_STATE ; 
 int /*<<< orphan*/  SCTP_CMD_REPLY ; 
 int /*<<< orphan*/  SCTP_CMD_TIMER_STOP ; 
 int /*<<< orphan*/  SCTP_DEC_STATS (struct net*,int /*<<< orphan*/ ) ; 
 int SCTP_DISPOSITION_DELETE_TCB ; 
 int SCTP_DISPOSITION_NOMEM ; 
 int /*<<< orphan*/  SCTP_EVENT_TIMEOUT_T2_SHUTDOWN ; 
 int /*<<< orphan*/  SCTP_EVENT_TIMEOUT_T5_SHUTDOWN_GUARD ; 
 int /*<<< orphan*/  SCTP_INC_STATS (struct net*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SCTP_MIB_CURRESTAB ; 
 int /*<<< orphan*/  SCTP_MIB_SHUTDOWNS ; 
 int /*<<< orphan*/  SCTP_NULL () ; 
 int /*<<< orphan*/  SCTP_SHUTDOWN_COMP ; 
 int /*<<< orphan*/  SCTP_STATE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SCTP_STATE_CLOSED ; 
 int /*<<< orphan*/  SCTP_TO (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SCTP_ULPEVENT (struct sctp_ulpevent*) ; 
 int /*<<< orphan*/  sctp_add_cmd_sf (struct sctp_cmd_seq*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sctp_chunk_length_valid (struct sctp_chunk*,int) ; 
 struct sctp_chunk* sctp_make_shutdown_complete (struct sctp_association const*,struct sctp_chunk*) ; 
 int sctp_sf_pdiscard (struct net*,struct sctp_endpoint const*,struct sctp_association const*,union sctp_subtype const,void*,struct sctp_cmd_seq*) ; 
 int sctp_sf_violation_chunklen (struct net*,struct sctp_endpoint const*,struct sctp_association const*,union sctp_subtype const,void*,struct sctp_cmd_seq*) ; 
 int /*<<< orphan*/  sctp_ulpevent_free (struct sctp_ulpevent*) ; 
 struct sctp_ulpevent* sctp_ulpevent_make_assoc_change (struct sctp_association const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sctp_vtag_verify (struct sctp_chunk*,struct sctp_association const*) ; 

enum sctp_disposition sctp_sf_do_9_2_final(struct net *net,
					   const struct sctp_endpoint *ep,
					   const struct sctp_association *asoc,
					   const union sctp_subtype type,
					   void *arg,
					   struct sctp_cmd_seq *commands)
{
	struct sctp_chunk *chunk = arg;
	struct sctp_chunk *reply;
	struct sctp_ulpevent *ev;

	if (!sctp_vtag_verify(chunk, asoc))
		return sctp_sf_pdiscard(net, ep, asoc, type, arg, commands);

	/* Make sure that the SHUTDOWN_ACK chunk has a valid length. */
	if (!sctp_chunk_length_valid(chunk, sizeof(struct sctp_chunkhdr)))
		return sctp_sf_violation_chunklen(net, ep, asoc, type, arg,
						  commands);
	/* 10.2 H) SHUTDOWN COMPLETE notification
	 *
	 * When SCTP completes the shutdown procedures (section 9.2) this
	 * notification is passed to the upper layer.
	 */
	ev = sctp_ulpevent_make_assoc_change(asoc, 0, SCTP_SHUTDOWN_COMP,
					     0, 0, 0, NULL, GFP_ATOMIC);
	if (!ev)
		goto nomem;

	/* ...send a SHUTDOWN COMPLETE chunk to its peer, */
	reply = sctp_make_shutdown_complete(asoc, chunk);
	if (!reply)
		goto nomem_chunk;

	/* Do all the commands now (after allocation), so that we
	 * have consistent state if memory allocation failes
	 */
	sctp_add_cmd_sf(commands, SCTP_CMD_EVENT_ULP, SCTP_ULPEVENT(ev));

	/* Upon the receipt of the SHUTDOWN ACK, the SHUTDOWN sender shall
	 * stop the T2-shutdown timer,
	 */
	sctp_add_cmd_sf(commands, SCTP_CMD_TIMER_STOP,
			SCTP_TO(SCTP_EVENT_TIMEOUT_T2_SHUTDOWN));

	sctp_add_cmd_sf(commands, SCTP_CMD_TIMER_STOP,
			SCTP_TO(SCTP_EVENT_TIMEOUT_T5_SHUTDOWN_GUARD));

	sctp_add_cmd_sf(commands, SCTP_CMD_NEW_STATE,
			SCTP_STATE(SCTP_STATE_CLOSED));
	SCTP_INC_STATS(net, SCTP_MIB_SHUTDOWNS);
	SCTP_DEC_STATS(net, SCTP_MIB_CURRESTAB);
	sctp_add_cmd_sf(commands, SCTP_CMD_REPLY, SCTP_CHUNK(reply));

	/* ...and remove all record of the association. */
	sctp_add_cmd_sf(commands, SCTP_CMD_DELETE_TCB, SCTP_NULL());
	return SCTP_DISPOSITION_DELETE_TCB;

nomem_chunk:
	sctp_ulpevent_free(ev);
nomem:
	return SCTP_DISPOSITION_NOMEM;
}