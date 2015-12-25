/*
 * author: Darren Bounds <dbounds@intrusense.com>
 * copyright: Copyright (C) 2002 by Darren Bounds
 * license: This software is under GPL version 2 of license
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * packit official page at http://packit.sourceforge.net
 */

#ifndef __PACKIT_H
#define __PACKIT_H

#ifndef __HAVE_CONFIG_H
#define __HAVE_CONFIG_H
#include "config.h"
#endif

#include <libnet.h>
#include <pcap.h>
#include <sys/types.h>
#include <net/bpf.h>
#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#define ARP_H            		0x1c    /* ARP header:          28 bytes */
#define DNS_H                 		0xc     /* DNS header base:     12 bytes */
#define ETH_H             		0xe     /* Etherner header:     14 bytes */
#define ICMPV4_H          		0x4     /* ICMP header base:     4 bytes */
#define ICMPV6_H           		0x08    /* ICMP6 header base:    8 bytes */
#define ICMPV4_ECHO_H       		0x8     /* ICMP_ECHO header:     8 bytes */
#define ICMPV4_MASK_H       		0xc     /* ICMP_MASK header:    12 bytes */
#define ICMPV4_UNREACH_H   		0x8     /* ICMP_UNREACH header:  8 bytes */
#define ICMPV4_TIMXCEED_H    		0x8     /* ICMP_TIMXCEED header: 8 bytes */
#define ICMPV4_REDIRECT_H    		0x8     /* ICMP_REDIRECT header: 8 bytes */
#define ICMPV4_TSTAMP_H      		0x14    /* ICMP_TIMESTAMP headr:20 bytes */
#define IPV4_H               		0x14    /* IP header:           20 bytes */
#define IPV6_H               		0x28    /* IPv6 header:         40 bytes */
#define TCP_H                		0x14    /* TCP header:          20 bytes */
#define UDP_H                		0x8     /* UDP header:           8 bytes */

#define ICMP_ECHOREPLY         		0       /* echo reply */
#define ICMP_UNREACH           		3       /* dest unreachable, codes: */
#define ICMP_SOURCEQUENCH      		4       /* packet lost, slow down */
#define ICMP_ECHO			8	/* echo request */
#define ICMP_ROUTERADVERT      		9       /* router advertisement */
#define ICMP_ROUTERSOLICIT     		10      /* router solicitation */
#define ICMP_TIMXCEED         		11      /* time exceeded, code: */
#define ICMP_PARAMPROB         		12      /* ip header bad */
#define ICMP_TSTAMP            		13      /* timestamp request */
#define ICMP_TSTAMPREPLY       		14      /* timestamp reply */
#define ICMP_IREQ              		15      /* information request */
#define ICMP_IREQREPLY         		16      /* information reply */
#define ICMP_MASKREQ           		17      /* address mask request */
#define ICMP_MASKREPLY         		18      /* address mask reply */
#define ICMP_TRACEROUTE			30	/* some misc traceroute type */

/* UNREACH codes */
#define ICMP_UNREACH_NET                0       /* bad net */
#define ICMP_UNREACH_HOST               1       /* bad host */
#define ICMP_UNREACH_PROTOCOL           2       /* bad protocol */
#define ICMP_UNREACH_PORT               3       /* bad port */
#define ICMP_UNREACH_NEEDFRAG           4       /* IP_DF caused drop */
#define ICMP_UNREACH_SRCFAIL            5       /* src route failed */
#define ICMP_UNREACH_NET_UNKNOWN        6       /* unknown net */
#define ICMP_UNREACH_HOST_UNKNOWN       7       /* unknown host */
#define ICMP_UNREACH_ISOLATED           8       /* src host isolated */
#define ICMP_UNREACH_NET_PROHIB         9       /* net denied */
#define ICMP_UNREACH_HOST_PROHIB        10      /* host denied */
#define ICMP_UNREACH_TOSNET             11      /* bad tos for net */
#define ICMP_UNREACH_TOSHOST            12      /* bad tos for host */
#define ICMP_UNREACH_FILTER_PROHIB      13      /* admin prohib */
#define ICMP_UNREACH_HOST_PRECEDENCE    14      /* host prec vio. */
#define ICMP_UNREACH_PRECEDENCE_CUTOFF  15      /* prec cutoff */
/* REDIRECT codes */
#define ICMP_REDIRECT_NET       	0       /* for network */
#define ICMP_REDIRECT_HOST      	1       /* for host */
#define ICMP_REDIRECT_TOSNET    	2       /* for tos and net */
#define ICMP_REDIRECT_TOSHOST   	3       /* for tos and host */
/* TIMEXCEED codes */
#define ICMP_TIMXCEED_INTRANS   	0       /* ttl==0 in transit */
#define ICMP_TIMXCEED_REASS     	1       /* ttl==0 in reass */
/* PARAMPROB code */
#define ICMP_PARAMPROB_OPTABSENT 	1       /* req. opt. absent */

#define ETHERTYPE_IP        		0x0800  /* internet protocol */
#define ETHERTYPE_ARP       		0x0806  /* addr. resolution protocol */
#define ETHERTYPE_REVARP    		0x8035  /* reverse addr. resolution protocol */

#define OPT_MAXLEN          		32

#define M_INJECT            		1
#define M_INJECT_RESPONSE   		2
#define M_CAPTURE           		10 
#define M_CAPTURE_RESET     		11 

#define P_INT16            		0x7FFF 
#define P_UINT16            		0xFFFF 
#define P_INT32             		0x7FFFFFFF 
#define P_UINT32            		0xFFFFFFFF 

pcap_t *pkt;
u_int8_t *filter;
u_int8_t *device;
u_int16_t hdr_len;
u_int32_t cnt;
u_int32_t inj_cnt;
u_int32_t cap_cnt;
u_int16_t p_mode;
unsigned short verbose;

void print_usage();
void parse_capture_options(int argc, char *argv[]);
void parse_inject_options(int argc, char *argv[]);

#endif /* __PACKIT_H */