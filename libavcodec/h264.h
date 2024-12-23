/*
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * H.264 common definitions
 */

#ifndef AVCODEC_H264_H
#define AVCODEC_H264_H

#define QP_MAX_NUM (51 + 6*6)           // The maximum supported qp

/*
 * Table 7-1 – NAL unit type codes, syntax element categories, and NAL unit type classes in
 * T-REC-H.264-201704
 */
enum {
    H264_NAL_UNSPECIFIED     = 0,
    H264_NAL_SLICE           = 1, //Coded slice of a non-IDR picture slice_layer_without_partitioning_rbsp( )
    H264_NAL_DPA             = 2, //coded slice data partition a
    H264_NAL_DPB             = 3,// coded slice data partition b
    H264_NAL_DPC             = 4,// coded slice data partition c
    H264_NAL_IDR_SLICE       = 5, // coded slice of idr picture
    H264_NAL_SEI             = 6, // supplemental enhanced information sei
    H264_NAL_SPS             = 7, // sequence parameter set
    H264_NAL_PPS             = 8, //picture parameter set
    H264_NAL_AUD             = 9,//access unit delimiter
    H264_NAL_END_SEQUENCE    = 10,//end of sequence
    H264_NAL_END_STREAM      = 11,//end of stream
    H264_NAL_FILLER_DATA     = 12,//filler data
    H264_NAL_SPS_EXT         = 13,//sequence parameter set extension
    H264_NAL_PREFIX          = 14,//prefix nal unit
    H264_NAL_SUB_SPS         = 15,//subset sequence parameter set
    H264_NAL_DPS             = 16,//?
    H264_NAL_RESERVED17      = 17,//?
    H264_NAL_RESERVED18      = 18,//?
    H264_NAL_AUXILIARY_SLICE = 19,//coded slice of an auxiliary coded picture without partitioning
    H264_NAL_EXTEN_SLICE     = 20,//coded slice extension
    H264_NAL_DEPTH_EXTEN_SLICE = 21,//?
    H264_NAL_RESERVED22      = 22,//?
    H264_NAL_RESERVED23      = 23,//?
    H264_NAL_UNSPECIFIED24   = 24,//?
    H264_NAL_UNSPECIFIED25   = 25,//?
    H264_NAL_UNSPECIFIED26   = 26,//?
    H264_NAL_UNSPECIFIED27   = 27,//?
    H264_NAL_UNSPECIFIED28   = 28,//?
    H264_NAL_UNSPECIFIED29   = 29,//?
    H264_NAL_UNSPECIFIED30   = 30,//?
    H264_NAL_UNSPECIFIED31   = 31,//?
};


enum {
    // 7.4.2.1.1: seq_parameter_set_id is in [0, 31].
    H264_MAX_SPS_COUNT = 32,
    // 7.4.2.2: pic_parameter_set_id is in [0, 255].
    H264_MAX_PPS_COUNT = 256,

    // A.3: MaxDpbFrames is bounded above by 16.
    H264_MAX_DPB_FRAMES = 16,
    // 7.4.2.1.1: max_num_ref_frames is in [0, MaxDpbFrames], and
    // each reference frame can have two fields.
    H264_MAX_REFS       = 2 * H264_MAX_DPB_FRAMES,

    // 7.4.3.1: modification_of_pic_nums_idc is not equal to 3 at most
    // num_ref_idx_lN_active_minus1 + 1 times (that is, once for each
    // possible reference), then equal to 3 once.
    H264_MAX_RPLM_COUNT = H264_MAX_REFS + 1,

    // 7.4.3.3: in the worst case, we begin with a full short-term
    // reference picture list.  Each picture in turn is moved to the
    // long-term list (type 3) and then discarded from there (type 2).
    // Then, we set the length of the long-term list (type 4), mark
    // the current picture as long-term (type 6) and terminate the
    // process (type 0).
    H264_MAX_MMCO_COUNT = H264_MAX_REFS * 2 + 3,

    // A.2.1, A.2.3: profiles supporting FMO constrain
    // num_slice_groups_minus1 to be in [0, 7].
    H264_MAX_SLICE_GROUPS = 8,

    // E.2.2: cpb_cnt_minus1 is in [0, 31].
    H264_MAX_CPB_CNT = 32,

    // A.3: in table A-1 the highest level allows a MaxFS of 139264.
    H264_MAX_MB_PIC_SIZE = 139264,
    // A.3.1, A.3.2: PicWidthInMbs and PicHeightInMbs are constrained
    // to be not greater than sqrt(MaxFS * 8).  Hence height/width are
    // bounded above by sqrt(139264 * 8) = 1055.5 macroblocks.
    H264_MAX_MB_WIDTH    = 1055,
    H264_MAX_MB_HEIGHT   = 1055,
    H264_MAX_WIDTH       = H264_MAX_MB_WIDTH  * 16,
    H264_MAX_HEIGHT      = H264_MAX_MB_HEIGHT * 16,
};


#endif /* AVCODEC_H264_H */
