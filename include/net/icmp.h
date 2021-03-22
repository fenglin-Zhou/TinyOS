#ifndef __TINYOS__NET__ICMP_H
#define __TINYOS__NET__ICMP_H

#include <common/types.h>
#include <net/ipv4.h>
#include <net/etherframe.h>
#include <net/arp.h>

namespace tinyos
{
    namespace net
    {

        struct InternetControlMessageProtocolMessage
        {
            common::uint8_t type;
            common::uint8_t code;

            common::uint16_t checksum;
            common::uint32_t data; 
        } __attribute__((packed));

        class InternetControlMessageProtocol : InternetProtocolHandler
        {
        public:
            InternetControlMessageProtocol(InternetProtocolProvider* backend);
            ~InternetControlMessageProtocol();

            virtual bool OnInternetProtocolReceived(common::uint32_t srcIP_BE, common::uint32_t dstIP_BE,
                                            common::uint8_t* internetprotocolPayload, common::uint32_t size);

            void RequestEchoReply(common::uint32_t ip_be);
        };
    }
}

#endif