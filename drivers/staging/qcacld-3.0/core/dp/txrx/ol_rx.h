/*
 * Copyright (c) 2011, 2014-2018 The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _OL_RX__H_
#define _OL_RX__H_

#include <qdf_nbuf.h>           /* qdf_nbuf_t */
#include <ol_htt_api.h>         /* htt_pdev_handle */
#include <cdp_txrx_cmn.h>       /* ol_txrx_vdev_t */

void
ol_rx_deliver(struct ol_txrx_vdev_t *vdev,
	      struct ol_txrx_peer_t *peer, unsigned int tid,
	      qdf_nbuf_t head_msdu);

void
ol_rx_discard(struct ol_txrx_vdev_t *vdev,
	      struct ol_txrx_peer_t *peer, unsigned int tid,
	      qdf_nbuf_t head_msdu);

void ol_rx_frames_free(htt_pdev_handle htt_pdev, qdf_nbuf_t frames);

void ol_rx_peer_init(struct ol_txrx_pdev_t *pdev, struct ol_txrx_peer_t *peer);

void
ol_rx_peer_cleanup(struct ol_txrx_vdev_t *vdev, struct ol_txrx_peer_t *peer);

#ifdef WDI_EVENT_ENABLE
void ol_rx_send_pktlog_event(struct ol_txrx_pdev_t *pdev,
			     struct ol_txrx_peer_t *peer, qdf_nbuf_t msdu,
			     uint8_t pktlog_bit);
#else
static inline
void ol_rx_send_pktlog_event(struct ol_txrx_pdev_t *pdev,
			     struct ol_txrx_peer_t *peer, qdf_nbuf_t msdu,
			     uint8_t pktlog_bit)
{
}
#endif


void
ol_rx_in_order_deliver(struct ol_txrx_vdev_t *vdev,
		       struct ol_txrx_peer_t *peer,
		       unsigned int tid, qdf_nbuf_t head_msdu);

void ol_rx_log_packet(htt_pdev_handle htt_pdev,
		 uint8_t peer_id, qdf_nbuf_t msdu);
void
ol_rx_offload_paddr_deliver_ind_handler(htt_pdev_handle htt_pdev,
					uint32_t msdu_count,
					uint32_t *msg_word);
void ol_rx_update_histogram_stats(uint32_t msdu_count,
		uint8_t frag_ind, uint8_t offload_ind);

void
ol_rx_mic_error_handler(
	ol_txrx_pdev_handle pdev,
	u_int8_t tid,
	u_int16_t peer_id,
	void *msdu_desc,
	qdf_nbuf_t msdu);

void ol_rx_timestamp(struct cdp_cfg *cfg_pdev, void *rx_desc, qdf_nbuf_t msdu);

#endif /* _OL_RX__H_ */
