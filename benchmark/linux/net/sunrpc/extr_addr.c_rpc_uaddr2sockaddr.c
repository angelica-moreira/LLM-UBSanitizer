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
struct sockaddr_in6 {void* sin6_port; } ;
struct sockaddr_in {void* sin_port; } ;
struct sockaddr {int sa_family; } ;
struct net {int dummy; } ;

/* Variables and functions */
#define  AF_INET 129 
#define  AF_INET6 128 
 int RPCBIND_MAXUADDRLEN ; 
 void* htons (unsigned short) ; 
 scalar_t__ kstrtou8 (char*,int,int*) ; 
 int /*<<< orphan*/  memcpy (char*,char const*,size_t const) ; 
 scalar_t__ rpc_pton (struct net*,char*,int /*<<< orphan*/ ,struct sockaddr*,size_t const) ; 
 int /*<<< orphan*/  strlen (char*) ; 
 char* strrchr (char*,char) ; 
 scalar_t__ unlikely (int) ; 

size_t rpc_uaddr2sockaddr(struct net *net, const char *uaddr,
			  const size_t uaddr_len, struct sockaddr *sap,
			  const size_t salen)
{
	char *c, buf[RPCBIND_MAXUADDRLEN + sizeof('\0')];
	u8 portlo, porthi;
	unsigned short port;

	if (uaddr_len > RPCBIND_MAXUADDRLEN)
		return 0;

	memcpy(buf, uaddr, uaddr_len);

	buf[uaddr_len] = '\0';
	c = strrchr(buf, '.');
	if (unlikely(c == NULL))
		return 0;
	if (unlikely(kstrtou8(c + 1, 10, &portlo) != 0))
		return 0;

	*c = '\0';
	c = strrchr(buf, '.');
	if (unlikely(c == NULL))
		return 0;
	if (unlikely(kstrtou8(c + 1, 10, &porthi) != 0))
		return 0;

	port = (unsigned short)((porthi << 8) | portlo);

	*c = '\0';
	if (rpc_pton(net, buf, strlen(buf), sap, salen) == 0)
		return 0;

	switch (sap->sa_family) {
	case AF_INET:
		((struct sockaddr_in *)sap)->sin_port = htons(port);
		return sizeof(struct sockaddr_in);
	case AF_INET6:
		((struct sockaddr_in6 *)sap)->sin6_port = htons(port);
		return sizeof(struct sockaddr_in6);
	}

	return 0;
}