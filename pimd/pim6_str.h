
#ifndef PIM6_STR_H
#define PIM6_STR_H

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <prefix.h>

#define PIM_ADDR in6_addr
#define PIM_SG_PFX(sg) (sg).src.ipaddr_v6
#define PIM_IPADDR_PFX(ip) (ip).ipaddr_v6
#define PIM_UN_PFX(p) (p).u.prefix6
#define pim_inet_dump prefix_mcast_inet6_dump

/*
 * Longest possible length of a (S,G) string is 36 bytes
 * 123.123.123.123 = 16 * 2
 * (,) = 3
 * NULL Character at end = 1
 * (123.123.123.123,123,123,123,123)
 */
#define PIM_SG_LEN PREFIX_SG_STR_LEN
#define pim_str_sg_set prefix_sg2str

static inline void pim_addr_copy(struct PIM_ADDR *dest, struct PIM_ADDR *source)
{
	IPV6_ADDR_COPY(dest, source);
}

static inline int pim_is_addr_any(struct PIM_ADDR addr)
{
	return IPV6_ADDR_SAME(&addr, &in6addr_any);
}

static inline int pim_addr_ntoh_and_compare(struct PIM_ADDR addr1,
					    struct PIM_ADDR addr2)
{
	return IPV6_ADDR_CMP(&addr1, &addr2);
}

static inline int pim_addr_compare(struct PIM_ADDR addr1, struct PIM_ADDR addr2)
{
	return IPV6_ADDR_CMP(&addr1, &addr2);
}

static inline int pim_addr_is_same(struct PIM_ADDR addr1, struct PIM_ADDR addr2)
{
	return IPV6_ADDR_SAME(&addr1, &addr2);
}

void pim_addr_dump(const char *onfail, struct prefix *p, char *buf,
		   int buf_size);
void pim_inet4_dump(const char *onfail, struct in_addr addr, char *buf,
		    int buf_size);
char *pim_str_sg_dump(const struct prefix_sg *sg);

#endif
