#pragma once

#include "envoy/network/connection_handler.h"

#include "common/protobuf/protobuf.h"

namespace Envoy {
namespace Server {

/**
 * Interface to create udp listener according to
 * envoy::api::v2::listener::UdpListenerConfig.udp_listener_name.
 */
class ActiveUdpListenerConfigFactory {
public:
  virtual ~ActiveUdpListenerConfigFactory() = default;

  virtual ProtobufTypes::MessagePtr createEmptyConfigProto() PURE;

  /**
   * Create an ActiveUdpListenerFactory object according to given message.
   */
  virtual Network::ActiveUdpListenerFactoryPtr
  createActiveUdpListenerFactory(const Protobuf::Message& message) PURE;

  /**
   * Used to identify which udp listener to create: quic or raw udp.
   */
  virtual std::string name() PURE;

  /**
   * @return std::string the identifying category name for objects
   * created by this factory. Used for automatic registration with
   * FactoryCategoryRegistry.
   */
  static std::string category() { return "udp_listeners"; }
};

} // namespace Server
} // namespace Envoy
