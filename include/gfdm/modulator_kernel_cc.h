/* -*- c++ -*- */
/* 
 * Copyright 2016 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */


#ifndef INCLUDED_GFDM_MODULATOR_KERNEL_CC_H
#define INCLUDED_GFDM_MODULATOR_KERNEL_CC_H

#include <gfdm/api.h>

namespace gr {
  namespace gfdm {


    /*!
     * \brief modulate a GFDM block.
     *
     */
    class GFDM_API modulator_kernel_cc
    {
    public:
      typedef std::complex<float> gfdm_complex;
      typedef boost::shared_ptr<modulator_kernel_cc> sptr;

      modulator_kernel_cc(int n_timeslots, int n_subcarriers, int overlap, std::vector<gfdm_complex> frequency_taps);
      ~modulator_kernel_cc();
      void generic_work(gfdm_complex* p_out, const gfdm_complex* p_in);
      int block_size(){return d_n_subcarriers * d_n_timeslots;};
    private:
      int d_n_timeslots;
      int d_n_subcarriers;
      int d_overlap;
      gfdm_complex* d_filter_taps;

      gfdm_complex* d_sub_fft_in;
      gfdm_complex* d_sub_fft_out;
      void* d_sub_fft_plan;
      void subcarrier_fft(gfdm_complex* p_out, const gfdm_complex* p_in);
      void gfdm_fftshift(gfdm_complex* p_out, const gfdm_complex* p_in, const int size);
      gfdm_complex* d_fd_data;
      void upsample_and_filter(gfdm_complex* p_out, const gfdm_complex* p_in);
      gfdm_complex* d_upfilter;
      gfdm_complex* d_filtered;
      void combine_subcarriers(gfdm_complex* p_out, const gfdm_complex* p_in);
      gfdm_complex* d_fd_out;
      gfdm_complex* d_ifft_in;
      gfdm_complex* d_ifft_out;
      void* d_ifft_plan;

      // DEBUG function
      const void print_vector(const gfdm_complex* v, const int size);
    };

  } // namespace gfdm
} // namespace gr

#endif /* INCLUDED_GFDM_MODULATOR_KERNEL_CC_H */

