/* -*- c++ -*- */

#define GFDM_API
#define DIGITAL_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "gfdm_swig_doc.i"

%{
#include "gfdm/transmitter_cvc.h"
#include "gfdm/framer_cc.h"
#include "gfdm/modulator_cc.h"
#include "gfdm/receiver_cc.h"
#include "gfdm/advanced_receiver_cc.h"
#include "gnuradio/digital/constellation.h"
%}

%include "gfdm/transmitter_cvc.h"
%include "gfdm/framer_cc.h"
%include "gfdm/modulator_cc.h"
%include "gfdm/receiver_cc.h"
%include "gfdm/advanced_receiver_cc.h"
%include "gnuradio/digital/constellation.h"

GR_SWIG_BLOCK_MAGIC2(gfdm, transmitter_cvc);
GR_SWIG_BLOCK_MAGIC2(gfdm, framer_cc);
GR_SWIG_BLOCK_MAGIC2(gfdm, modulator_cc);
GR_SWIG_BLOCK_MAGIC2(gfdm, receiver_cc);
GR_SWIG_BLOCK_MAGIC2(gfdm, advanced_receiver_cc);

%include "gnuradio/swig/constellation.i"
