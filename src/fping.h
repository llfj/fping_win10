#ifndef _FPING_H
#define _FPING_H

#define __APPLE_USE_RFC_3542 1

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define	ICMP_MINLEN	8				/* abs minimum */
#define	ICMP_ECHOREPLY		0		/* echo reply */
#define	ICMP_ECHO		8		/* echo service */
#define	ICMP_UNREACH		3		/* dest unreachable, codes: */
#define	ICMP_SOURCEQUENCH	4		/* packet lost, slow down */
#define	ICMP_REDIRECT		5		/* shorter route, codes: */
#define	ICMP_TIMXCEED		11		/* time exceeded, code: */
#define	ICMP_PARAMPROB		12		/* ip header bad */



/* fping.c */
void crash_and_burn( char *message );
void errno_crash_and_burn( char *message );
int in_cksum( unsigned short *p, int n );
int random_data_flag;

/* socket.c */
int  open_ping_socket_ipv4();
void init_ping_buffer_ipv4(size_t ping_data_size);
void socket_set_src_addr_ipv4(int s, struct in_addr *src_addr);
int  socket_sendto_ping_ipv4(int s, struct sockaddr *saddr, socklen_t saddr_len, uint16_t icmp_seq, uint16_t icmp_id);
#ifdef IPV6
int  open_ping_socket_ipv6();
void init_ping_buffer_ipv6(size_t ping_data_size);
void socket_set_src_addr_ipv6(int s, struct in6_addr *src_addr);
int  socket_sendto_ping_ipv6(int s, struct sockaddr *saddr, socklen_t saddr_len, uint16_t icmp_seq, uint16_t icmp_id);
#endif

#endif
