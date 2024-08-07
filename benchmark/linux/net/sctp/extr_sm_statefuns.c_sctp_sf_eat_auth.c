#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  union sctp_subtype {int dummy; } sctp_subtype ;
struct sctp_ulpevent {int dummy; } ;
struct sctp_endpoint {int dummy; } ;
struct sctp_cmd_seq {int dummy; } ;
struct sctp_chunk {TYPE_2__* skb; } ;
struct sctp_authhdr {int /*<<< orphan*/  shkey_id; int /*<<< orphan*/  hmac_id; } ;
struct sctp_auth_chunk {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  auth_capable; } ;
struct sctp_association {scalar_t__ active_key_id; TYPE_1__ peer; } ;
struct net {int dummy; } ;
typedef  enum sctp_ierror { ____Placeholder_sctp_ierror } sctp_ierror ;
typedef  enum sctp_disposition { ____Placeholder_sctp_disposition } sctp_disposition ;
typedef  int /*<<< orphan*/  __u16 ;
struct TYPE_4__ {scalar_t__ data; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  SCTP_AUTH_NEW_KEY ; 
 int /*<<< orphan*/  SCTP_CHUNK (struct sctp_chunk*) ; 
 int /*<<< orphan*/  SCTP_CMD_EVENT_ULP ; 
 int /*<<< orphan*/  SCTP_CMD_REPLY ; 
 int /*<<< orphan*/  SCTP_CMD_REPORT_BAD_TAG ; 
 int SCTP_DISPOSITION_CONSUME ; 
 int SCTP_DISPOSITION_NOMEM ; 
 int /*<<< orphan*/  SCTP_ERROR_UNSUP_HMAC ; 
#define  SCTP_IERROR_AUTH_BAD_HMAC 132 
#define  SCTP_IERROR_AUTH_BAD_KEYID 131 
#define  SCTP_IERROR_BAD_SIG 130 
#define  SCTP_IERROR_NOMEM 129 
#define  SCTP_IERROR_PROTO_VIOLATION 128 
 int /*<<< orphan*/  SCTP_NULL () ; 
 int /*<<< orphan*/  SCTP_ULPEVENT (struct sctp_ulpevent*) ; 
 scalar_t__ ntohs (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sctp_add_cmd_sf (struct sctp_cmd_seq*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sctp_chunk_length_valid (struct sctp_chunk*,int) ; 
 struct sctp_chunk* sctp_make_op_error (struct sctp_association const*,struct sctp_chunk*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int sctp_sf_authenticate (struct sctp_association const*,struct sctp_chunk*) ; 
 int sctp_sf_pdiscard (struct net*,struct sctp_endpoint const*,struct sctp_association const*,union sctp_subtype const,void*,struct sctp_cmd_seq*) ; 
 int sctp_sf_unk_chunk (struct net*,struct sctp_endpoint const*,struct sctp_association const*,union sctp_subtype const,void*,struct sctp_cmd_seq*) ; 
 int sctp_sf_violation_chunklen (struct net*,struct sctp_endpoint const*,struct sctp_association const*,union sctp_subtype const,void*,struct sctp_cmd_seq*) ; 
 struct sctp_ulpevent* sctp_ulpevent_make_authkey (struct sctp_association const*,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sctp_vtag_verify (struct sctp_chunk*,struct sctp_association const*) ; 

enum sctp_disposition sctp_sf_eat_auth(struct net *net,
				       const struct sctp_endpoint *ep,
				       const struct sctp_association *asoc,
				       const union sctp_subtype type,
				       void *arg, struct sctp_cmd_seq *commands)
{
	struct sctp_chunk *chunk = arg;
	struct sctp_authhdr *auth_hdr;
	struct sctp_chunk *err_chunk;
	enum sctp_ierror error;

	/* Make sure that the peer has AUTH capable */
	if (!asoc->peer.auth_capable)
		return sctp_sf_unk_chunk(net, ep, asoc, type, arg, commands);

	if (!sctp_vtag_verify(chunk, asoc)) {
		sctp_add_cmd_sf(commands, SCTP_CMD_REPORT_BAD_TAG,
				SCTP_NULL());
		return sctp_sf_pdiscard(net, ep, asoc, type, arg, commands);
	}

	/* Make sure that the AUTH chunk has valid length.  */
	if (!sctp_chunk_length_valid(chunk, sizeof(struct sctp_auth_chunk)))
		return sctp_sf_violation_chunklen(net, ep, asoc, type, arg,
						  commands);

	auth_hdr = (struct sctp_authhdr *)chunk->skb->data;
	error = sctp_sf_authenticate(asoc, chunk);
	switch (error) {
	case SCTP_IERROR_AUTH_BAD_HMAC:
		/* Generate the ERROR chunk and discard the rest
		 * of the packet
		 */
		err_chunk = sctp_make_op_error(asoc, chunk,
					       SCTP_ERROR_UNSUP_HMAC,
					       &auth_hdr->hmac_id,
					       sizeof(__u16), 0);
		if (err_chunk) {
			sctp_add_cmd_sf(commands, SCTP_CMD_REPLY,
					SCTP_CHUNK(err_chunk));
		}
		/* Fall Through */
	case SCTP_IERROR_AUTH_BAD_KEYID:
	case SCTP_IERROR_BAD_SIG:
		return sctp_sf_pdiscard(net, ep, asoc, type, arg, commands);

	case SCTP_IERROR_PROTO_VIOLATION:
		return sctp_sf_violation_chunklen(net, ep, asoc, type, arg,
						  commands);

	case SCTP_IERROR_NOMEM:
		return SCTP_DISPOSITION_NOMEM;

	default:			/* Prevent gcc warnings */
		break;
	}

	if (asoc->active_key_id != ntohs(auth_hdr->shkey_id)) {
		struct sctp_ulpevent *ev;

		ev = sctp_ulpevent_make_authkey(asoc, ntohs(auth_hdr->shkey_id),
				    SCTP_AUTH_NEW_KEY, GFP_ATOMIC);

		if (!ev)
			return -ENOMEM;

		sctp_add_cmd_sf(commands, SCTP_CMD_EVENT_ULP,
				SCTP_ULPEVENT(ev));
	}

	return SCTP_DISPOSITION_CONSUME;
}