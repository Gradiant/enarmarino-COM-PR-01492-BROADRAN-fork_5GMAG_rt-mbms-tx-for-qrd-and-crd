/**
 *
 * \section COPYRIGHT
 *
 * Copyright 2013-2021 Software Radio Systems Limited
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the distribution.
 *
 */
#ifndef SRSRAN_GNB_RRC_NR_INTERFACES_H
#define SRSRAN_GNB_RRC_NR_INTERFACES_H

#include "srsran/asn1/ngap.h"
#include "srsran/common/byte_buffer.h"
namespace srsenb {

class rrc_interface_ngap_nr
{
public:
  virtual int  ue_set_security_cfg_key(uint16_t rnti, const asn1::fixed_bitstring<256, false, true>& key)    = 0;
  virtual int  ue_set_bitrates(uint16_t rnti, const asn1::ngap_nr::ue_aggregate_maximum_bit_rate_s& rates)   = 0;
  virtual int  ue_set_security_cfg_capabilities(uint16_t rnti, const asn1::ngap_nr::ue_security_cap_s& caps) = 0;
  virtual int  start_security_mode_procedure(uint16_t rnti)                                                  = 0;
  virtual void write_dl_info(uint16_t rnti, srsran::unique_byte_buffer_t sdu)                                = 0;
};

} // namespace srsenb

#endif // SRSRAN_GNB_RRC_NR_INTERFACES_H