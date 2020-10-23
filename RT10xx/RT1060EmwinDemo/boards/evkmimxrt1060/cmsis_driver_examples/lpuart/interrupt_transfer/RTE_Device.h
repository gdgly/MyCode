/*
 * Copyright 2018 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __RTE_DEVICE_H
#define __RTE_DEVICE_H

/* Driver name mapping. */
#define RTE_USART1        1
#define RTE_USART1_DMA_EN 0
#define RTE_USART2        0
#define RTE_USART2_DMA_EN 0
#define RTE_USART3        0
#define RTE_USART3_DMA_EN 0
#define RTE_USART4        0
#define RTE_USART4_DMA_EN 0
#define RTE_USART5        0
#define RTE_USART5_DMA_EN 0
#define RTE_USART6        0
#define RTE_USART6_DMA_EN 0
#define RTE_USART7        0
#define RTE_USART7_DMA_EN 0
#define RTE_USART8        1
#define RTE_USART8_DMA_EN 0

/* UART configuration. */
#define RTE_USART1_DMA_TX_CH          0
#define RTE_USART1_DMA_TX_PERI_SEL    (uint8_t) kDmaRequestMuxLPUART1Tx
#define RTE_USART1_DMA_TX_DMAMUX_BASE DMAMUX
#define RTE_USART1_DMA_TX_DMA_BASE    DMA0
#define RTE_USART1_DMA_RX_CH          1
#define RTE_USART1_DMA_RX_PERI_SEL    (uint8_t) kDmaRequestMuxLPUART1Rx
#define RTE_USART1_DMA_RX_DMAMUX_BASE DMAMUX
#define RTE_USART1_DMA_RX_DMA_BASE    DMA0

#define RTE_USART2_DMA_TX_CH          0
#define RTE_USART2_DMA_TX_PERI_SEL    (uint8_t) kDmaRequestMuxLPUART2Tx
#define RTE_USART2_DMA_TX_DMAMUX_BASE DMAMUX
#define RTE_USART2_DMA_TX_DMA_BASE    DMA0
#define RTE_USART2_DMA_RX_CH          1
#define RTE_USART2_DMA_RX_PERI_SEL    (uint8_t) kDmaRequestMuxLPUART2Rx
#define RTE_USART2_DMA_RX_DMAMUX_BASE DMAMUX
#define RTE_USART2_DMA_RX_DMA_BASE    DMA0

#define RTE_USART3_DMA_TX_CH          0
#define RTE_USART3_DMA_TX_PERI_SEL    (uint8_t) kDmaRequestMuxLPUART3Tx
#define RTE_USART3_DMA_TX_DMAMUX_BASE DMAMUX
#define RTE_USART3_DMA_TX_DMA_BASE    DMA0
#define RTE_USART3_DMA_RX_CH          1
#define RTE_USART3_DMA_RX_PERI_SEL    (uint8_t) kDmaRequestMuxLPUART3Rx
#define RTE_USART3_DMA_RX_DMAMUX_BASE DMAMUX
#define RTE_USART3_DMA_RX_DMA_BASE    DMA0

#define RTE_USART4_DMA_TX_CH          0
#define RTE_USART4_DMA_TX_PERI_SEL    (uint8_t) kDmaRequestMuxLPUART4Tx
#define RTE_USART4_DMA_TX_DMAMUX_BASE DMAMUX
#define RTE_USART4_DMA_TX_DMA_BASE    DMA0
#define RTE_USART4_DMA_RX_CH          1
#define RTE_USART4_DMA_RX_PERI_SEL    (uint8_t) kDmaRequestMuxLPUART4Rx
#define RTE_USART4_DMA_RX_DMAMUX_BASE DMAMUX
#define RTE_USART4_DMA_RX_DMA_BASE    DMA0

#define RTE_USART5_DMA_TX_CH          0
#define RTE_USART5_DMA_TX_PERI_SEL    (uint8_t) kDmaRequestMuxLPUART5Tx
#define RTE_USART5_DMA_TX_DMAMUX_BASE DMAMUX
#define RTE_USART5_DMA_TX_DMA_BASE    DMA0
#define RTE_USART5_DMA_RX_CH          1
#define RTE_USART5_DMA_RX_PERI_SEL    (uint8_t) kDmaRequestMuxLPUART5Rx
#define RTE_USART5_DMA_RX_DMAMUX_BASE DMAMUX
#define RTE_USART5_DMA_RX_DMA_BASE    DMA0

#define RTE_USART6_DMA_TX_CH          0
#define RTE_USART6_DMA_TX_PERI_SEL    (uint8_t) kDmaRequestMuxLPUART6Tx
#define RTE_USART6_DMA_TX_DMAMUX_BASE DMAMUX
#define RTE_USART6_DMA_TX_DMA_BASE    DMA0
#define RTE_USART6_DMA_RX_CH          1
#define RTE_USART6_DMA_RX_PERI_SEL    (uint8_t) kDmaRequestMuxLPUART6Rx
#define RTE_USART6_DMA_RX_DMAMUX_BASE DMAMUX
#define RTE_USART6_DMA_RX_DMA_BASE    DMA0

#define RTE_USART7_DMA_TX_CH          0
#define RTE_USART7_DMA_TX_PERI_SEL    (uint8_t) kDmaRequestMuxLPUART7Tx
#define RTE_USART7_DMA_TX_DMAMUX_BASE DMAMUX
#define RTE_USART7_DMA_TX_DMA_BASE    DMA0
#define RTE_USART7_DMA_RX_CH          1
#define RTE_USART7_DMA_RX_PERI_SEL    (uint8_t) kDmaRequestMuxLPUART7Rx
#define RTE_USART7_DMA_RX_DMAMUX_BASE DMAMUX
#define RTE_USART7_DMA_RX_DMA_BASE    DMA0

#define RTE_USART8_DMA_TX_CH          0
#define RTE_USART8_DMA_TX_PERI_SEL    (uint8_t) kDmaRequestMuxLPUART8Tx
#define RTE_USART8_DMA_TX_DMAMUX_BASE DMAMUX
#define RTE_USART8_DMA_TX_DMA_BASE    DMA0
#define RTE_USART8_DMA_RX_CH          1
#define RTE_USART8_DMA_RX_PERI_SEL    (uint8_t) kDmaRequestMuxLPUART8Rx
#define RTE_USART8_DMA_RX_DMAMUX_BASE DMAMUX
#define RTE_USART8_DMA_RX_DMA_BASE    DMA0

#endif /* __RTE_DEVICE_H */
