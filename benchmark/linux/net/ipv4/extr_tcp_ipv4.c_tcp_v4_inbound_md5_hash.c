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
typedef  union tcp_md5_addr {int dummy; } tcp_md5_addr ;
struct tcphdr {int /*<<< orphan*/  dest; int /*<<< orphan*/  source; } ;
struct tcp_md5sig_key {int dummy; } ;
struct sock {int dummy; } ;
struct sk_buff {int dummy; } ;
struct iphdr {int /*<<< orphan*/  daddr; int /*<<< orphan*/  saddr; } ;
typedef  int /*<<< orphan*/  __u8 ;

/* Variables and functions */
 int /*<<< orphan*/  AF_INET ; 
 int /*<<< orphan*/  LINUX_MIB_TCPMD5FAILURE ; 
 int /*<<< orphan*/  LINUX_MIB_TCPMD5NOTFOUND ; 
 int /*<<< orphan*/  LINUX_MIB_TCPMD5UNEXPECTED ; 
 int /*<<< orphan*/  NET_INC_STATS (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct iphdr* ip_hdr (struct sk_buff const*) ; 
 scalar_t__ memcmp (int /*<<< orphan*/  const*,unsigned char*,int) ; 
 int /*<<< orphan*/  net_info_ratelimited (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  ntohs (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sock_net (struct sock const*) ; 
 struct tcphdr* tcp_hdr (struct sk_buff const*) ; 
 struct tcp_md5sig_key* tcp_md5_do_lookup (struct sock const*,union tcp_md5_addr*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * tcp_parse_md5sig_option (struct tcphdr const*) ; 
 int tcp_v4_md5_hash_skb (unsigned char*,struct tcp_md5sig_key*,int /*<<< orphan*/ *,struct sk_buff const*) ; 

__attribute__((used)) static bool tcp_v4_inbound_md5_hash(const struct sock *sk,
				    const struct sk_buff *skb)
{
#ifdef CONFIG_TCP_MD5SIG
	/*
	 * This gets called for each TCP segment that arrives
	 * so we want to be efficient.
	 * We have 3 drop cases:
	 * o No MD5 hash and one expected.
	 * o MD5 hash and we're not expecting one.
	 * o MD5 hash and its wrong.
	 */
	const __u8 *hash_location = NULL;
	struct tcp_md5sig_key *hash_expected;
	const struct iphdr *iph = ip_hdr(skb);
	const struct tcphdr *th = tcp_hdr(skb);
	int genhash;
	unsigned char newhash[16];

	hash_expected = tcp_md5_do_lookup(sk, (union tcp_md5_addr *)&iph->saddr,
					  AF_INET);
	hash_location = tcp_parse_md5sig_option(th);

	/* We've parsed the options - do we have a hash? */
	if (!hash_expected && !hash_location)
		return false;

	if (hash_expected && !hash_location) {
		NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPMD5NOTFOUND);
		return true;
	}

	if (!hash_expected && hash_location) {
		NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPMD5UNEXPECTED);
		return true;
	}

	/* Okay, so this is hash_expected and hash_location -
	 * so we need to calculate the checksum.
	 */
	genhash = tcp_v4_md5_hash_skb(newhash,
				      hash_expected,
				      NULL, skb);

	if (genhash || memcmp(hash_location, newhash, 16) != 0) {
		NET_INC_STATS(sock_net(sk), LINUX_MIB_TCPMD5FAILURE);
		net_info_ratelimited("MD5 Hash failed for (%pI4, %d)->(%pI4, %d)%s\n",
				     &iph->saddr, ntohs(th->source),
				     &iph->daddr, ntohs(th->dest),
				     genhash ? " tcp_v4_calc_md5_hash failed"
				     : "");
		return true;
	}
	return false;
#endif
	return false;
}